/****************** libs *****************/
#include<stdio.h>
#include<stdint.h>
#include"card.h"
#include"terminal.h"
#include"server.h"
#include"string.h"
#include"app.h"
/*****************************************/


 
// ***** global variable ****//
// accounts data base
extern ST_accountsDB_t accounts[MAX_AVILABLE];
// transaction data base
extern ST_transaction_t tran[MAX_AVILABLE];
//
extern int i, seq;
//


/*
Please refere to the flow chart attached under the instructions video in order to implement this application.
*/

// appstart function it's a root of a project 
void appStart(void) {

	init_accountDB();

	ST_transaction_t transaction = { 0 };

	/***************************************** card info ******************************************/
	getCardHolderName(&transaction.cardHolderData);
	getCardExpiryDate(&transaction.cardHolderData);
	getCardPAN(&transaction.cardHolderData);

	 
	/***************************************** terminal ******************************************/
	EN_terminalError_t tError = TERMINAL_OK;

	tError = isValidCardPAN(&transaction.cardHolderData);
	if (tError == INVALID_CARD) {
		printf("Invalid card.\n");
		return;
	}
	//
	setMaxAmount(&transaction.terminalData);
	//
	getTransactionDate(&transaction.terminalData);
	tError = isCardExpired(transaction.cardHolderData, transaction.terminalData);

	if (tError == EXPIRED_CARD) {
		printf("Expired card!\n");
		return;
	}

	getTransactionAmount(&transaction.terminalData);
	tError = isBelowMaxAmount(&transaction.terminalData);
	if (tError == EXCEED_MAX_AMOUNT) {
		printf("It is currently not possible to withdraw this amount.\n");
		return;
	}


	/***************************************** server ******************************************/

	if (isValidAccount(&transaction.cardHolderData) != SERVER_OK) {
		printf("Invalid account.\n");
		return;
	}

	if (isAmountAvailable(&transaction.terminalData) != SERVER_OK) {
		printf("Not enough money!\n");
		return;
	}

	if (recieveTransactionData(&transaction) != SERVER_OK) {
		printf("Something went wrong, the transaction wasn't completed.");
		return;
	}

	printf("\nTransaction completed successfully!\nThanks for using our bank.\n");


	return;

}

// function to fill global array of accounts
void init_accountDB() {
	accounts[0].balance = 10000;
	strcpy((char*)accounts[0].primaryAccountNumber, "1111111111111111");
	accounts[1].balance = 20000;
	strcpy((char*)accounts[1].primaryAccountNumber, "2222222222222222");
}

// function to assign data to transaction
void transaction_DB(ST_cardData_t cardData, ST_terminalData_t termData, uint32_t sequence) {
	tran[sequence].cardHolderData = cardData;
	tran[sequence].terminalData = termData;
}

