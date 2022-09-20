#include "terminal.h"


void getTransactionDate(ST_terminalData_t *termData)
{  
    struct tm* ptr;
    time_t t;
    t = time(NULL);
    ptr = localtime(&t);
    termData->transactionDate[0] = asctime(ptr)[8];
    termData->transactionDate[1] = asctime(ptr)[9];
    termData->transactionDate[2] = '/';
    termData->transactionDate[3] = '0';
    termData->transactionDate[4] = '8';
    termData->transactionDate[5] = '/';
    termData->transactionDate[6] = asctime(ptr)[20];
    termData->transactionDate[7] = asctime(ptr)[21];
    termData->transactionDate[8] = asctime(ptr)[22];
    termData->transactionDate[9] = asctime(ptr)[23];
    
}

EN_terminalError_t isCardExpired(ST_cardData_t cardData, ST_terminalData_t termData)
{  
    if (termData.transactionDate[8] > cardData.cardExpirationDate[3])            //year check
            return EXPIRED_CARD;
    else if (termData.transactionDate[8] == cardData.cardExpirationDate[3])      //year check
        {if(termData.transactionDate[9] > cardData.cardExpirationDate[4])
            return EXPIRED_CARD;
        else if (termData.transactionDate[9] == cardData.cardExpirationDate[4])
            {if(termData.transactionDate[3] > cardData.cardExpirationDate[0])             //month check
                    return EXPIRED_CARD;
            else if (termData.transactionDate[3] == cardData.cardExpirationDate[0])    //month check
                {if(termData.transactionDate[4] > cardData.cardExpirationDate[1])
                    return EXPIRED_CARD;}
            else if (termData.transactionDate[8] > cardData.cardExpirationDate[3])       //year check
                    return EXPIRED_CARD;
            else if (termData.transactionDate[8] == cardData.cardExpirationDate[3])      //year check
                {if(termData.transactionDate[9] > cardData.cardExpirationDate[4])
                    return EXPIRED_CARD;}
            }
        }
        return OKK;
}

EN_terminalError_t getTransactionAmount(ST_terminalData_t *termData)
{
    printf("please enter the transaction amount: ");
    scanf("%f",&termData->transAmount);
    if(termData->transAmount <= 0.0)
        return INVALID_AMOUNT;
    else
        return OKK;
}

EN_terminalError_t isBelowMaxAmount(ST_terminalData_t *termData)
{
    if(termData->transAmount > termData->maxTransAmount)
        return EXCEED_MAX_AMOUNT;
    else
        return OKK;
}

EN_terminalError_t setMaxAmount(ST_terminalData_t *termData)
{
    termData->maxTransAmount = 5000;
    if(termData->maxTransAmount <= 0.0)
        return INVALID_MAX_AMOUNT;
    else
        return OKK;

}


