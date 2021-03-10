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
#define PAYLOADTYPESIZE 4 // Size of different payload types accounting for null terminator

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
    Message message;
    int i;
    char calcCheckSum[MESSAGE_CHECKSUM_LEN], payloadType[PAYLOADTYPESIZE];
    sprintf(calcCheckSum, "%x", Message_CalculateChecksum(payload));
    
    // Makes sure that the checksum string is exactly 2 characters
    if (strlen(checksum_string) != MESSAGE_CHECKSUM_LEN) {
        printf("INVALID CHECKSUM SIZE\n");
        return STANDARD_ERROR;
    }
    
    // Makes sure that the calculated checksum and the passed are the same
    if (strcmp(calcCheckSum, checksum_string)) {
        printf("INEQUIVALENT CHECKSUM\n");
        return STANDARD_ERROR;
    }
    // Determine what the payload type is
    for (i = 0; i < PAYLOADTYPESIZE - 1; i++) {
        payloadType[i] = *payload++;
    }
    payloadType[i] = '\0'; // Appends the null terminator to the string
    
    // This block determines what the message type is and changes the BB_Event values
    if (!strcmp(payloadType, "CHA")) {
        printf("messageID: CHA\n");
        message_event -> type = BB_EVENT_CHA_RECEIVED;
    } else if (!strcmp(payloadType, "ACC")) {
        printf("messageID: ACC\n");
        message_event -> type = BB_EVENT_ACC_RECEIVED;
    } else if (!strcmp(payloadType, "REV")) {
        printf("messageID: REV\n");
        message_event -> type = BB_EVENT_REV_RECEIVED;
    } else if (!strcmp(payloadType, "SHO")) {
        printf("messageID: SHO\n");
        message_event->type = BB_EVENT_SHO_RECEIVED;
    } else if (!strcmp(payloadType, "RES")) {
        printf("messageID: RES\n");
        message_event -> type = BB_EVENT_RES_RECEIVED;
    } else {
        printf("INVALID MESSAGE TYPE\n");
        message_event -> type = BB_EVENT_NO_EVENT;
        return STANDARD_ERROR;
    }
    //printf("message type: %d\n", message_event -> type);
    
    // Need to see if the payload template is a valid template
    
    
    return SUCCESS;
}