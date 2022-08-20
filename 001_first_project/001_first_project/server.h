#pragma once
#ifndef server_H
#define server_H
/****************** libs *****************/

#include<stdio.h>
#include<stdint.h>
#include"terminal.h"
#include "../001_first_project/card.h"
/*****************************************/


/**************************************************************************************************/
// ***** typedefs ****
typedef unsigned int uint32_t;
typedef unsigned char uint8_t;
// ***** macros ****
#define MAX_AVILABLE 255
/**************************************************************************************************/


/************ struct and enum ************/
typedef enum EN_transState_t
{
	APPROVED, DECLINED_INSUFFECIENT_FUND, DECLINED_STOLEN_CARD, INTERNAL_SERVER_ERROR
}EN_transState_t;

typedef enum EN_serverError_t
{
	SERVER_OK, SAVING_FAILED, TRANSACTION_NOT_FOUND, ACCOUNT_NOT_FOUND, LOW_BALANCE
}EN_serverError_t;

typedef struct ST_accountsDB_t
{
	float balance;
	uint8_t primaryAccountNumber[20];
}ST_accountsDB_t;

typedef struct ST_transaction_t
{
	ST_cardData_t cardHolderData;
	ST_terminalData_t terminalData;
	EN_transState_t transState;
	uint32_t transactionSequenceNumber;
}ST_transaction_t;
/*****************************************/




/*********** function prototype **********/

EN_transState_t recieveTransactionData(ST_transaction_t* transData);
EN_serverError_t isValidAccount(ST_cardData_t* cardData);
EN_serverError_t isAmountAvailable(ST_terminalData_t* termData);
EN_serverError_t saveTransaction(ST_transaction_t* transData);
EN_serverError_t getTransaction(uint32_t transactionSequenceNumber, ST_transaction_t* transData);
/*****************************************/






#endif
