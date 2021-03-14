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
#include "Negotiation.h"


int main(){
    NegotiationData mysecret= 3;
    NegotiationData theirsecret= 4;
    NegotiationData mycommitment= NegotiationHash(mysecret);
    NegotiationData theircommitment= (16%PUBLIC_KEY);
 
    printf("result of negociation hash: %d", mycommitment);
    NegotiationVerify(theirsecret, theircommitment);
    printf("negoviation verify: %d", NegotiationVerify(theirsecret, theircommitment));
    //NegotiateCoinFlip(mysecret, theirsecret);
    return 0;
}
