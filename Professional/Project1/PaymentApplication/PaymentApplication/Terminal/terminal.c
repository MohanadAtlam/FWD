#define _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_DEPRECATE  
#define _CRT_NONSTDC_NO_DEPRECATE

#include<stdio.h>
#include <stdlib.h>

#include"STD_TYPES_FWD.h"
#include"../Card/card.h"
#include"terminal.h"


EN_terminalError_t getTransactionDate(ST_terminalData_t* termData)
{
	printf("\nEnter the transaction date in the form of DD/MM/YYYY : ");
	gets(termData->transactionDate);
	uint8_t counter = 0;
	while (termData->transactionDate[counter] != 0)
	{
		counter++;
	}
	if (counter != 10 || termData->transactionDate[0] == 0)
	{
		printf("\nWrong date entered\n");
		return WRONG_DATE;
	}
	else { return TERMINAL_OK; }
}

EN_terminalError_t isCardExpired(ST_cardData_t* cardData, ST_terminalData_t* termData)
{
	uint8_t card_EXPmonth = atoi(cardData->cardExpirationDate);
	uint8_t card_EXPyear = atoi(&(cardData->cardExpirationDate[3]));

	uint8_t transaction_month = atoi(&(termData->transactionDate[3]));
	uint8_t transaction_year = atoi(&(termData->transactionDate[6]))-2000;

	if (transaction_year < card_EXPyear)
	{
		printf("Card is still available\n");
		return TERMINAL_OK;
	}
	else
	{
		if (transaction_month <= card_EXPmonth)
		{
			printf("Card is still available\n");
			return TERMINAL_OK;
		}
		else
		{
			printf("Card expired\n");
			return EXPIRED_CARD;
		}
	}
}

EN_terminalError_t getTransactionAmount(ST_terminalData_t* termData)
{
	float transAmount;
	printf("\nEnter the transaction amout : ");
	scanf("%f", &transAmount);
	if (transAmount <= 0)
	{
		printf("Invalid Amount Entered\n");
		return INVALID_AMOUNT;
	}
	else
	{
		termData->transAmount = transAmount;
		return TERMINAL_OK;
	}
}

EN_terminalError_t isBelowMaxAmount(ST_terminalData_t* termData)
{
	if (termData->transAmount > termData->maxTransAmount)
	{
		printf("You Exceeded the max amount possible for transaction\n");
		return EXCEED_MAX_AMOUNT;
	}
	else 
	{ 
		printf("Transaction amount is below the max amount \n");
		return TERMINAL_OK;
	}
}

EN_terminalError_t setMaxAmount(ST_terminalData_t* termData, float maxAmount)
{
	if(maxAmount<=0)
	{
		return INVALID_MAX_AMOUNT;
	}
	else 
	{ 
		termData->maxTransAmount = maxAmount;
		return TERMINAL_OK;
	}
}


// test functions 
void getTransactionDateTest(void)
{
	uint8_t date1[] = "11/11/2022";
	uint8_t date2[] = "11/11/20";
	uint8_t date3[] = "11/11/2022/10";
	uint8_t date4[10] = { 0 };

	printf("\nTester name: Mohanad Magdy \n");
	printf("Function Name: getTransactionDate \n");
	printf("Test Case 1: right input data\n");
	printf("Input Data: 11/11/2022\n");
	printf("Expected Result: Valid date entered\n");
	printf("Actual Result: ");
	uint8_t counter = 0;
	while (date1[counter] != 0)
	{
		counter++;
	}
	if (counter != 10 || date1[0] == 0)
	{
		printf("Wrong date entered\n");
	}
	else 
	{ 
		printf("Valid date entered\n");
	}

	printf("\nTest Case 2: too short input data\n");
	printf("Input Data: 11/11/20\n");
	printf("Expected Result: Wrong date entered\n");
	printf("Actual Result: ");
	counter = 0;
	while (date2[counter] != 0)
	{
		counter++;
	}
	if (counter != 10 || date2[0] == 0)
	{
		printf("Wrong date entered\n");
	}
	else
	{
		printf("Valid date entered\n");;
	}

	printf("\nTest Case 3: too long input data\n");
	printf("Input Data: 11/11/2022/10\n");
	printf("Expected Result: Wrong date entered\n");
	printf("Actual Result: ");
	counter = 0;
	while (date3[counter] != 0)
	{
		counter++;
	}
	if (counter != 10 || date3[0] == 0)
	{
		printf("Wrong date entered\n");
	}
	else
	{
		printf("Valid date entered\n");
	}

	printf("\nTest Case 4: 0 as an input data\n");
	printf("Input Data: 0\n");
	printf("Expected Result: Wrong date entered\n");
	printf("Actual Result: ");
	counter = 0;
	while (date4[counter] != 0)
	{
		counter++;
	}
	if (counter != 10 || date4[0] == 0)
	{
		printf("Wrong date entered\n");
	}
	else
	{
		printf("Valid date entered\n");
	}
}


void isCardExpiredTest(void)
{
	uint8_t card_EXPmonth = 12;
	uint8_t card_EXPyear = 22;

	uint8_t transaction_month = 11;
	uint8_t transaction_year = 2022 - 2000;

	printf("\nTester name: Mohanad Magdy \n");
	printf("Function Name: isCardExpiredTest \n");
	printf("Test Case 1: right input data\n");
	printf("Input Data: day of transaction: DD/11/2022 ::: card exp date: 12/22 \n");
	printf("Expected Result: Card is still available\n");
	printf("Actual Result: ");

	if (transaction_year <= card_EXPyear)
	{
		if (transaction_month <= card_EXPmonth)
		{
			printf("Card is still available\n");
		}
		else
		{
			printf("Card expired\n");
		}
	}
	else
	{
		printf("Card expired\n");
	}

	printf("\nTest Case 2: expired date input\n");
	printf("Input Data: day of transaction: DD/11/2022 ::: card exp date: 12/21 \n");
	printf("Expected Result: Card expired\n");
	printf("Actual Result: ");

	if (transaction_year <= card_EXPyear-1)
	{
		if (transaction_month <= card_EXPmonth)
		{
			printf("Card is still available\n");
		}
		else
		{
			printf("Card expired\n");
		}
	}
	else
	{
		printf("Card expired\n");
	}
}

void getTransactionAmountTest(void)
{
	float transAmount1 =1000.0;
	float transAmount2 = -1000.0;

	printf("\nTester name: Mohanad Magdy \n");
	printf("Function Name: getTransactionAmount \n");
	printf("Test Case 1: right input data\n");
	printf("Input Data: 1000.0 \n");
	printf("Expected Result: Valid Amount Entered\n");
	printf("Actual Result: ");

	if (transAmount1 <= 0)
	{
		printf("Invalid Amount Entered\n");
	}
	else
	{
		printf("Valid Amount Entered\n");
	}

	printf("\nTest Case 2: right input data\n");
	printf("Input Data: day of transaction: -1000 \n");
	printf("Expected Result: Invalid Amount Entered\n");
	printf("Actual Result: ");

	if (transAmount2 <= 0)
	{
		printf("Invalid Amount Entered\n");
	}
	else
	{
		printf("Valid Amount Entered\n");
	}
}

void isBelowMaxAmountTest(void)
{
	float transAmount1 = 1000;
	float transAmount2 = 10000;
	float maxTransAmount = 3000;

	printf("\nTester name: Mohanad Magdy \n");
	printf("Function Name: isBelowMaxAmount \n");
	printf("Test Case 1: right input data\n");
	printf("Input Data: trans amoun = 1000 ... maxtransamount = 3000 \n");
	printf("Expected Result: Transaction amount is below the max amount\n");
	printf("Actual Result: ");

	if (transAmount1 > maxTransAmount)
	{
		printf("You Exceeded the max amount possible for transaction\n");
	}
	else
	{
		printf("Transaction amount is below the max amount \n");;
	}

	printf("\nTest Case 2: wrong input data\n");
	printf("Input Data: trans amoun = 10000 ... maxtransamount = 3000 \n");
	printf("Expected Result: You Exceeded the max amount possible for transaction\n");
	printf("Actual Result: ");

	if (transAmount2 > maxTransAmount)
	{
		printf("You Exceeded the max amount possible for transaction\n");
	}
	else
	{
		printf("Transaction amount is below the max amount \n");;
	}
}

void setMaxAmountTest(void)
{
	float maxAmount1 = 2000;
	float maxAmount2 = -2000;
	printf("\nTester name: Mohanad Magdy \n");
	printf("Function Name: setMaxAmountTest \n");
	printf("Test Case 1: right input data\n");
	printf("Input Data: 2000 \n");
	printf("Expected Result: Valid max amount\n");
	printf("Actual Result: ");

	if (maxAmount1 <= 0)
	{
		printf("Invalid max amount \n");
	}
	else
	{
		printf("Valid max amount \n");
	}

	printf("\nTest Case 2: wrong input data\n");
	printf("Input Data: -2000 \n");
	printf("Expected Result: Invalid max amount\n");
	printf("Actual Result: ");

	if (maxAmount2 <= 0)
	{
		printf("Invalid max amount \n");
	}
	else
	{
		printf("Valid max amount \n");
	}
}