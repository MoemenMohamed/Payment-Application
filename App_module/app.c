#include <stdio.h>
#include "app.h"
#include "..\Server Module\server.h"
ST_terminalData_t trans1;
ST_cardData_t card_1;
ST_transaction data_1;


void AppStart()
{
    int flags[]={1,1,1,1,1,1,1};

    while(1)
    {   flags[0] = getCardHolderName(&card_1); // get card holder name
            if(flags[0] !=0)
                {printf("ERROR WRONG_NAME\n");
                break;}
        flags[1] = getCardExpiryDate(&card_1); // get card expiry date
            if(flags[1] !=0)
                {printf("ERROR WRONG_EXP_DATE\n");
                break;}
        flags[2]= getCardPAN(&card_1);        // get card pan
            if(flags[2] !=0)
                {printf("ERROR WRONG_PAN\n");
                break;}
        getTransactionDate(&trans1);          // get transaction date
        printf("%s\n",trans1.transactionDate);
        flags[3] = isCardExpired(card_1,trans1);  //check if the card is expired
            if(flags[3] !=0)
                {printf("ERROR EXPIRED_CARD\n",flags[3]);
                break;}
        flags[4]= getTransactionAmount(&trans1);  //check if transaction amount is valid
            if(flags[4] !=0)
                {printf("ERROR INVALID_AMOUNT\n",flags[4]);
                break;}
        setMaxAmount(&trans1);                     //set max amout to 5000
        flags[5] = isBelowMaxAmount(&trans1);      //check if transaction amount is more than max
            if(flags[5] !=0)
                {printf("ERROR EXCEED_MAX_AMOUNT\n",flags[5]);
                break;}
        printf("Transaction amount is %f\n",trans1.transAmount);
        flags[6] = recieveTransactionData(&data_1,&card_1,&trans1); // check if pan available in database and trans amount
            if(flags[6] !=0)                                        //is less than or equal your balance
                {
                    if(flags[6] == 1 )
                    {   printf("DECLINED_INSUFFECIENT_FUND\n");
                        break;}
                    else
                        printf("ACCOUNT_NOT_FOUND\n");
                }
            else
                    printf("TRANSACTION IS APPROVED\n");

        flags[7] = saveTransaction(&data_1);                       // save transaction data in database
            if(flags[7] !=1 )
                printf("TRANSACTION IS SAVED SUCCESFULLY\n");
            else
                printf("TRANSACTION SAVING_FAILED\n");
        
    }
}
