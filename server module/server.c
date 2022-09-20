#include "server.h"
#include <stdlib.h>


ST_accountsDB_t arr1[255] = {2000,"1258745953201254963",2135,"452013698541785236"};
ST_transaction  arr2[255]={0};

EN_transState_t recieveTransactionData(ST_transaction *transData,ST_cardData_t *cardata,ST_terminalData_t *termdata)
{  
    int i,k;
    for(i=0;i<2;i++)
    {   int value=strcmp(cardata->primaryAccountNumber,arr1[i].primaryAccountNumber);
        if( value == 0)
           {  
            if(termdata->transAmount > arr1[i].balance)
                {return DECLINED_INSUFFECIENT_FUND;
                break;}
            else
                {arr1[i].balance -=  termdata->transAmount;
                 printf("Your new balance is %f\n",arr1[i].balance);
                return APPROVED;}
            }
       
    }
    return ACCOUNT_NOT_FOUND;
}

EN_serverError_t saveTransaction(ST_transaction *transData)
{   int j;
    for(j=0;j<256;j++)
    {   arr2[j].cardHolderData = transData->cardHolderData;
        arr2[j].terminalData = transData->terminalData;
        arr2[j].transactionSequenceNumber++;
        return APPROVED;
    }
    return SAVING_FAILED;
}


