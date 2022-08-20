/****************** libs *****************/
#include<stdio.h>
#include<stdint.h>
#include "../001_first_project/card.h"
#include"terminal.h"
#include"server.h"
#include"string.h"
/*****************************************/


// accounts data base
ST_accountsDB_t accounts[MAX_AVILABLE];
// transaction data base
ST_transaction_t tran[MAX_AVILABLE];
// global vars
int i, seq;


/***************************************************/
/*
This function will take all transaction data and validate its data.
It checks the account details and amount availability.
If the account does not exist return DECLINED_STOLEN_CARD, if the amount is not available will return DECLINED_INSUFFECIENT_FUND, if a transaction can't be saved will return INTERNAL_SERVER_ERROR and will not save the transaction, else returns APPROVED.
It will update the database with the new balance.
*/
EN_transState_t recieveTransactionData(ST_transaction_t* transData) {
    if (isValidAccount(&transData->cardHolderData)) {
        transData->transState = DECLINED_STOLEN_CARD;
        return DECLINED_STOLEN_CARD;

    }
    else if (isAmountAvailable(&transData->terminalData)) {
        transData->transState = DECLINED_INSUFFECIENT_FUND;
        return DECLINED_INSUFFECIENT_FUND;
    }
    else if (saveTransaction(transData)) {
        transData->transState = INTERNAL_SERVER_ERROR;
        return INTERNAL_SERVER_ERROR;
    }
    printf("/////////////////////////////////////////////////\n");
    printf("balance before transaction = %f " , accounts[i].balance);
    printf("\n withdraw amount  = %f ", transData->terminalData.transAmount);
    accounts[i].balance -= transData->terminalData.transAmount; 
    printf("\n balance after transaction = %f ", accounts[i].balance);
    printf("\n /////////////////////////////////////////////////");
    return APPROVED;

}
/*
This function will take card data and validate these data.
It checks if the PAN exists or not in the server's database.
If the PAN doesn't exist will return DECLINED_STOLEN_CARD, else will return SERVER_OK
*/
EN_serverError_t isValidAccount(ST_cardData_t* cardData) {
    for (i = 0; i < 2; i++) {
        if (!strcmp((char*)cardData->primaryAccountNumber, (char*)accounts[i].primaryAccountNumber)) {
            return SERVER_OK;
        }
    }
    printf("Stolen Card !!\n");
    return DECLINED_STOLEN_CARD;
}
/*
This function will take terminal data and validate these data.
It checks if the transaction's amount is available or not.
If the transaction amount is greater than the balance in the database will return LOW_BALANCE, else will return SERVER_OK
*/
EN_serverError_t isAmountAvailable(ST_terminalData_t* termData) {
    if (termData->transAmount > accounts[i].balance) {
        return LOW_BALANCE;
    }

    return SERVER_OK;
}
/*
This function will take all transaction data into the transactions database.
It gives a sequence number to a transaction, this number is incremented once a transaction is processed into the server.
If saves any type of transaction, APPROVED or DECLINED, with the specific reason for declining/transaction state.
If transaction can't be saved will return SAVING_FAILED, else will return SERVER_OK
*/
EN_serverError_t saveTransaction(ST_transaction_t* transData) {
    transData->transactionSequenceNumber = seq;
    seq++;
    if (transData->transState == DECLINED_STOLEN_CARD || transData->transState == DECLINED_INSUFFECIENT_FUND) {

        return SAVING_FAILED;
    }
    return SERVER_OK;
}


EN_serverError_t getTransaction(uint32_t transactionSequenceNumber, ST_transaction_t* transData) {
  //  ???????????????????????? not found in rubric 
}

/***************************************************/