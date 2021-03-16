/* Creator: Michael Pasaye
 * Class: CSE13E Winter 2021
 * File: Agent.c
 * Lab: BattleBoats
 */

// Standard Libraries
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// CSE13E Libraries
#include "BOARD.h"
#include "Oled.h"

// BattleBoat Libraries
#include "Agent.h"
#include "Field.h"
#include "FieldOled.h"
#include "Negotiation.h"

// Define Block

// TypeDef Block

typedef enum {
    LOSS,
    WON
} GameState;

// Variable Block

static AgentState agentState;
static int turnCnt;
static char aStr[50], bStr[50], aHashStr[50];    // 50 should be enough to store all secrets and hash's
static Message message;
static NegotiationData a, aHash, b;
static NegotiationOutcome coinFlip;
static Field ownField, oppField;
static GuessData guessOut, guessRes;
static GameState gameState;
static FieldOledTurn whosTurn;
// Function Block

void AgentInit(void)
{
    agentState = AGENT_STATE_START; // Initializing the state machine to Start
    turnCnt = 0; // Initialize the turn counter to zero
    message.type = MESSAGE_NONE; // Initialize the message
    a = 0;
    b = 0;
    aHash = 0;
    whosTurn = FIELD_OLED_TURN_NONE;
}

Message AgentRun(BB_Event event)
{
    if (event.type == BB_EVENT_RESET_BUTTON) {
        AgentInit();
        OledClear(0);
        OledDrawString("START");
        OledDrawString("\n\nReady for a new game?");
        OledDrawString("\n\n\nPress BTN4 to Start");
        OledUpdate();
    }

    // Make sure mssage.type == MESSAGE_NONE so no weird stuff happens
    message.type = MESSAGE_NONE;
    
    printf("AGENT STATE: %d\n", agentState);
    printf("BB_EVENT: %d\n", event.type);
    
    switch (agentState) {
    case AGENT_STATE_START:
        printf("START STATE\n");
        if (event.type == BB_EVENT_START_BUTTON) {
            printf("START BUTTON\n");
            a = (NegotiationData) rand() & 0xFFFF;
            //printf("value of a: %d\n", a);
            aHash = NegotiationHash(a);
            //printf("value of aHash: %d\n", aHash);
            message.type = MESSAGE_CHA;
            message.param0 = aHash;
            FieldInit(&ownField, &oppField);
            FieldAIPlaceAllBoats(&ownField);
            agentState = AGENT_STATE_CHALLENGING;
        } else if (event.type == BB_EVENT_CHA_RECEIVED) {
            printf("CHA RECEIVED\n");
            b = (NegotiationData) rand() & 0xFFFF;
            aHash = event.param0;
            message.type = MESSAGE_ACC;
            message.param0 = b;
            FieldInit(&ownField, &oppField);
            FieldAIPlaceAllBoats(&ownField);
            agentState = AGENT_STATE_ACCEPTING;
        }

        break;
    case AGENT_STATE_CHALLENGING:
        printf("CHALLENGING STATE\n");
        OledClear(0);
        if (event.type == BB_EVENT_ACC_RECEIVED) {
            printf("ACC RECEIVED\n");
            b = event.param0; // Obtaining the secret sent by the opponent 
            message.type = MESSAGE_REV; // Sending our secret to our opponent
            message.param0 = a;
            coinFlip = NegotiateCoinFlip(a, b);
            //coinFlip = TAILS;
            if (coinFlip == HEADS) {
                printf("HEADS\n");
                agentState = AGENT_STATE_WAITING_TO_SEND;
            } else if (coinFlip == TAILS) {
                printf("TAILS\n");
                agentState = AGENT_STATE_DEFENDING;
            }
        }
        sprintf(aStr, "\n %d = A", (int) a);
        sprintf(aHashStr, "\n\n %d = hash_a", (int) aHash);
        OledDrawString("CHALLENGING");
        OledDrawString(aStr);
        OledDrawString(aHashStr);
        OledUpdate();
        break;
    case AGENT_STATE_ACCEPTING:
        printf("ACCEPTING STATE\n");
        OledClear(0);
        if (event.type == BB_EVENT_REV_RECEIVED) {
            printf("REV RECEIVED\n");
            a = event.param0;
            coinFlip = NegotiateCoinFlip(a, b);
            if (!NegotiationVerify(a, aHash)) { //Cheating Detected
                agentState = AGENT_STATE_END_SCREEN;
            }

            if (coinFlip == HEADS) {
                agentState = AGENT_STATE_DEFENDING;
            } else if (coinFlip == TAILS) {
                guessOut = FieldAIDecideGuess(&oppField);
                message.type = MESSAGE_SHO;
                message.param0 = guessOut.row;
                message.param1 = guessOut.col;
                agentState = AGENT_STATE_ATTACKING;
            }
        }
        
        sprintf(bStr, "\n %d = B", (int) b);
        sprintf(aHashStr, "\n\n %d = hash_a", (int) aHash);
        OledDrawString("ACCEPTING");
        OledDrawString(aHashStr);
        OledDrawString(bStr);
        OledUpdate();
        
        break;
    case AGENT_STATE_WAITING_TO_SEND:
        printf("WAITING TO SEND STATE\n");
        OledClear(0);
        if (event.type == BB_EVENT_MESSAGE_SENT) {
            printf("MESSAGE SENT\n");
            whosTurn = FIELD_OLED_TURN_MINE;
            turnCnt++;
            guessOut = FieldAIDecideGuess(&oppField);
            message.type = MESSAGE_SHO;
            message.param0 = guessOut.row;
            message.param1 = guessOut.col;
            agentState = AGENT_STATE_ATTACKING;
        }
        
        FieldOledDrawScreen(&ownField, &oppField, whosTurn, turnCnt);
        break;
    case AGENT_STATE_ATTACKING:
        printf("ATTACKING STATE\n");
        OledClear(0);
        if (event.type == BB_EVENT_RES_RECEIVED) {
            printf("RES RECEIVED\n");
            guessRes.row = event.param0;
            guessRes.col = event.param1;
            guessRes.result = event.param2;
            FieldUpdateKnowledge(&oppField, &guessRes);
            // Checks if all the boats are destroyed
            if (!(oppField.hugeBoatLives) && !(oppField.largeBoatLives) && !(oppField.mediumBoatLives) && !(oppField.smallBoatLives)) {
                // The game has been won
                agentState = AGENT_STATE_END_SCREEN;
                gameState = WON;
            } else {
                agentState = AGENT_STATE_DEFENDING;
            }
        }
        
        FieldOledDrawScreen(&ownField, &oppField, whosTurn, turnCnt);
        break;
    case AGENT_STATE_DEFENDING:
        printf("DEFENDING STATE\n");
        if (event.type == BB_EVENT_SHO_RECEIVED) {
            printf("SHO RECEIVED\n");
            whosTurn = FIELD_OLED_TURN_THEIRS;
            guessRes.row = event.param0;
            guessRes.col = event.param1;
            FieldRegisterEnemyAttack(&ownField, &guessRes);
            message.type = MESSAGE_RES;
            message.param0 = guessRes.row;
            message.param1 = guessRes.col;
            message.param2 = guessRes.result;

            if (!(ownField.hugeBoatLives) && !(ownField.largeBoatLives) && !(ownField.mediumBoatLives) && !(ownField.smallBoatLives)) {
                // The game has been lost
                agentState = AGENT_STATE_END_SCREEN;
                gameState = LOSS;
            } else {
                agentState = AGENT_STATE_WAITING_TO_SEND;
            }
        }
        
        FieldOledDrawScreen(&ownField, &oppField, whosTurn, turnCnt);
        break;
    case AGENT_STATE_END_SCREEN:
        printf("END SCREEN STATE\n");
        OledClear(0);
        if (gameState == WON) {
            OledDrawString("YOU'VE WON\n");
        } else if (gameState == LOSS) {
            OledDrawString("YOU'VE LOST\n");
        } else {
            OledDrawString("FATAL ERROR\n");
        }
        OledUpdate();
        break;
    case AGENT_STATE_SETUP_BOATS:
        // Necessary for a human agent (extra credit)
        break;
    }



    return message;
}

AgentState AgentGetState(void)
{
    return agentState;
}

void AgentSetState(AgentState newState)
{
    agentState = newState;
}
