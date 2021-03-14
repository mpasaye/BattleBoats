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
#define MAXPARAMETERS 3
#define MINPAYLOADSIZE 5 // Accounts for the smallest payload that has one argument
#define SINGLEPARAM 2 // Message types that only have one argument
#define DOUBLEPARAM 4 // Message types that have two arguments
#define TRIPLEPARAM 6 // Message type that have three arguments
#define ASCIIZERO 48
#define ASCIININE 57
#define ASCIIA 65
#define ASCIIF 70
// TypeDef Block

static typedef enum {
    DECODE_WAITING,
    DECODE_PAYLOAD,
    DECODE_CHECKSUM
    //DECODE_END
} DecodeState;

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
    MessageType messageID;
    int i;
    char calcCheckSum[MESSAGE_CHECKSUM_LEN], payloadType[PAYLOADTYPESIZE];
    sprintf(calcCheckSum, "%X", Message_CalculateChecksum(payload));

    // Makes sure that the checksum string is exactly 2 characters, and the payload does not exceed max length
    if (strlen(checksum_string) != MESSAGE_CHECKSUM_LEN || strlen(payload) > MESSAGE_MAX_PAYLOAD_LEN) {
        printf("INVALID CHECKSUM/PAYLOAD SIZE\n");
        return STANDARD_ERROR;
    }

    // Makes sure that the calculated checksum and the passed are equivalent
    if (strcmp(calcCheckSum, checksum_string)) {
        printf("INEQUIVALENT CHECKSUM\n");
        return STANDARD_ERROR;
    }

    // Makes sure that we have a payload that is not an abnormal size
    if (strlen(payload) < MINPAYLOADSIZE) {
        printf("PAYLOAD INVALID SIZE\n");
        return STANDARD_ERROR;
    }

    // Obtains the payload type and stores it in a string
    for (i = 0; i < PAYLOADTYPESIZE - 1; i++) { // Subtracting leaves room for the null terminator 
        payloadType[i] = *payload++;
    }
    payloadType[i] = '\0'; // Appends the null terminator to the string

    // This block determines what the payload type is and changes the BB_Event type accordingly 
    if (!strcmp(payloadType, "CHA")) {
        printf("messageID: CHA\n");
        messageID = MESSAGE_CHA;
    } else if (!strcmp(payloadType, "ACC")) {
        printf("messageID: ACC\n");
        messageID = MESSAGE_ACC;
    } else if (!strcmp(payloadType, "REV")) {
        printf("messageID: REV\n");
        messageID = MESSAGE_REV;
    } else if (!strcmp(payloadType, "SHO")) {
        printf("messageID: SHO\n");
        messageID = MESSAGE_SHO;
    } else if (!strcmp(payloadType, "RES")) {
        printf("messageID: RES\n");
        messageID = MESSAGE_RES;
    } else {
        printf("INVALID MESSAGE TYPE\n");
        messageID = MESSAGE_ERROR;
        return STANDARD_ERROR;
    }

    // This block retrieves the parameters from the payload and updates the BB_Event accordingly
    char arg[MESSAGE_MAX_PAYLOAD_LEN]; // stores the string that contains the arguments to be parsed
    uint16_t param[MAXPARAMETERS]; // Stores each tok to be passed to the message_event
    char *tok; // Stores the token after each call to strtok()
    strcpy(arg, payload);
    i = 0; // Reinitialize i to zero to be used with param[] array

    switch (messageID) {
    case MESSAGE_ERROR:
        printf("message error\n");
        break;
    case MESSAGE_NONE:
        printf("no message event\n");
        break;
    case MESSAGE_CHA:
        printf("CHA RECEIVED\n");
        if (strlen(arg) != SINGLEPARAM) {
            printf("INVALID ARGUMENTS\n");
            return STANDARD_ERROR;
        }

        tok = strtok(arg, ",");
        if (!atoi(tok) && (strcmp(tok, "0") != 0)) {
            return STANDARD_ERROR;
        }
        param[i++] = atoi(tok);
        message_event -> type = BB_EVENT_CHA_RECEIVED;
        message_event -> param0 = param[0];
        break;
    case MESSAGE_ACC:
        printf("ACC RECEIVED\n");
        if (strlen(arg) != SINGLEPARAM) {
            printf("INVALID ARGUMENTS\n");
            return STANDARD_ERROR;
        }

        tok = strtok(arg, ",");
        if (!atoi(tok) && (strcmp(tok, "0") != 0)) {
            return STANDARD_ERROR;
        }
        param[i++] = atoi(tok);
        message_event -> type = BB_EVENT_ACC_RECEIVED;
        message_event -> param0 = param[0];
        break;
    case MESSAGE_REV:
        printf("REV RECEIVED\n");
        if (strlen(arg) != SINGLEPARAM) {
            printf("INVALID ARGUMENTS\n");
            return STANDARD_ERROR;
        }

        tok = strtok(arg, ",");
        if (!atoi(tok) && (strcmp(tok, "0") != 0)) {
            return STANDARD_ERROR;
        }

        param[i++] = atoi(tok);
        message_event -> type = BB_EVENT_REV_RECEIVED;
        message_event -> param0 = param[0];
        break;
    case MESSAGE_SHO:
        printf("SHO RECEIVED\n");
        if (strlen(arg) != DOUBLEPARAM) {
            printf("INVALID ARGUMENTS\n");
            return STANDARD_ERROR;
        }

        tok = strtok(arg, ",");
        while (tok != NULL) {
            if (!atoi(tok) && (strcmp(tok, "0") != 0)) {
                return STANDARD_ERROR;
            }
            param[i++] = atoi(tok);
            tok = strtok(NULL, ",");
        }

        message_event -> type = BB_EVENT_SHO_RECEIVED;
        message_event -> param0 = param[0];
        message_event -> param1 = param[1];
        break;
    case MESSAGE_RES:
        printf("RES RECEIVED\n");
        if (strlen(arg) != TRIPLEPARAM) {
            printf("INVALID ARGUMENTS\n");
            return STANDARD_ERROR;
        }
        
        tok = strtok(arg, ",");
        while (tok != NULL) {
            if (!atoi(tok) && (strcmp(tok, "0") != 0)) {
                printf("ATOI FAILED\n");
                return STANDARD_ERROR;
            }
            param[i++] = atoi(tok);
            tok = strtok(NULL, ",");
        }

        message_event -> type = BB_EVENT_RES_RECEIVED;
        message_event -> param0 = param[0];
        message_event -> param1 = param[1];
        message_event -> param2 = param[2];
        break;
    }

    return SUCCESS;
}

int Message_Encode(char *message_string, Message message_to_encode)
{
    char payload[MESSAGE_MAX_PAYLOAD_LEN];
    uint8_t checkSum;

    switch (message_to_encode.type) {
    case MESSAGE_NONE:
        return MESSAGE_NONE;
        break;
    case MESSAGE_ERROR:
        return MESSAGE_ERROR;
        break;
    case MESSAGE_CHA:
        sprintf(payload, PAYLOAD_TEMPLATE_CHA, message_to_encode.param0);
        checkSum = Message_CalculateChecksum(payload);
        sprintf(message_string, MESSAGE_TEMPLATE, payload, checkSum);
        break;
    case MESSAGE_ACC:
        sprintf(payload, PAYLOAD_TEMPLATE_ACC, message_to_encode.param0);
        checkSum = Message_CalculateChecksum(payload);
        sprintf(message_string, MESSAGE_TEMPLATE, payload, checkSum);
        break;
    case MESSAGE_REV:
        sprintf(payload, PAYLOAD_TEMPLATE_REV, message_to_encode.param0);
        checkSum = Message_CalculateChecksum(payload);
        sprintf(message_string, MESSAGE_TEMPLATE, payload, checkSum);
        break;
    case MESSAGE_SHO:
        sprintf(payload, PAYLOAD_TEMPLATE_SHO, message_to_encode.param0, message_to_encode.param1);
        checkSum = Message_CalculateChecksum(payload);
        sprintf(message_string, MESSAGE_TEMPLATE, payload, checkSum);
        break;
    case MESSAGE_RES:
        sprintf(payload, PAYLOAD_TEMPLATE_RES, message_to_encode.param0, message_to_encode.param1, message_to_encode.param2);
        checkSum = Message_CalculateChecksum(payload);
        sprintf(message_string, MESSAGE_TEMPLATE, payload, checkSum);
        break;
    }
    return strlen(message_string);
}

int Message_Decode(unsigned char char_in, BB_Event * decoded_message_event)
{
    static DecodeState decodeState = DECODE_WAITING;
    static char message[MESSAGE_MAX_LEN], payload[MESSAGE_MAX_PAYLOAD_LEN], checkSum[MESSAGE_CHECKSUM_LEN];
    static int messageIndex = 0, payloadIndex = 0, checkSumLength = 0;
    printf("state: %d\n", decodeState);
    printf("message: %s\n", message);
    printf("messageIndex: %d\n", messageIndex);

    switch (decodeState) {
    case DECODE_WAITING:

        if (char_in == '$') {
            // Makes sure the decode_message_event parameters are empty
            decoded_message_event -> param0 = NULL;
            decoded_message_event -> param1 = NULL;
            decoded_message_event -> param2 = NULL;
            printf("START DELIMITER\n");
            message[messageIndex++] = char_in;
            decodeState = DECODE_PAYLOAD;
        }
        decoded_message_event -> type = BB_EVENT_NO_EVENT;
        break;
    case DECODE_PAYLOAD:

        printf("RECORD PAYLOAD\n");
        // If statement checks for the error cases
        if (char_in == '$' || char_in == '\n' || (messageIndex + 1 > MESSAGE_MAX_PAYLOAD_LEN)) {
            printf("UNEXPECTED DELIMETER or EXCEDDED PAYLOAD LEN\n");
            decoded_message_event -> type = BB_EVENT_ERROR;
            decodeState = DECODE_WAITING;
        }
        message[messageIndex++] = char_in;

        if (char_in == '*') {
            decodeState = DECODE_CHECKSUM;
        } else {    // If its not the delimiter then we record the char for our payload
            payload[payloadIndex++] = char_in;
        }
        break;
    case DECODE_CHECKSUM:
        printf("RECORD CHECKSUM\n");
        
        if (char_in == '\n') {
            printf("GO TO END STATE\n");
            message[messageIndex++] = char_in;
            //checkSum[checkSumLength++] = char_in;
            break;
        }
        
        if (checkSumLength == MESSAGE_CHECKSUM_LEN) {
            printf("INVALID CHECKSUM LEN\n");
            decoded_message_event -> type = BB_EVENT_ERROR;
            decodeState = DECODE_WAITING;
        }

        // If statement makes sure that we either have a capital A-F or number from 0-9
        if (((int) char_in >= ASCIIZERO && (int) char_in <= ASCIININE) || ((int) char_in >= ASCIIA && (int) char_in <= ASCIIF)) {
            printf("NUMBER OR LETTER\n");
            message[messageIndex++] = char_in;
            checkSum[checkSumLength++] = char_in;
        } else {
            printf("INVALID CHECKSUM CHAR\n");
            decoded_message_event -> type = BB_EVENT_ERROR;
            decodeState = DECODE_WAITING;
        }
        break;
    }

    // End state where we make sure that we have a valid payload and check sum matches
    if (char_in == '\n') {
        if (!Message_ParseMessage(payload, checkSum, decoded_message_event)) {
            printf("ERRROR\n");
            decoded_message_event -> type = BB_EVENT_ERROR;
        }
        // Need to reset all values
        decodeState = DECODE_WAITING;
        messageIndex = 0, payloadIndex = 0, checkSumLength = 0; // Resetting all the counters
        // These lines empty all the char arrays
        memset(message, '\0', strlen(message));
        memset(payload, '\0', strlen(payload));
        memset(checkSum, '\0', strlen(checkSum));
    }
    
    if (decoded_message_event -> type == BB_EVENT_ERROR) {
        return STANDARD_ERROR;
    }
    return SUCCESS;
}