/* Creator: Michael Pasaye
 * Class: CSE13E Winter 2021
 * File: Message.c
 * Lab: BattleBoats
 */

// Standard Libraries
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// CSE13E Libraries
#include "BOARD.h"

// BattleBoat Libraries
#include "Message.h"

// Define Block
#define PAYLOADTYPESIZE 4 // Size of different payload types accounting for null terminator
#define AMOUNTOFPARAMETERS 3
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
    int i, param[AMOUNTOFPARAMETERS];
    char calcCheckSum[MESSAGE_CHECKSUM_LEN], payloadType[PAYLOADTYPESIZE];
    sprintf(calcCheckSum, "%X", Message_CalculateChecksum(payload));
    
    //printf("str: %s\n", calcCheckSum);
    // Makes sure that the checksum string is exactly 2 characters
    if (strlen(checksum_string) != MESSAGE_CHECKSUM_LEN) {
        printf("INVALID CHECKSUM SIZE\n");
        return STANDARD_ERROR;
    }
    
    // Makes sure that the calculated checksum and the passed are equivalent
    if (strcmp(calcCheckSum, checksum_string)) {
        printf("INEQUIVALENT CHECKSUM\n");
        return STANDARD_ERROR;
    }
    // Obtains the payload type and stores it in a string
    for (i = 0; i < PAYLOADTYPESIZE - 1; i++) {
        payloadType[i] = *payload++;
    }
    payloadType[i] = '\0'; // Appends the null terminator to the string
    //printf("%s\n", payload);
    //printf("%d\n", strncmp(payload, "SHO", 3));
    // This block determines what the payload type is and changes the BB_Event type accordingly 
    if (!strcmp(payloadType, "CHA")) {
        //printf("messageID: CHA\n");
        message_event -> type = BB_EVENT_CHA_RECEIVED;
    } else if (!strcmp(payloadType, "ACC")) {
        //printf("messageID: ACC\n");
        message_event -> type = BB_EVENT_ACC_RECEIVED;
    } else if (!strcmp(payloadType, "REV")) {
        //printf("messageID: REV\n");
        message_event -> type = BB_EVENT_REV_RECEIVED;
    } else if (!strcmp(payloadType, "SHO")) {
        printf("messageID: SHO\n");
        message_event->type = BB_EVENT_SHO_RECEIVED;
    } else if (!strcmp(payloadType, "RES")) {
        //printf("messageID: RES\n");
        message_event -> type = BB_EVENT_RES_RECEIVED;
    } else {
        printf("INVALID MESSAGE TYPE\n");
        message_event -> type = BB_EVENT_NO_EVENT;
        return STANDARD_ERROR;
    }
    
    // Need to see if the payload template is a valid template
    printf("message type: %d\n", message_event -> type);
    char arg[MESSAGE_MAX_PAYLOAD_LEN];
    strcpy(arg, payload);
    printf("payload before token: %s\n", payload);
    char *tok;
    //const char de[] = ",";
    tok = strtok(arg, ",");
    printf("token: %s\n", tok);
    i = 0;
    while (tok != NULL) {
        printf("next token: %s\n", tok);
        if (!atoi(tok) || i >= 1) {
            printf("INVALID TOKEN\n");
            return STANDARD_ERROR;
        }
        tok = strtok(NULL, ",");
        i++;
    }
    
    // This block retrieves the parameters from the payload and updates the BB_Event accordingly
    /*switch(message_event -> type) {
        case BB_EVENT_NO_EVENT:
            printf("no message event\n");
            break;
        case BB_EVENT_CHA_RECEIVED:
            printf("challenge recieved\n");
            
    }*/
    //printf("payload Template: %d", strcmp(payload, PAYLOAD_TEMPLATE_SHO));
    
    return SUCCESS;
}