// Standard libraries
#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include "Agent.h"
#include "BOARD.h"
#include "Field.h"
#include "FieldOled.h"
#include "Negotiation.h"

int main(){
    BOARD_Init();
    printf("Welcome to NABARRAZ'S AgentTest.  Compiled on %s %s\n", __DATE__, __TIME__);
    /**************************************************************************/
    //TESTING AGENT INIT
    {
        AgentInit();
        printf("Testing AgentInit:\n");
        AgentState return_val=AgentGetState();
        if (return_val==AGENT_STATE_START){
            printf("TEST 1 PASSED\n");
        }else{
            printf("TEST 1 FAILED\n");
        }
        AgentSetState(AGENT_STATE_CHALLENGING);
        AgentInit();
        return_val=AgentGetState();
        if (return_val==AGENT_STATE_START){
            printf("TEST 2 PASSED\n");
        }else{
            printf("TEST 2 FAILED\n");
        }
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
    AgentInit();
    printf("Testing AgentRun:\n");
    BB_Event event1={};
    event1.type=BB_EVENT_CHA_RECEIVED;
    event1.param0=2;
    //event1={BB_EVENT_CHA_RECEIVED, 2};
    printf("monkey\n");
    Message message1=AgentRun(event1);
    printf("hello\n");
    printf("printing messagetype: %d\n", message1.type);
    if (message1.type==MESSAGE_ACC){
        printf("TEST 1 PASSED\n");
    }else{
        printf("TEST 1 FAILED\n");
    }
    
/*******************************************************************************/
    //TESTING AGENT GET STATE
    printf("Testing AgentGetState:\n");
    int testspassed=0;
    AgentState newState= AGENT_STATE_CHALLENGING;
    AgentSetState(newState);
    return_val=AgentGetState();
    if (return_val==newState){
        testspassed++;
        printf("TEST 1 PASSED\n");
    }else{
        printf("TEST 1 FAILED\n");
    }
    
    newState= AGENT_STATE_WAITING_TO_SEND;
    AgentSetState(newState);
    return_val=AgentGetState();
    if (return_val==newState){
        testspassed++;
        printf("TEST 2 PASSED\n");
    }else{
        printf("TEST 2 FAILED\n");
    }
    
    newState=  BB_EVENT_ACC_RECEIVED;
    AgentSetState(newState);
    return_val=AgentGetState();
    if (return_val==newState){
        testspassed++;
        printf("TEST 3 PASSED\n");
    }else{
        printf("TEST 3 FAILED\n");
    }
    /**************************************************************************/
    //TESTING AGENTSETSTATE
    printf("Testing AgentSetState:\n");
    testspassed=0;
    newState=AGENT_STATE_ATTACKING;
    AgentSetState(newState);
    return_val=AgentGetState();
    if (return_val==newState){
        testspassed++;
        printf("TEST 1 PASSED\n");
    }else{
        printf("TEST 1 FAILED\n");
    }
    
    newState= AGENT_STATE_ACCEPTING;
    AgentSetState(newState);
    return_val=AgentGetState();
    if (return_val==newState){
        testspassed++;
        printf("TEST 2 PASSED\n");
    }else{
        printf("TEST 2 FAILED\n");
    }
    
    newState= AGENT_STATE_END_SCREEN;
    AgentSetState(newState);
    return_val=AgentGetState();
    if (return_val==newState){
        testspassed++;
        printf("TEST 3 PASSED\n");
    }else{
        printf("TEST 3 FAILED\n");
    }
    
    return 0;
    BOARD_End();
}

