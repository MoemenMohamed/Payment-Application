#include "card.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

EN_cardError_t getCardHolderName(ST_cardData_t *cardData)
{   
    printf("Enter the card holder's name (no spaces bet. names): ");
    scanf("%s",&cardData->cardHolderName);
    if( strlen(cardData->cardHolderName)>24 || strlen(cardData->cardHolderName)<15)
        return WRONG_NAME;
    else
        return OK;
}


EN_cardError_t getCardExpiryDate(ST_cardData_t *cardData)
{
    printf("Enter the card expiry date in MM/YY format: "); //ask the user for expiray date
    scanf("%s",&cardData->cardExpirationDate);                     // read the expiray date as array of char
                                
    if( strlen(cardData->cardExpirationDate)!=5 || (cardData->cardExpirationDate[0]-'0')>1 || (cardData->cardExpirationDate[1]-'0')>9 || cardData->cardExpirationDate[2] != '/' )  // error conditions
        return WRONG_EXP_DATE;
    else                                                         // approval condition
        return OK;
}


EN_cardError_t getCardPAN(ST_cardData_t *cardData)
{
    printf("Enter your PAN: ");                           //ask the user for PAN
    scanf("%s",&cardData->primaryAccountNumber);                 // read the PAN number
    if( strlen(cardData->primaryAccountNumber)>19 || strlen(cardData->primaryAccountNumber)<16 ) //error conditions
        return WRONG_PAN;
    else                                                       // approval condition
        return OK;
}


