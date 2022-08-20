#pragma warning(disable : 4996)
/****************** libs *****************/


#include<stdio.h>
#include "app.h"
#include "server.h"

int main() {
	/*************/
	//appStart();
	/*************/

	









	
//****************************** card test ******************************//
	//getCardHolderName();*****************************
	/*	// for test purpose
	
	ST_cardData_t testperson;
	// 
	if (getCardHolderName(&testperson) == WRONG_NAME) {
		printf(" less than 20 or more 24 character \n");
	}
	else {
		printf(" complied name \n");
	}
						// omaromar
						// omaromaromaromaromaro
						// omaromaromaromaromaromaro
*/
	//getCardExpiryDate();*****************************
	/*	// for test purpose 
	ST_cardData_t testperson;
	// 
	getCardExpiryDate(&testperson);
	
						// no /
						// > 5  or  < 5
						// null
						// 05/25
*/
	//getCardPAN();*****************************
	/*	// for test purpose 
	ST_cardData_t testperson;
	//
	if (getCardPAN(&testperson) == WRONG_PAN) {
		printf(" wrong pan \n");
	}
	else {
		printf(" valid  pan  \n");
	}
						// 111112222233333
						// 1111122222333334
						// 11111222223333344444
	*/
//****************************** terminal test ******************************//
	//getTransactionDate();*****************************
/*
    ST_transaction_t transaction_test = { 0 };
	getTransactionDate(&transaction_test.terminalData);
						// <10
						// null
						// [2]!= /
						// [5]!= /
						// 22/07/2022
*/
	
	//isCardExpired();*****************************
		// for test purpose 
	ST_terminalData_t atm;
	ST_cardData_t testperson;
	getCardExpiryDate(&testperson);
	getTransactionDate(&atm);
	//
	if (isCardExpired(testperson, atm)) {
		printf(" expired card \n");
	}
	else {
		printf(" valid card \n");
	}
						// 05/21 ,  28/07/2022
						// 05/22 ,  28/07/2022
						// 05/25 ,  28/07/2022
	
	//getTransactionAmount();*****************************
	/*	// for test purpose 
	ST_terminalData_t atm;
	//
	if (getTransactionAmount(&atm)) {
		printf(" invalid amount \n");
	}
	else {
		printf(" valid amount \n");
	}
						// -5000
						// 5000
*/
	//isBelowMaxAmount();*****************************
	/*
    ST_terminalData_t atm;
	getTransactionAmount(&atm);
	setMaxAmount(&atm);
	if (isBelowMaxAmount(&atm)) {
		printf(" exceed max \n");
	}
	else {
		printf(" not exceed max \n");
	}
						// 20000
						// 5000
	*/

//****************************** server test ******************************//
	//isValidAccount();*****************************
	/*
    init_accountDB();
	ST_cardData_t testperson;
	getCardPAN(&testperson);
	if (isValidAccount(&testperson)) {
		printf(" invalid account  \n");
	}
	else {
		printf(" valid account \n");
	}
						// 2000000000000000
						// 1111111111111111

	*/
	//isAmountAvailable();*****************************
    //recieveTransactionData();*****************************
	//saveTransaction();*****************************


//****************************** app test ******************************//
	//approvedTransaction();*****************************
	//exceedAmount();*****************************
	//insufficientFund();*****************************
	//expiredCard();*****************************
	//invalidUser();*****************************


	

	int x = getchar();



}