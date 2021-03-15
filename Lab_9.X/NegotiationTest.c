/* Creator: Michael Pasaye
 * Class: CSE13E Winter 2021
 * File: NegotiationTest.c
 * Lab: BattleBoats
 */

// Standard libraries
#include <stdio.h>
#include <stdlib.h>

//CSE13 Support Library
#include "BOARD.h"

//CSE13 standard libraries:

// Battleboats Libraries:
#include "BattleBoats.h"
#include "Negotiation.h"

int main()
{
    BOARD_Init();
    printf("Welcome to MPASAYE'S NegotiationTest.  Compiled on %s %s\n", __DATE__, __TIME__);

    // Test for NegotiationHash
    {
        printf("\nTesting NegotiationHash\n");
        int testCnt = 0;
        NegotiationData hash = 0, secret = 3;

        hash = NegotiationHash(secret);
        if (hash == 9) {
            printf("\tTEST PASSED\n");
            testCnt++;
        } else {
            printf("\tTEST FAILED\n");
        }

        secret = 12345;
        hash = NegotiationHash(secret);
        if (hash == 43182) {
            printf("\tTEST PASSED\n");
            testCnt++;
        } else {
            printf("\tTEST FAILED\n");
        }

        secret = 45896;
        hash = NegotiationHash(secret);
        if (hash == 2311) {
            printf("\tTEST PASSED\n");
            testCnt++;
        } else {
            printf("\tTEST FAILED\n");
        }

        printf("%d/3 TEST PASSED\n", testCnt);
    }

    // Test for NegotiationVerify
    {
        printf("\nTesting NegotiationVerify\n");
        int verifyRes = 0, testCnt = 0;
        NegotiationData secret, commitment;
        
        secret = 9;
        commitment = NegotiationHash(secret);
        verifyRes = NegotiationVerify(secret, commitment);
        if (verifyRes) {
            printf("\tTEST PASSED\n");
            testCnt++;
        } else {
            printf("\tTEST FAILED\n");
        }
        
        secret = 2456;
        commitment = NegotiationHash(secret);
        verifyRes = NegotiationVerify(secret, commitment);
        if (verifyRes) {
            printf("\tTEST PASSED\n");
            testCnt++;
        } else {
            printf("\tTEST FAILED\n");
        }
        
        // This test will try to accurately detect cheating
        secret = 69;
        commitment = 2012;
        verifyRes = NegotiationVerify(secret, commitment);
        if (!verifyRes) {
            printf("\tTEST PASSED\n");
            testCnt++;
        } else {
            printf("\tTEST FAILED\n");
        }
        
        printf("%d/3 TEST PASSED\n", testCnt);
    }

    // Test for NegotiateCoinFlip
    {
        printf("\nTesting NegotiateCoinFlip\n");
        int coinOut = 0, testCnt = 0;
        NegotiationData a, b;
        
        a = 12;
        b = 5;
        coinOut = NegotiateCoinFlip(a, b);
        if (coinOut == TAILS) {
            printf("\tTEST PASSED\n");
            testCnt++;
        } else {
            printf("\tTEST FAILED\n");
        }
        
        a = 7;
        b = 45;
        coinOut = NegotiateCoinFlip(a, b);
        if (coinOut == HEADS) {
            printf("\tTEST PASSED\n");
            testCnt++;
        } else {
            printf("\tTEST FAILED\n");
        }
        
        a = 2456;
        b = 5959;
        coinOut = NegotiateCoinFlip(a, b);
        if (coinOut == HEADS) {
            printf("\tTEST PASSED\n");
            testCnt++;
        } else {
            printf("\tTEST FAILED\n");
        }
        
        printf("%d/3 TEST PASSED\n", testCnt);
    }

    while (1);
}
