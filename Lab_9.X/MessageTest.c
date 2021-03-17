#include "Message.h"
// Standard libraries
#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include "BOARD.h"

int main(){
    BOARD_Init();
    
    int testspassed=0;
    int totaltests=0;
    //Testing messagecalculatechecksum
    char* payload;
    uint8_t  result;
    printf("Testing Message_CalculateChecksum:\n");
    
    payload="shouldnt match any template";
    result=Message_CalculateChecksum(payload);
    
    if (result==38){
        printf("TEST 1 PASSED\n");
        testspassed++;
    }else{
        printf("TEST 1 FAILED\n");
    }
    totaltests++;
    
    payload="CHA,10";
    result=Message_CalculateChecksum(payload);
    
    if (result==103){
        printf("TEST 2 PASSED\n");
        testspassed++;
    }else{
        printf("TEST 2 FAILED\n");
    }
    totaltests++;
    
    payload="SHO,2,10";
    result=Message_CalculateChecksum(payload);
    if (result==103){
        printf("TEST 3 PASSED\n");
        testspassed++;
    }else{
        printf("TEST 3 FAILED\n");
    }
    totaltests++;
    
    payload="REV,7";
    result=Message_CalculateChecksum(payload);
    if (result==90){
        printf("TEST 4 PASSED\n");
        testspassed++;
    }else{
        printf("TEST 4 FAILED\n");
    }
    totaltests++;
    
    payload="ACC,6r";
    result=Message_CalculateChecksum(payload);
    if (result==41){
        printf("TEST 5 PASSED\n");
        testspassed++;
    }else{
        printf("TEST 5 FAILED\n");
    }
    totaltests++;
    
    payload="RES,3,,0";
    result=Message_CalculateChecksum(payload);
    if (result==107){
        printf("TEST 6 PASSED\n");
        testspassed++;
    }else{
        printf("TEST 6 FAILED\n");
    }
    totaltests++;
    printf("%d/%d TESTS PASSED\n", testspassed, totaltests);
    
    /****************************************************************************/
    //TESTING MESSAGE PARSE MESSAGE
    //Message_ParseMessage(const char* payload,const char* checksum_string, BB_Event * message_event);
    testspassed=0;
    totaltests=0;
    const char*  checksum_string;
    int result1;
    BB_Event message_event={};
    
    printf("Testing Message_ParseMessage:\n");
    
    //payload shouldnt match any template
    checksum_string="26";
    result1=Message_ParseMessage(payload,checksum_string, &message_event);
    if (result1==STANDARD_ERROR){
        printf("TEST 1 PASSED\n");
        testspassed++;
    }else{
        printf("TEST 1 FAILED\n");
    }
    totaltests++;
    
    //Payload shouldnt match checksum
    payload="REV,7";
    checksum_string="5a";
    result1=Message_ParseMessage(payload,checksum_string, &message_event);
    if (result1==STANDARD_ERROR){
        printf("TEST 2 PASSED\n");
        testspassed++;
    }else{
        printf("TEST 2 FAILED\n");
    }
    totaltests++;
    
    //should work fine
    payload="CHA,10";
    checksum_string="67";
    result1=Message_ParseMessage(payload,checksum_string, &message_event);
    if (result1==SUCCESS){
        printf("TEST 3 PASSED\n");
        testspassed++;
    }else{
        printf("TEST 3 FAILED\n");
    }
    totaltests++;
    
    //checksum not two characters long
    payload="ACC,6";
    checksum_string="2";
    result1=Message_ParseMessage(payload,checksum_string, &message_event);
    printf("Printing result %d\n", result1);
    if (result1==STANDARD_ERROR){
        printf("TEST 4 PASSED\n");
        testspassed++;
    }else{
        printf("TEST 4 FAILED\n");
    }
    totaltests++;
    
    printf("%d/%d TESTS PASSED\n", testspassed, totaltests);
    
    /**************************************************************************/
    //TESTING MESSAGE ENCODE
    //int Message_Encode(char *message_string, Message message_to_encode);
    int result2;
    Message message_to_encode={};
    char *message_string="$SHO,2,9*5F\n";
    printf("Testing Message_Encode:\n");
    
    //payload shouldnt match any template
    checksum_string="26";
    result2=Message_Encode(message_string, message_to_encode);
    if (result2==SUCCESS){
        printf("TEST 1 PASSED\n");
        testspassed++;
    }else{
        printf("TEST 1 FAILED\n");
    }
    totaltests++;
    return 0;
    BOARD_End();
}
