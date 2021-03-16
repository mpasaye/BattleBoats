#include "Field.h"
#include "BOARD.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * This function is optional, but recommended.   It prints a representation of both
 * fields, similar to the OLED display.
 * @param f The field to initialize.
 * @param p The data to initialize the entire field to, should be a member of enum
 *                     SquareStatus.
 */
void FieldPrint_UART(Field *own_field, Field * opp_field) {
    int row = 0;
    int col = 0;
    printf("printing my field\n");
    for (row = 0; row < FIELD_ROWS; row++) {
        printf("%d| ", row);
        for (col = 0; col < FIELD_COLS; col++) {
            printf("%d ", own_field->grid[row][col]);
        }
        printf("|\n");
    }
    row = 0;
    col = 0;
    printf("printing opp field\n");
    for (row = 0; row < FIELD_ROWS; row++) {
        printf("%d| ", row);
        for (col = 0; col < FIELD_COLS; col++) {
            printf("%d ", opp_field->grid[row][col]);
        }
        printf("|\n");
    }

}

/**
 * FieldInit() will initialize two passed field structs for the beginning of play.
 * Each field's grid should be filled with the appropriate SquareStatus (
 * FIELD_SQUARE_EMPTY for your own field, FIELD_SQUARE_UNKNOWN for opponent's).
 * Additionally, your opponent's field's boatLives parameters should be filled
 *  (your own field's boatLives will be filled when boats are added)
 * 
 * FieldAI_PlaceAllBoats() should NOT be called in this function.
 * 
 * @param own_field     //A field representing the agents own ships
 * @param opp_field     //A field representing the opponent's ships
 */
void FieldInit(Field *own_field, Field * opp_field) {

    own_field->smallBoatLives = 0;
    own_field->mediumBoatLives = 0;
    own_field->largeBoatLives = 0;
    own_field->hugeBoatLives = 0;

    opp_field->smallBoatLives = FIELD_BOAT_SIZE_SMALL;
    opp_field->mediumBoatLives = FIELD_BOAT_SIZE_MEDIUM;
    opp_field->largeBoatLives = FIELD_BOAT_SIZE_LARGE;
    opp_field->hugeBoatLives = FIELD_BOAT_SIZE_HUGE;
    int x = 0;
    int y = 0;
    for (x = 0; x < FIELD_COLS; x++) {
        for (y = 0; y < FIELD_ROWS; y++) {
            own_field->grid[y][x] = FIELD_SQUARE_EMPTY;
            opp_field->grid[y][x] = FIELD_SQUARE_UNKNOWN;
        }
    }
}

/**
 * Retrieves the value at the specified field position.
 * @param f     //The Field being referenced
 * @param row   //The row-component of the location to retrieve
 * @param col   //The column-component of the location to retrieve
 * @return  FIELD_SQUARE_INVALID if row and col are not valid field locations
 *          Otherwise, return the status of the referenced square 
 */
SquareStatus FieldGetSquareStatus(const Field *f, uint8_t row, uint8_t col) {
    if (row < FIELD_ROWS && col < FIELD_COLS) {
        return f->grid[row][col];
    }
    return FIELD_SQUARE_INVALID;
}

/**
 * This function provides an interface for setting individual locations within a Field struct. This
 * is useful when FieldAddBoat() doesn't do exactly what you need. For example, if you'd like to use
 * FIELD_SQUARE_CURSOR, this is the function to use.
 * 
 * @param f The Field to modify.
 * @param row The row-component of the location to modify
 * @param col The column-component of the location to modify
 * @param p The new value of the field location
 * @return The old value at that field location
 */
SquareStatus FieldSetSquareStatus(Field *f, uint8_t row, uint8_t col, SquareStatus p) {
    int return_val = f->grid[row][col];
    f->grid[row][col] = p;
    return return_val;
}

/**
 * FieldAddBoat() places a single ship on the player's field based on arguments 2-5. Arguments 2, 3
 * represent the x, y coordinates of the pivot point of the ship.  Argument 4 represents the
 * direction of the ship, and argument 5 is the length of the ship being placed. 
 * 
 * All spaces that
 * the boat would occupy are checked to be clear before the field is modified so that if the boat
 * can fit in the desired position, the field is modified as SUCCESS is returned. Otherwise the
 * field is unmodified and STANDARD_ERROR is returned. There is no hard-coded limit to how many
 * times a boat can be added to a field within this function.
 * 
 * In addition, this function should update the appropriate boatLives parameter of the field.
 *
 * So this is valid test code:
 * {
 *   Field myField;
 *   FieldInit(&myField,FIELD_SQUARE_EMPTY);
 *   FieldAddBoat(&myField, 0, 0, FIELD_BOAT_DIRECTION_EAST, FIELD_BOAT_TYPE_SMALL);
 *   FieldAddBoat(&myField, 1, 0, FIELD_BOAT_DIRECTION_EAST, FIELD_BOAT_TYPE_MEDIUM);
 *   FieldAddBoat(&myField, 1, 0, FIELD_BOAT_DIRECTION_EAST, FIELD_BOAT_TYPE_HUGE);
 *   FieldAddBoat(&myField, 0, 6, FIELD_BOAT_DIRECTION_SOUTH, FIELD_BOAT_TYPE_SMALL);
 * }
 *
 * should result in a field like:
 *      0 1 2 3 4 5 6 7 8 9
 *     ---------------------
 *  0 [ 3 3 3 . . . 3 . . . ]
 *  1 [ 4 4 4 4 . . 3 . . . ]
 *  2 [ . . . . . . 3 . . . ]
 *  3 [ . . . . . . . . . . ]
 *  4 [ . . . . . . . . . . ]
 *  5 [ . . . . . . . . . . ]
 *     
 * @param f The field to grab data from.
 * @param row The row that the boat will start from, valid range is from 0 and to FIELD_ROWS - 1.
 * @param col The column that the boat will start from, valid range is from 0 and to FIELD_COLS - 1.
 * @param dir The direction that the boat will face once places, from the BoatDirection enum.
 * @param boatType The type of boat to place. Relies on the FIELD_SQUARE_*_BOAT values from the
 * SquareStatus enum.
 * @return SUCCESS for success, STANDARD_ERROR for failure
 */
uint8_t FieldAddBoat(Field *own_field, uint8_t row, uint8_t col, BoatDirection dir, BoatType boat_type) {
    int size;
    int square;
    if (boat_type == FIELD_BOAT_TYPE_SMALL) {
        size = FIELD_BOAT_SIZE_SMALL;
        square = FIELD_SQUARE_SMALL_BOAT;
        own_field->smallBoatLives = FIELD_BOAT_SIZE_SMALL;
    } else if (boat_type == FIELD_BOAT_TYPE_MEDIUM) {
        size = FIELD_BOAT_SIZE_MEDIUM;
        square = FIELD_SQUARE_MEDIUM_BOAT;
        own_field->smallBoatLives = FIELD_BOAT_SIZE_MEDIUM;
    } else if (boat_type == FIELD_BOAT_TYPE_LARGE) {
        size = FIELD_BOAT_SIZE_LARGE;
        square = FIELD_SQUARE_LARGE_BOAT;
        own_field->smallBoatLives = FIELD_BOAT_SIZE_LARGE;
    } else if (boat_type == FIELD_BOAT_TYPE_HUGE) {
        size = FIELD_BOAT_SIZE_HUGE;
        square = FIELD_SQUARE_HUGE_BOAT;
        own_field->smallBoatLives = FIELD_BOAT_SIZE_HUGE;
    }
    //printf("printing size: %d\n", size);
    int lastindex;
    int maxlen;
    if (dir == FIELD_DIR_SOUTH) {
        lastindex = row + boat_type;
        maxlen = FIELD_ROWS;
    } else {
        lastindex = col + boat_type;
        maxlen = FIELD_COLS;
    }
    if ((row >= 0) && (col >= 0) && (row < FIELD_ROWS) && (col < FIELD_COLS) && (lastindex < maxlen)) {
        //printf("entering if statement\n");
        if (dir == FIELD_DIR_SOUTH) {

            int y = row;
            for (y = row; y < (size + row); y++) {
                if (own_field->grid[y][col] == FIELD_SQUARE_EMPTY) {
                    continue;
                } else {
                    return STANDARD_ERROR;
                }
            }
            for (y = row; y < (size + col); y++) {
                own_field->grid[y][col] = square;
            }

        } else if (dir == FIELD_DIR_EAST) {
            //printf("entering east\n");
            int x = col;
            for (x = col; x < (size + col); x++) {
                if (own_field->grid[row][x] == FIELD_SQUARE_EMPTY) {
                    continue;
                } else {
                    return STANDARD_ERROR;
                }
            }
            for (x = col; x < (size + col); x++) {
                own_field->grid[row][x] = square;
            }
        }
        return SUCCESS;
    }
    return STANDARD_ERROR;
}

/**
 * This function registers an attack at the gData coordinates on the provided field. This means that
 * 'f' is updated with a FIELD_SQUARE_HIT or FIELD_SQUARE_MISS depending on what was at the
 * coordinates indicated in 'gData'. 'gData' is also updated with the proper HitStatus value
 * depending on what happened AND the value of that field position BEFORE it was attacked. Finally
 * this function also reduces the lives for any boat that was hit from this attack.
 * @param f The field to check against and update.
 * @param gData The coordinates that were guessed. The result is stored in gData->result as an
 *               output.  The result can be a RESULT_HIT, RESULT_MISS, or RESULT_***_SUNK.
 * @return The data that was stored at the field position indicated by gData before this attack.
 */
SquareStatus FieldRegisterEnemyAttack(Field *own_field, GuessData *opp_guess) {
    SquareStatus return_val = own_field->grid[opp_guess->row][opp_guess->col];
    
    if (own_field->grid[opp_guess->row][opp_guess->col] == FIELD_SQUARE_EMPTY) {
        own_field->grid[opp_guess->row][opp_guess->col] = FIELD_SQUARE_MISS;
        opp_guess->result = RESULT_MISS;
    } else if (own_field->grid[opp_guess->row][opp_guess->col] == FIELD_SQUARE_SMALL_BOAT) {
        own_field->grid[opp_guess->row][opp_guess->col] = FIELD_SQUARE_HIT;
        own_field->smallBoatLives--;
        if (own_field->smallBoatLives > 0) {
            opp_guess->result = RESULT_HIT;
        } else {
            opp_guess->result = RESULT_SMALL_BOAT_SUNK;
        }
        
    } else if (own_field->grid[opp_guess->row][opp_guess->col] == FIELD_SQUARE_MEDIUM_BOAT) {
        own_field->grid[opp_guess->row][opp_guess->col] = FIELD_SQUARE_HIT;
        own_field->mediumBoatLives--;
        if (own_field->mediumBoatLives > 0) {
            opp_guess->result = RESULT_HIT;
        } else {
            opp_guess->result = RESULT_MEDIUM_BOAT_SUNK;
        }
    } else if (own_field->grid[opp_guess->row][opp_guess->col] == FIELD_SQUARE_LARGE_BOAT) {
        own_field->grid[opp_guess->row][opp_guess->col] = FIELD_SQUARE_HIT;
        own_field->largeBoatLives--;
        if (own_field->largeBoatLives > 0) {
            opp_guess->result = RESULT_HIT;
        } else {
            opp_guess->result = RESULT_LARGE_BOAT_SUNK;
        }
    } else if (own_field->grid[opp_guess->row][opp_guess->col] == FIELD_SQUARE_HUGE_BOAT) {
        own_field->grid[opp_guess->row][opp_guess->col] = FIELD_SQUARE_HIT;
        own_field->hugeBoatLives--;
        if (own_field->hugeBoatLives > 0) {
            opp_guess->result = RESULT_HIT;
        } else {
            opp_guess->result = RESULT_HUGE_BOAT_SUNK;
        }
    }
    return return_val;
}

/**
 * This function updates the FieldState representing the opponent's game board with whether the
 * guess indicated within gData was a hit or not. If it was a hit, then the field is updated with a
 * FIELD_SQUARE_HIT at that position. If it was a miss, display a FIELD_SQUARE_EMPTY instead, as
 * it is now known that there was no boat there. The FieldState struct also contains data on how
 * many lives each ship has. Each hit only reports if it was a hit on any boat or if a specific boat
 * was sunk, this function also clears a boats lives if it detects that the hit was a
 * RESULT_*_BOAT_SUNK.
 * @param f The field to grab data from.
 * @param gData The coordinates that were guessed along with their HitStatus.
 * @return The previous value of that coordinate position in the field before the hit/miss was
 * registered.
 */
SquareStatus FieldUpdateKnowledge(Field *opp_field, const GuessData *own_guess) {

    SquareStatus return_val = opp_field->grid[own_guess->row][own_guess->col];

    if (own_guess->result == RESULT_HIT) {
        opp_field->grid[own_guess->row][own_guess->col] = FIELD_SQUARE_HIT;
    } else if (own_guess->result == RESULT_MISS) {
        opp_field->grid[own_guess->row][own_guess->col] = FIELD_SQUARE_MISS;
    } else if (own_guess->result == RESULT_SMALL_BOAT_SUNK) {
        opp_field->smallBoatLives = 0;
        opp_field->grid[own_guess->row][own_guess->col] = FIELD_SQUARE_HIT;
    } else if (own_guess->result == RESULT_MEDIUM_BOAT_SUNK) {
        opp_field->mediumBoatLives = 0;
        opp_field->grid[own_guess->row][own_guess->col] = FIELD_SQUARE_HIT;
    } else if (own_guess->result == RESULT_LARGE_BOAT_SUNK) {
        opp_field->largeBoatLives = 0;
        opp_field->grid[own_guess->row][own_guess->col] = FIELD_SQUARE_HIT;
    } else if (own_guess->result == RESULT_HUGE_BOAT_SUNK) {
        opp_field->hugeBoatLives = 0;
        opp_field->grid[own_guess->row][own_guess->col] = FIELD_SQUARE_HIT;
    }
    return return_val;

}

/**
 * This function returns the alive states of all 4 boats as a 4-bit bitfield (stored as a uint8).
 * The boats are ordered from smallest to largest starting at the least-significant bit. So that:
 * 0b00001010 indicates that the small boat and large boat are sunk, while the medium and huge boat
 * are still alive. See the BoatStatus enum for the bit arrangement.
 * @param f The field to grab data from.
 * @return A 4-bit value with each bit corresponding to whether each ship is alive or not.
 */
uint8_t FieldGetBoatStates(const Field *f) {
    uint8_t result = 0;
    if (f->smallBoatLives > 0) {
        result += FIELD_BOAT_STATUS_SMALL;
    }
    if (f->mediumBoatLives > 0) {
        result += FIELD_BOAT_STATUS_MEDIUM;
    }
    if (f->largeBoatLives > 0) {
        result += FIELD_BOAT_STATUS_LARGE;
    }
    if (f->hugeBoatLives > 0) {
        result += FIELD_BOAT_STATUS_HUGE;
    }
    return result;
}

/**
 * This function is responsible for placing all four of the boats on a field.
 * 
 * @param f         //agent's own field, to be modified in place.
 * @return SUCCESS if all boats could be placed, STANDARD_ERROR otherwise.
 * 
 * This function should never fail when passed a properly initialized field!
 */
uint8_t FieldAIPlaceAllBoats(Field *own_field) {

    int boatsPlaced = 0;
    int result;
    int smallplaced = FALSE;
    int mediumplaced = FALSE;
    int largeplaced = FALSE;
    int hugeplaced = FALSE;
    while (boatsPlaced < 4) {

        if (smallplaced == FALSE) {
            result = FieldAddBoat(own_field, rand() % 5, rand() % 9, rand() % 2, FIELD_BOAT_TYPE_SMALL);
            if (result == SUCCESS) {
                boatsPlaced++;
                smallplaced = TRUE;
                own_field->smallBoatLives = FIELD_BOAT_SIZE_SMALL;
            }
        }
        if (mediumplaced == FALSE) {
            result = FieldAddBoat(own_field, rand() % 5, rand() % 9, rand() % 2, FIELD_BOAT_TYPE_MEDIUM);
            if (result == SUCCESS) {
                boatsPlaced++;
                mediumplaced = TRUE;
                own_field->mediumBoatLives = FIELD_BOAT_SIZE_MEDIUM;
            }
        }
        if (largeplaced == FALSE) {
            result = FieldAddBoat(own_field, rand() % 5, rand() % 9, rand() % 2, FIELD_BOAT_TYPE_LARGE);
            if (result == SUCCESS) {
                boatsPlaced++;
                largeplaced = TRUE;
                own_field->largeBoatLives = FIELD_BOAT_SIZE_LARGE;
            }
        }
        if (hugeplaced == FALSE) {
            result = FieldAddBoat(own_field, rand() % 5, rand() % 9, rand() % 2, FIELD_BOAT_TYPE_HUGE);
            if (result == SUCCESS) {
                boatsPlaced++;
                hugeplaced = TRUE;
                own_field->hugeBoatLives = FIELD_BOAT_SIZE_HUGE;
            }
        }
    }
    return SUCCESS;
}

/**
 * Given a field, decide the next guess.
 *
 * This function should not attempt to shoot a square which has already been guessed.
 *
 * You may wish to give this function static variables.  If so, that data should be
 * reset when FieldInit() is called.
 * 
 * @param f an opponent's field.
 * @return a GuessData struct whose row and col parameters are the coordinates of the guess.  The 
 *           result parameter is irrelevant.
 */
GuessData FieldAIDecideGuess(const Field *opp_field) {
    int undecided = TRUE;
    int col;
    int row;
    GuessData myGuess;
    while (undecided) {
        col = rand() % 9;
        row = rand() % 5;
        if (opp_field->grid[row][col] == FIELD_SQUARE_UNKNOWN) {
            undecided = FALSE;
            myGuess.col = col;
            myGuess.row = row;
        }
    }
    return myGuess;
}

/** 
 * For Extra Credit:  Make the two "AI" functions above 
 * smart enough to beat our AI in more than 55% of games.
 */


