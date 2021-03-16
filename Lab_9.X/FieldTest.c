
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
#include "Field.h"

int main()
{
    BOARD_Init();
    printf("Welcome to MPASAYE'S FieldTest.  Compiled on %s %s\n", __DATE__, __TIME__);

    // Testing FieldInit()
    {
        printf("\nTesting FieldInit()\n");
        int testCnt = 0;
        Field ownField, oppField;
        FieldInit(&ownField, &oppField);

        // Makes sure that the lives of your boats are all zero since you have not added any boats yet
        if (!ownField.smallBoatLives && !ownField.mediumBoatLives && !ownField.largeBoatLives && !ownField.hugeBoatLives) {
            printf("\tTEST PASSED\n");
            testCnt++;
        } else {
            printf("\tTEST FAILED\n");
        }

        // Makes sure that the lives of your opponents boats are full since they have added boats
        if (oppField.smallBoatLives && oppField.mediumBoatLives && oppField.largeBoatLives && oppField.hugeBoatLives) {
            printf("\tTEST PASSED\n");
            testCnt++;
        } else {
            printf("\tTEST FAILED\n");
        }

        // Making sure your grid is empty
        if (ownField.grid[0][0] == FIELD_SQUARE_EMPTY && ownField.grid[5][9] == FIELD_SQUARE_EMPTY && ownField.grid[3][3] == FIELD_SQUARE_EMPTY) {
            printf("\tTEST PASSED\n");
            testCnt++;
        } else {
            printf("\tTEST FAILED\n");
        }

        // Making sure the opponent grid is unknown
        if (oppField.grid[0][0] == FIELD_SQUARE_UNKNOWN && oppField.grid[5][9] == FIELD_SQUARE_UNKNOWN && oppField.grid[3][3] == FIELD_SQUARE_UNKNOWN) {
            printf("\tTEST PASSED\n");
            testCnt++;
        } else {
            printf("\tTEST FAILED\n");
        }

        printf("%d/4 TEST PASSED\n", testCnt);

    }

    // Test for FieldGetSqaureStatus()
    {
        printf("\nTesting FieldGetSquareStatus()\n");
        int testCnt = 0;
        Field ownField, oppField;
        FieldInit(&ownField, &oppField);

        ownField.grid[0][0] = FIELD_SQUARE_SMALL_BOAT;
        oppField.grid[0][0] = FIELD_SQUARE_MISS;

        if (FieldGetSquareStatus(&ownField, 0, 0) == FIELD_SQUARE_SMALL_BOAT) {
            printf("\tTEST PASSED\n");
            testCnt++;
        } else {
            printf("\tTEST FAILED\n");
        }

        if (FieldGetSquareStatus(&ownField, 10, 10) == FIELD_SQUARE_INVALID) {
            printf("\tTEST PASSED\n");
            testCnt++;
        } else {
            printf("\tTEST FAILED\n");
        }

        if (FieldGetSquareStatus(&oppField, 0, 0) == FIELD_SQUARE_MISS) {
            printf("\tTEST PASSED\n");
            testCnt++;
        } else {
            printf("\tTEST FAILED\n");
        }

        if (FieldGetSquareStatus(&ownField, 10, 10) == FIELD_SQUARE_INVALID) {
            printf("\tTEST PASSED\n");
            testCnt++;
        } else {
            printf("\tTEST FAILED\n");
        }

        printf("%d/4 TEST PASSEd\n", testCnt);
    }

    // Test for FieldSetSquareStatus
    {
        printf("\nTesting FieldSetSquareStatus()\n");
        int testCnt = 0;
        Field ownField, oppField;
        FieldInit(&ownField, &oppField);

        ownField.grid[0][0] = FIELD_SQUARE_SMALL_BOAT;
        oppField.grid[0][0] = FIELD_SQUARE_MISS;

        if (FieldSetSquareStatus(&ownField, 0, 0, FIELD_SQUARE_LARGE_BOAT) == FIELD_SQUARE_SMALL_BOAT) {
            printf("\tTEST PASSED\n");
            testCnt++;
        } else {
            printf("\tTEST FAILED\n");
        }

        // Making sure that they square changed
        if (ownField.grid[0][0] == FIELD_SQUARE_LARGE_BOAT) {
            printf("\tTEST PASSED\n");
            testCnt++;
        } else {
            printf("\tTEST FAILED\n");
        }

        if (FieldSetSquareStatus(&oppField, 0, 0, FIELD_SQUARE_HIT) == FIELD_SQUARE_MISS) {
            printf("\tTEST PASSED\n");
            testCnt++;
        } else {
            printf("\tTEST FAILED\n");
        }

        if (oppField.grid[0][0] == FIELD_SQUARE_HIT) {
            printf("\tTEST PASSED\n");
            testCnt++;
        } else {
            printf("\tTEST FAILED\n");
        }

        printf("%d/4 TEST PASSED\n", testCnt);
    }

    // Testing FieldAddBoat()
    {
        printf("\nTesting FieldAddBoat()\n");
        int testCnt = 0;
        Field ownField, oppField;
        FieldInit(&ownField, &oppField);

        if (FieldAddBoat(&ownField, 0, 0, FIELD_DIR_EAST, FIELD_BOAT_TYPE_SMALL) == SUCCESS) {
            printf("\tTEST PASSED\n");
            testCnt++;
        } else {
            printf("\tTEST FAILED\n");
        }

        if (FieldAddBoat(&ownField, 0, 0, FIELD_DIR_EAST, FIELD_BOAT_TYPE_HUGE) == STANDARD_ERROR) {
            printf("\tTEST PASSED\n");
            testCnt++;
        } else {
            printf("\tTEST FAILED\n");
        }

        if (FieldAddBoat(&ownField, 1, 0, FIELD_DIR_EAST, FIELD_BOAT_TYPE_HUGE) == SUCCESS) {
            printf("\tTEST PASSED\n");
            testCnt++;
        } else {
            printf("\tTEST FAILED\n");
        }

        if (FieldAddBoat(&ownField, 1, 0, FIELD_DIR_EAST, FIELD_BOAT_TYPE_MEDIUM) == STANDARD_ERROR) {
            printf("\tTEST PASSED\n");
            testCnt++;
        } else {
            printf("\tTEST FAILED\n");
        }

        printf("%d/4 TEST PASSED\n", testCnt);
    }

    // Testing FieldRegisterEnemyAttack()
    {
        printf("\nTesting FieldRegisterEnemyAttack()\n");
        int testCnt = 0;
        GuessData shot = {0, 0}; // Sets the row and column being attacked to [0][0]
        Field ownField, oppField;
        FieldInit(&ownField, &oppField);
        FieldAddBoat(&ownField, 0, 0, FIELD_DIR_EAST, FIELD_BOAT_TYPE_SMALL);
        FieldAddBoat(&oppField, 0, 0, FIELD_DIR_EAST, FIELD_BOAT_TYPE_HUGE);

        if (FieldRegisterEnemyAttack(&ownField, &shot) == FIELD_SQUARE_SMALL_BOAT && shot.result == RESULT_HIT) {
            printf("\tTEST PASSED\n");
            testCnt++;
        } else {
            printf("\tTEST FAILED\n");
        }

        if (FieldGetSquareStatus(&ownField, 0, 0) == FIELD_SQUARE_HIT) {
            printf("\tTEST PASSED\n");
            testCnt++;
        } else {
            printf("\tTEST FAILED\n");
        }
        
        // Testing to see that we sink a boat
        shot.col = 1;
        FieldRegisterEnemyAttack(&ownField, &shot);
        shot.col = 2;
        if (FieldRegisterEnemyAttack(&ownField, &shot) == FIELD_SQUARE_SMALL_BOAT && shot.result == RESULT_SMALL_BOAT_SUNK) {
            printf("\tTEST PASSED\n");
            testCnt++;
        } else {
            printf("\tTEST FAILED\n");
        }

        if (FieldGetSquareStatus(&ownField, 0, 0) == FIELD_SQUARE_HIT 
                && FieldGetSquareStatus(&ownField, 0, 1) == FIELD_SQUARE_HIT 
                && FieldGetSquareStatus(&ownField, 0, 2) == FIELD_SQUARE_HIT) {
            printf("\tTEST PASSED\n");
            testCnt++;
        } else {
            printf("\tTEST FAILED\n");
        }
        
        printf("%d/4 TEST PASSED\n", testCnt);
    }
    
    // Testing FieldUpdateKnowledge()
    {
        printf("\nTesting FieldUpdateKnowledge()\n");
        int testCnt = 0;
        GuessData shot = {0, 0, RESULT_HIT};
        Field ownField, oppField;
        FieldInit(&ownField, &oppField);
        
        if (FieldUpdateKnowledge(&oppField, &shot) == FIELD_SQUARE_UNKNOWN && oppField.grid[0][0] == FIELD_SQUARE_HIT) {
            printf("\tTEST PASSED\n");
            testCnt++;
        } else {
            printf("\tTEST FAILED\n");
        }
        
        shot.col = 1;
        
        if (FieldUpdateKnowledge(&oppField, &shot) == FIELD_SQUARE_UNKNOWN && oppField.grid[0][1] == FIELD_SQUARE_HIT) {
            printf("\tTEST PASSED\n");
            testCnt++;
        } else {
            printf("\tTEST FAILED\n");
        }
        
        // Makes sure that once a boat has sunk that the lives of that boat type are zero
        shot.col = 2;
        shot.result = RESULT_SMALL_BOAT_SUNK;
        if (FieldUpdateKnowledge(&oppField, &shot) == FIELD_SQUARE_UNKNOWN 
                && oppField.grid[0][2] == FIELD_SQUARE_HIT 
                && oppField.smallBoatLives == 0) {
            printf("\tTEST PASSED\n");
            testCnt++;
        } else {
            printf("\tTEST FAILED\n");
        }
        
        printf("%d/3 TEST PASSED\n", testCnt);
    }
    
    // Testing FieldGetBoatStates()
    {
        printf("\nTesting FieldGetBoatStates()\n");
        int testCnt = 0;
        Field ownField, oppField;
        FieldInit(&ownField, &oppField);
        ownField.hugeBoatLives = 1;
        ownField.largeBoatLives = 0;
        ownField.mediumBoatLives = 1;
        ownField.smallBoatLives = 0;
        
        if (!(FieldGetBoatStates(&ownField) & FIELD_BOAT_STATUS_SMALL)) {
            printf("\tTEST PASSED\n");
            testCnt++;
        } else {
            printf("\tTEST FAILED\n");
        }
        
        if ((FieldGetBoatStates(&ownField) & FIELD_BOAT_STATUS_MEDIUM)) {
            printf("\tTEST PASSED\n");
            testCnt++;
        } else {
            printf("\tTEST FAILED\n");
        }
        
        if (!(FieldGetBoatStates(&ownField) & FIELD_BOAT_STATUS_LARGE)) {
            printf("\tTEST PASSED\n");
            testCnt++;
        } else {
            printf("\tTEST FAILED\n");
        }
        
        if ((FieldGetBoatStates(&ownField) & FIELD_BOAT_STATUS_HUGE)) {
            printf("\tTEST PASSED\n");
            testCnt++;
        } else {
            printf("\tTEST FAILED\n");
        }
        
        printf("%d/4 TEST PASSED\n", testCnt);
    }
    
    // Testing FieldAIPlaceAllBoats()
    {
        printf("\nTesting FieldAIPlaceAllBoats()\n");
        int testCnt = 0;
        Field ownField, oppField;
        
        FieldInit(&ownField, &oppField);
        if (FieldAIPlaceAllBoats(&ownField)) {
            printf("\tTEST PASSED\n");
            testCnt++;
        } else {
            printf("\tTEST FAILED\n");
        }
        if (ownField.hugeBoatLives && ownField.largeBoatLives && ownField.mediumBoatLives && ownField.smallBoatLives) {
            printf("\tTEST PASSED\n");
            testCnt++;
        } else {
            printf("\tTEST FAILED\n");
        }
        
        printf("%d/2 TEST PASSEd\n", testCnt);
    }
    while (1);
}
