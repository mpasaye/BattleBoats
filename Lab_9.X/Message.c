/* Creator: Michael Pasaye
 * Class: CSE13E Winter 2021
 * File: Message.c
 * Lab: BattleBoats
 */

// Standard Libraries
#include <stdio.h>
#include <string.h>

// CSE13E Libraries
#include "BOARD.h"

// BattleBoat Libraries
#include "Message.h"

// Define Block
#define CHECKSUMSIZE 2 // Accounts for both characters

// Function Block

uint8_t Message_CalculateChecksum(const char* payload)
{
    int checkSum = 0;
    
    while (*payload) {
        
        checkSum ^= *payload++; // Iterates through each element of the char array and XORs the value with checkSum
    }
    
    return checkSum;
}

int Message_ParseMessage(const char* payload, const char* checksum_string, BB_Event * message_event)
{
    if (strlen(checksum_string) > CHECKSUMSIZE) {
        return STANDARD_ERROR;
    }
    return SUCCESS;
}