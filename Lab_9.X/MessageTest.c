#include "Message.h"
// Standard libraries
#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include "BOARD.h"

int main(){
    BOARD_Init();
    printf("Welcome to NABARRAZ'S MessageTest.  Compiled on %s %s\n", __DATE__, __TIME__);
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
    testspassed=0;
    totaltests=0;
    int result2;
    char message_string[MESSAGE_MAX_LEN];
    
    printf("Testing Message_Encode:\n");
    //"$SHO,2,9*5F\n"
    Message message_to_encode1={MESSAGE_SHO, 2,9};
    result2=Message_Encode(message_string, message_to_encode1);
    char result_str1[MESSAGE_MAX_LEN]="$SHO,2,9*5F\n";
    if (result2==strlen(result_str1) && !strcmp(message_string, result_str1) ){
        printf("TEST 1 PASSED\n");
        testspassed++;
    }else{
        printf("TEST 1 FAILED\n");
    }
    totaltests++;
    
    //CHA,10
    Message message_to_encode2={MESSAGE_CHA, 10};
    result2=Message_Encode(message_string, message_to_encode2);
    char result_str2[MESSAGE_MAX_LEN]="$CHA,10*67\n";
    if (result2==strlen(result_str2) && !strcmp(message_string, result_str2) ){
        printf("TEST 2 PASSED\n");
        testspassed++;
    }else{
        printf("TEST 2 FAILED\n");
    }
    totaltests++;
    
    Message message_to_encode3={MESSAGE_REV, 7};
    result2=Message_Encode(message_string, message_to_encode3);
    char result_str3[MESSAGE_MAX_LEN]="$REV,7*5A\n";
    if (result2==strlen(result_str3) && !strcmp(message_string, result_str3) ){
        printf("TEST 3 PASSED\n");
        testspassed++;
    }else{
        printf("TEST 3 FAILED\n");
    }
    totaltests++;
    
    printf("%d/%d TESTS PASSED\n", testspassed, totaltests);
    
    testspassed=0;
    totaltests=0;
    /**************************************************************************/
    //Testing MessageDecode
    
    printf("Testing Message_CalculateChecksum:\n");
    
    unsigned char char_in;
    BB_EventType expected_type;
    uint16_t expected_param0;
    
    //$CHA,10*67\n
    char_in='$';
    expected_type=BB_EVENT_CHA_RECEIVED;
    expected_param0=10;
    
    BB_Event decoded_message_event1={};
    result=Message_Decode(char_in, &decoded_message_event1);
    if (result==SUCCESS){
        printf("TEST 1 PASSED\n");
        testspassed++;
    }else{
        printf("TEST 1 FAILED\n");
    }
    totaltests++;
    
    char_in='C';
    expected_type=BB_EVENT_CHA_RECEIVED;
    //expected_param0=10;
    
    result=Message_Decode(char_in, &decoded_message_event1);
    if (result==SUCCESS){
        printf("TEST 2 PASSED\n");
        testspassed++;
    }else{
        printf("TEST 2 FAILED\n");
    }
    totaltests++;
    
    char_in='H';
    result=Message_Decode(char_in, &decoded_message_event1);
    if (result==SUCCESS){
        printf("TEST 3 PASSED\n");
        testspassed++;
    }else{
        printf("TEST 3 FAILED\n");
    }
    totaltests++;
    
    char_in='A';
    result=Message_Decode(char_in, &decoded_message_event1);
    if (result==SUCCESS){
        printf("TEST 4 PASSED\n");
        testspassed++;
    }else{
        printf("TEST 4 FAILED\n");
    }
    totaltests++;
    
    char_in=',';
    result=Message_Decode(char_in, &decoded_message_event1);
    if (result==SUCCESS){
        printf("TEST 5 PASSED\n");
        testspassed++;
    }else{
        printf("TEST 5 FAILED\n");
    }
    totaltests++;
    
    char_in='1';
    result=Message_Decode(char_in, &decoded_message_event1);
    if (result==SUCCESS){
        printf("TEST 6 PASSED\n");
        testspassed++;
    }else{
        printf("TEST 6 FAILED\n");
    }
    totaltests++;
    
    char_in='0';
    result=Message_Decode(char_in, &decoded_message_event1);
    if (result==SUCCESS){
        printf("TEST 7 PASSED\n");
        testspassed++;
    }else{
        printf("TEST 7 FAILED\n");
    }
    totaltests++;
    
    char_in='*';
    result=Message_Decode(char_in, &decoded_message_event1);
    if (result==SUCCESS){
        printf("TEST 8 PASSED\n");
        testspassed++;
    }else{
        printf("TEST 8 FAILED\n");
    }
    totaltests++;
    
    char_in='6';
    result=Message_Decode(char_in, &decoded_message_event1);
    if (result==SUCCESS){
        printf("TEST 9 PASSED\n");
        testspassed++;
    }else{
        printf("TEST 9 FAILED\n");
    }
    totaltests++;
    
    char_in='7';
    result=Message_Decode(char_in, &decoded_message_event1);
    if (result==SUCCESS){
        printf("TEST 10 PASSED\n");
        testspassed++;
    }else{
        printf("TEST 10 FAILED\n");
    }
    
    char_in='\n';
    result=Message_Decode(char_in, &decoded_message_event1);
    if (result==SUCCESS && (decoded_message_event1.type==expected_type) && (decoded_message_event1.param0==expected_param0)){
        printf("TEST 11 PASSED\n");
        testspassed++;
    }else{
        printf("TEST 11 FAILED\n");
    }
    
    totaltests++;
    return 0;
    BOARD_End();
}
