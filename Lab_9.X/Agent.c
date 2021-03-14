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

// Define Block

// TypeDef Block

// Variable Block

static AgentState agentState;
static int turnCnt;

// Function Block

void AgentInit(void)
{
    agentState = AGENT_STATE_START; // Initializing the state machine to Start
    turnCnt = 0;    // Initialize the turn counter to zero
}

/*Message AgentRun(BB_Event event)
{
    
}*/

AgentState AgentGetState(void)
{
    return agentState;
}

void AgentSetState(AgentState newState)
{
    agentState = newState;
}
