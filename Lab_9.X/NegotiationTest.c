// Standard libraries
#include <stdio.h>
#include <string.h>
#include <stdint.h>

//CMPE13 Support Library
#include "BOARD.h"

// Microchip libraries
#include <xc.h>
#include <sys/attribs.h>

//CE13 standard libraries:
#include "Buttons.h"
#include "Uart1.h"
#include "Oled.h"

// Battleboats Libraries:
#include "BattleBoats.h"
#include "Message.h"


int main(){
    NegotiationData mysecret= 3;
    NegociationData thiersecret= 4;
    NegociationData mycommitment= NegotiationHash(mysecret);
    NegociationData theircommitment= (16%PUBLIC_KEY);
 
    printf("result of negociation hash: %d", mycommitment);
    NegotiationVerify(theirsecret, theircommitment);
    printf("negoviation verify: %d", NegotiationVerify(theirsecret, theircommitment);)
    //NegotiateCoinFlip(mysecret, theirsecret);
}
