#include "Field.h"
// Standard libraries
#include <stdio.h>
#include <string.h>
#include "BOARD.h"
int main(){
    BOARD_Init();
    
    Field own_field={};
    Field opp_field={};
    printf("Testing init:\n");
    FieldInit(&own_field, &opp_field);
    /*FieldPrint_UART(&own_field, &opp_field);
    printf("Testing addboat:\n");
    FieldAddBoat(&own_field, 5, 4, FIELD_DIR_EAST, FIELD_BOAT_TYPE_HUGE);
    FieldPrint_UART(&own_field, &opp_field);*/
    printf("Testing PlaceAllBoats:\n");
    FieldAIPlaceAllBoats(&own_field);
    FieldPrint_UART(&own_field, &opp_field);
    return 0;
    
    BOARD_End();
    
    //return 0;
}
