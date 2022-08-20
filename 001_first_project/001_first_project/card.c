/****************** libs *****************/
#include "../001_first_project/card.h"
#include <string.h>	// strlen, strcpy
#include <stdio.h>	// printf, scanf_s
#include <ctype.h>
#include <stdlib.h>
/****************************************/

/*
This function will ask for the cardholder's name and store it into card data.
Card holder name is 24 characters string max and 20 min.
If the cardholder name is NULL, less than 20 characters or more than 24 will return WRONG_NAME error, else return CARD_OK.
You should deliver a maximum 2min video to discuss your implementation and run different test cases on this function
*/
EN_cardError_t getCardHolderName(ST_cardData_t* cardData) {

    printf("Enter card holder name ");
    gets(cardData->cardHolderName);
    size_t length = strlen(cardData->cardHolderName);
    if (length > 24 || length < 20 || cardData->cardHolderName == NULL) {
        printf(" WRONG_NAME error\n");
        return WRONG_NAME;
    }
    else {
        printf(" complied_NAME\n");
        return CARD_OK;
    }
}
/*
This function will ask for the card expiry date and store it in card data.
Card expiry date is 5 characters string in the format "MM/YY", e.g "05/25".
If the card expiry date is NULL, less or more than 5 characters, or has the wrong format will return WRONG_EXP_DATE error, else return CARD_OK.
*/
EN_cardError_t getCardExpiryDate(ST_cardData_t* cardData) {


    printf("Enter card expiry date in the format MM/YY ");
    scanf("%s", &cardData->cardExpirationDate);
    size_t length = strlen(cardData->cardExpirationDate);
    if (length !=5 || cardData->cardExpirationDate == NULL || cardData->cardExpirationDate[2] !=  '/'  ) {
        printf(" WRONG_EXP_DATE error\n");
        return WRONG_EXP_DATE;
    }
    else {
        printf(" complied_EXP_DATE\n");
        return CARD_OK;

    }

}

/*
This function will ask for the card's Primary Account Number and store it in card data.
PAN is 20 characters alphanumeric only string 19 character max, and 16 character min.
If the PAN is NULL, less than 16 or more than 19 characters, will return WRONG_PAN error, else return CARD_OK.
*/
EN_cardError_t getCardPAN(ST_cardData_t* cardData) {

    printf("Enter card PAN number ");
    scanf("%s", &cardData->primaryAccountNumber);
    size_t length = strlen(cardData->primaryAccountNumber);
    if (length > 19 || length < 16 || cardData->primaryAccountNumber == NULL ) {
        printf(" WRONG_PAN error\n");
        return WRONG_PAN;
    }
    else {
        printf(" complied_PAN\n");
        return CARD_OK;

    }

}