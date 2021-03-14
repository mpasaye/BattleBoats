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

// BattleBoat Libraries
#include "Agent.h"
#include "Field.h"
#include "Negotiation.h"

// Define Block

// TypeDef Block

// Variable Block

static AgentState agentState;
static int turnCnt;
static Message message;
static NegotiationData a, aHash, b;
static NegotiationOutcome coinFlip;
static Field ownField, oppField;
static GuessData guessOut;

// Function Block

void AgentInit(void)
{
    agentState = AGENT_STATE_START; // Initializing the state machine to Start
    turnCnt = 0; // Initialize the turn counter to zero
    message.type = MESSAGE_NONE; // Initialize the message
}

Message AgentRun(BB_Event event)
{
    if (event.type == BB_EVENT_RESET_BUTTON) {
        AgentInit();
    }

    switch (agentState) {
    case AGENT_STATE_START:
        if (event.type == BB_EVENT_START_BUTTON) {
            a = (NegotiationData) rand();
            //printf("value of a: %d\n", a);
            aHash = NegotiationHash(a);
            //printf("value of aHash: %d\n", aHash);
            message.type = MESSAGE_CHA;
            message.param0 = aHash;
            FieldInit(&ownField, &oppField);
            FieldAIPlaceAllBoats(&ownField);
            agentState = AGENT_STATE_CHALLENGING;
        } else if (event.type == BB_EVENT_CHA_RECEIVED) {
            b = (NegotiationData) rand();
            message.type = MESSAGE_ACC;
            message.param0 = b;
            FieldInit(&ownField, &oppField);
            FieldAIPlaceAllBoats(&ownField);
            agentState = AGENT_STATE_ACCEPTING;
        }
        
        break;
    case AGENT_STATE_CHALLENGING:
        if (event.type == BB_EVENT_ACC_RECEIVED) {
            b = message.param0; // Obtaining the secret sent by the opponent 
            message.type = MESSAGE_REV; // Sending our secret to our opponent
            message.param0 = a;
            coinFlip = NegotiateCoinFlip(a, b);
            if (coinFlip == HEADS) {
                agentState = AGENT_STATE_WAITING_TO_SEND;
            } else {
                agentState = AGENT_STATE_DEFENDING;
            }
        }
        break;
    case AGENT_STATE_ACCEPTING:
        if (event.type == BB_EVENT_REV_RECEIVED) {
            a = message.param0;
            coinFlip = NegotiateCoinFlip(a, b);
            if (!NegotiationVerify(a, aHash)) {
                agentState = AGENT_STATE_END_SCREEN;
            }
            
            if (coinFlip == HEADS) {
                agentState = AGENT_STATE_DEFENDING;
            } else {
                guessOut = FieldAIDecideGuess(&oppField);
                message.type = MESSAGE_SHO;
                message.param0 = guessOut.row;
                message.param1 = guessOut.col;
                agentState = AGENT_STATE_ATTACKING;
            }
        }
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
