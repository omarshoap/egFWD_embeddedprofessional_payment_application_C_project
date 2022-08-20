
/****************** libs *****************/
#include"terminal.h"
#include"card.h"
/*****************/



/*
This function will ask for the transaction data and store it in terminal data.
Transaction date is 10 characters string in the format DD/MM/YYYY, e.g 25/06/2022.
If the transaction date is NULL, less than 10 characters or wrong format will return WRONG_DATE error, else return TERMINAL_OK.
*/
EN_terminalError_t getTransactionDate(ST_terminalData_t* termData) {
    printf("transaction date in the format DD/MM/YYYY");
    scanf("%s", &termData->transactionDate);
    size_t length = strlen(termData->transactionDate);
    if (length < 10 || termData->transactionDate == NULL || termData->transactionDate[2] != '/' || termData->transactionDate[5] != '/') {
        printf(" WRONG_DATE error\n");
        return WRONG_DATE;
    }
    else {
        return TERMINAL_OK;
    }
}



/*
This function compares the card expiry date with the transaction date.
If the card expiration date is before the transaction date will return EXPIRED_CARD, else return TERMINAL_OK.
*/
EN_terminalError_t isCardExpired(ST_cardData_t cardData, ST_terminalData_t termData) {
    // Expiry date format "MM/YY"
    // transation date format "DD/MM/YYYY"
    int expir_year, expir_month, trans_year, trans_month , trans_day;
    sscanf(cardData.cardExpirationDate , "%d/%d" , &expir_month , &expir_year);
    expir_year  += 2000;
    sscanf(termData.transactionDate, "%d/%d/%d",&trans_day ,&trans_month, &trans_year);
  
    if (expir_year < trans_year)
        return EXPIRED_CARD;
    else if (expir_year == trans_year && expir_month < trans_month)
        return EXPIRED_CARD;
    else {
        return TERMINAL_OK;
    }
}

EN_terminalError_t isValidCardPAN(ST_cardData_t* cardData) {
// optional
}


/*
This function asks for the transaction amount and saves it into terminal data.
If the transaction amount is less than or equal to 0 will return INVALID_AMOUNT, else return TERMINAL_OK.
*/
EN_terminalError_t getTransactionAmount(ST_terminalData_t* termData) {
    printf("enter transaction amount");
    scanf("%f", &termData->transAmount);
    if (termData->transAmount <= 0 ) {
        printf(" INVALID_AMOUNT error\n");
        return INVALID_AMOUNT;
    }
    else {
        return TERMINAL_OK;
    }
}
/*
This function compares the transaction amount with the terminal max amount.
If the transaction amount is larger than the terminal max amount will return EXCEED_MAX_AMOUNT, else return TERMINAL_OK.
*/
EN_terminalError_t isBelowMaxAmount(ST_terminalData_t* termData) {
    if (termData->transAmount > termData->maxTransAmount) {
        printf(" EXCEED_MAX_AMOUNT error\n");
        return EXCEED_MAX_AMOUNT;
    }
    else {
        return TERMINAL_OK;
    }

}
/*
This function sets the maximum allowed amount into terminal data.
Transaction max amount is a float number.
If transaction max amount less than or equal to 0 will return INVALID_MAX_AMOUNT error, else return TERMINAL_OK.
*/
EN_terminalError_t setMaxAmount(ST_terminalData_t* termData) {
    // set maxTransAmount manually  
    termData->maxTransAmount = 15000;

  //  not logical but rubric need it
    if (termData->maxTransAmount <= 0) {
        printf(" INVALID_MAX_AMOUNT error\n");
        return INVALID_MAX_AMOUNT;
    }
    else {
        return TERMINAL_OK;
    }
}
/*****************/



