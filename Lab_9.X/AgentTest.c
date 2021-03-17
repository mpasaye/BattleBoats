// Standard libraries
#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include "Agent.h"
#include "BOARD.h"
#include "Field.h"
#include "FieldOled.h"
#include "Negotiation.h"
#include "BattleBoats.h"
#include "Message.h"

<<<<<<< HEAD
int main()
{
=======
int main() {
>>>>>>> f312fb4302ef29c47205c81f85e53239e8816056
    BOARD_Init();
    printf("Welcome to NABARRAZ'S AgentTest.  Compiled on %s %s\n", __DATE__, __TIME__);
    /**************************************************************************/
    //TESTING AGENT INIT
    {
        AgentInit();
        int testspassed = 0, totaltests = 2;
        
        printf("Testing AgentInit:\n");
        AgentState return_val = AgentGetState();
        if (return_val == AGENT_STATE_START) {
            testspassed++;
            printf("TEST 1 PASSED\n");
        } else {
            printf("TEST 1 FAILED\n");
        }
        AgentSetState(AGENT_STATE_CHALLENGING);
        AgentInit();
        return_val = AgentGetState();
        if (return_val == AGENT_STATE_START) {
            testspassed++;
            printf("TEST 2 PASSED\n");
        } else {
            printf("TEST 2 FAILED\n");
        }
        printf("%d/%d TESTS PASSED\n", testspassed, totaltests);
    }

    /*******************************************************************************/
    //TESTING AGENT GET STATE
    {
        AgentInit();
        printf("Testing AgentGetState:\n");
        int testspassed = 0, totaltests = 3;
        AgentState newState = AGENT_STATE_CHALLENGING;
        AgentSetState(newState);
        AgentState return_val = AgentGetState();
        if (return_val == newState) {
            testspassed++;
            printf("TEST 1 PASSED\n");
        } else {
            printf("TEST 1 FAILED\n");
        }

        newState = AGENT_STATE_WAITING_TO_SEND;
        AgentSetState(newState);
        return_val = AgentGetState();
        if (return_val == newState) {
            testspassed++;
            printf("TEST 2 PASSED\n");
        } else {
            printf("TEST 2 FAILED\n");
        }

        newState = BB_EVENT_ACC_RECEIVED;
        AgentSetState(newState);
        return_val = AgentGetState();
        if (return_val == newState) {
            testspassed++;
            printf("TEST 3 PASSED\n");
        } else {
            printf("TEST 3 FAILED\n");
        }
        printf("%d/%d TESTS PASSED\n", testspassed, totaltests);
    }
    /**************************************************************************/
    //TESTING AGENTSETSTATE
    {
        printf("Testing AgentSetState:\n");
        int testspassed = 0, totaltests = 3;
        AgentState newState = AGENT_STATE_ATTACKING;
        AgentSetState(newState);
        AgentState return_val = AgentGetState();
        if (return_val == newState) {
            testspassed++;
            printf("TEST 1 PASSED\n");
        } else {
            printf("TEST 1 FAILED\n");
        }

        newState = AGENT_STATE_ACCEPTING;
        AgentSetState(newState);
        return_val = AgentGetState();
        if (return_val == newState) {
            testspassed++;
            printf("TEST 2 PASSED\n");
        } else {
            printf("TEST 2 FAILED\n");
        }

        newState = AGENT_STATE_END_SCREEN;
        AgentSetState(newState);
        return_val = AgentGetState();
        if (return_val == newState) {
            testspassed++;
            printf("TEST 3 PASSED\n");
        } else {
            printf("TEST 3 FAILED\n");
        }
        printf("%d/%d TESTS PASSED\n", testspassed, totaltests);
    }

    /**
     * AgentRun evolves the Agent state machine in response to an event.
     * 
     * @param  The most recently detected event
     * @return Message, a Message struct to send to the opponent. 
     * 
     * If the returned Message struct is a valid message
     * (that is, not of type MESSAGE_NONE), then it will be
     * passed to the transmission module and sent via UART.
     * This is handled at the top level! AgentRun is ONLY responsible 
     * for generating the Message struct, not for encoding or sending it.
     */
    //Message AgentRun(BB_Event event);
    {
        AgentInit();
        int testspassed = 0, totaltests = 3;
        printf("Testing AgentRun:\n");
<<<<<<< HEAD
        BB_Event event = {BB_EVENT_START_BUTTON};
        Message message = AgentRun(event);
        
        if (message.type == MESSAGE_CHA) {
            testspassed++;
=======
        BB_Event event1 = {BB_EVENT_START_BUTTON, 2};

        Message message1 = AgentRun(event1);

        if (message1.type == MESSAGE_ACC) {
>>>>>>> f312fb4302ef29c47205c81f85e53239e8816056
            printf("TEST 1 PASSED\n");
        } else {
            printf("TEST 1 FAILED\n");
        }
        
        AgentInit();
        event.type = BB_EVENT_ACC_RECEIVED;
        event.param0 = 3;
        message = AgentRun(event);
        //AgentSetState(AGENT_STATE_START);
        //message = AgentRun(event);
        if (message.type == MESSAGE_CHA) {
            testspassed++;
            printf("TEST 2 PASSED\n");
        } else {
            printf("TEST 2 FAILED\n");
        }
        
        AgentInit();
        event.type = BB_EVENT_CHA_RECEIVED;
        event.param0 = 3;
        message = AgentRun(event);
        
        if (message.type == MESSAGE_ACC) {
            testspassed++;
            printf("TEST 3 PASSED\n");
        } else {
            printf("TEST 3 FAILED\n");
        }
        printf("%d/%d TESTS PASSED\n", testspassed, totaltests);
    }
    return 0;
    BOARD_End();
}

