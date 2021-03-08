/* Creator: Michael Pasaye
 * Class: CSE13E Winter 2021
 * File: Message.c
 * Lab: BattleBoats
 */

// Standard Libraries
#include <stdio.h>

// CSE13E Libraries

// BattleBoat Libraries
#include "Message.h"

// Function Block

uint8_t Message_CalculateChecksum(const char* payload)
{
    int checkSum = 0;
    
    while (*payload) {
        
        checkSum ^= *payload++; // Iterates through each element of the char array and XORs the value with checkSum
    }
    
    return checkSum;
}