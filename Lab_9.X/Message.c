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
    char outCheckSumStr[CHECKSUMSIZE];
    
    if (strlen(checksum_string) > CHECKSUMSIZE) {   // Makes sure that the checksum string is not greater than 2 characters
        return STANDARD_ERROR;
    }
    sprintf(outCheckSumStr, "%x", Message_CalculateChecksum(payload));  // Calculates the actual checksum, and converts to str for comparison with passed checksum
    
    if (strcmp(checksum_string, outCheckSumStr)) {
        printf("strings are not equal\n");
    } else {
        printf("Strsings are equal\n");
    }
    return SUCCESS;
}