#include "Message.h"
// Standard libraries
#include <stdio.h>
#include <string.h>
#include <stdint.h>

int main(){
    BOARD_Init();
    
    

    BOARD_End();
    int result1;
    int result2;
    int result3;
    int result4;
    //Testing messagecalculatechecksum
    char* payload="shouldnt match any template"
    Message_CalculateChecksum(payload);
    printf()
    return 0;
}
