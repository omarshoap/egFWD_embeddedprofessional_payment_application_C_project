#pragma once
#ifndef app_H
#define app_H
/****************** libs *****************/
#include<stdio.h>
#include<stdint.h>
#include"terminal.h"
#include "../001_first_project/card.h"
/*****************************************/


void init_accountDB();
void transaction_DB(ST_cardData_t cardData, ST_terminalData_t termData, uint32_t sequence);

void appStart(void);


#endif
