//card.c
#define _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_DEPRECATE  
#define _CRT_NONSTDC_NO_DEPRECATE

#include "STD_TYPES_FWD.h"
#include "card.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

EN_cardError_t getCardHolderName(ST_cardData_t* cardData)
{
	printf("\nPlease Enter the card holder name : ");
	gets(cardData->cardHolderName);
	uint8_t counter = 0;
	//while loop to get the string length     ==== same to all funcitons in this module
	while (cardData->cardHolderName[counter] != 0)
	{
		//cheching if not from a->z , A->Z and not a space
		if ((cardData->cardHolderName[counter] < 'a' || cardData->cardHolderName[counter]>'z') && (cardData->cardHolderName[counter] < 'A' || cardData->cardHolderName[counter]>'Z') && cardData->cardHolderName[counter] != ' ')
		{
			printf("--> Name you enter must contain only characters\n");
			return WRONG_NAME;
		}
		counter++;
	}
	//check if the name is less than 20 elements or its 0 or more than 24 elements  
	if (counter < 20 || cardData->cardHolderName[0] == 0 || counter > 24)
	{
		printf("\nWrong Name entered\n");
		return WRONG_NAME;
	}
	else 
	{ 
		return CARD_OK; 
	}
}

EN_cardError_t getCardExpiryDate(ST_cardData_t* cardData)
{
	printf("\nPlease Enter the expiary date in the form of MM/YY : ");
	gets(cardData->cardExpirationDate);
	uint8_t counter = 0;
	while (cardData->cardExpirationDate[counter] != 0)
	{
		//cheching if not a number and not a /
		if ((cardData->cardExpirationDate[counter]<'0' || cardData->cardExpirationDate[counter]>'9')&& cardData->cardExpirationDate[counter]!='/')
		{
			printf("--> date you enter must contain only numbers and be in the form of MM/YY\n");
			return WRONG_EXP_DATE;
		}
		counter++;
	}
	if (cardData->cardExpirationDate[2] != '/')
	{
		printf("--> Wrong date form entered\n");
		return WRONG_EXP_DATE;
	}

	if (atoi(cardData->cardExpirationDate) < 0 || atoi(cardData->cardExpirationDate) > 12)
	{
		printf("--> Wrong date entered\n");
		return WRONG_EXP_DATE;
	}

	if (counter != 5 || cardData->cardExpirationDate[0] == 0)
	{
		printf("\nWrong EXP Date\n");
		return WRONG_EXP_DATE;
	}
	else 
	{
		printf("\nValid EXP Date\n");
		return CARD_OK; 
	}
}


EN_cardError_t getCardPAN(ST_cardData_t* cardData)
{
	printf("\nEnter the card pan : ");
	gets(cardData->primaryAccountNumber);
	uint8_t counter = 0;
	while (cardData->primaryAccountNumber[counter] != 0)
	{
		
		if (cardData->primaryAccountNumber[counter] < '0' || cardData->primaryAccountNumber[counter]>'9')
		{
			printf("--> PAN you enter must contain only numbers\n");
			return WRONG_PAN;
		}
		
		counter++;
	}
	if (counter <16 || cardData->primaryAccountNumber[0] == 0 || counter >19)
	{
		printf("Wrong pan entered\n");
		return WRONG_PAN;
	}
	else 
	{
		return CARD_OK;
	}
}

//test functions

void getCardHolderNameTest(void)
{
	printf("\nTester name: Mohanad Magdy \n");
	printf("Function Name: getCardHolderName \n");
	printf("Test Case 1: right input data\n");
	printf("Input Data: mohanad magdy mohamad\n");
	printf("Expected Result: Valid Name entered\n");
	printf("Actual Result: ");

	uint8_t name1[24] = "mohanad magdy mohamad";
	uint8_t name2[24] = "mohanad";
	uint8_t name3[24] = { 0 };
	uint8_t name4[] = "mohanad magdy mohamad fahmy ahmed";
	uint8_t counter = 0;
	while (name1[counter] != 0)
	{
		counter++;
	}
	if (counter < 20 || name1[0] == 0 || counter > 24)
	{
		printf("Wrong Name entered\n");
	}
	else
	{
		printf("Valid Name entered\n");
	}
	printf("\nTest Case 2: too short input data\n");
	printf("Input Data: mohanad \n");
	printf("Expected Result: Wrong Name entered\n");
	printf("Actual Result: ");
	counter = 0;
	while (name2[counter] != 0)
	{
		counter++;
	}
	if (counter < 20 || name2[0] == 0 || counter > 24)
	{
		printf("Wrong Name entered\n");
	}
	else
	{
		printf("Valid Name entered\n");
	}

	printf("\nTest Case 3: 0 as an input data\n");
	printf("Input Data: 0 \n");
	printf("Expected Result: Wrong Name entered\n");
	printf("Actual Result: ");
	counter = 0;
	while (name3[counter] != 0)
	{
		counter++;
	}
	if (counter < 20 || name3[0] == 0 || counter > 24)
	{
		printf("Wrong Name entered\n");
	}
	else
	{
		printf("Valid Name entered\n");
	}

	printf("\nTest Case 4: too long input data\n");
	printf("Input Data: mohanad magdy mohamad fahmy ahmed \n");
	printf("Expected Result: Wrong Name entered\n");
	printf("Actual Result: ");
	counter = 0;
	while (name4[counter] != 0)
	{
		counter++;
	}
	if (counter < 20 || name4[0] == 0 || counter > 24)
	{
		printf("Wrong Name entered\n");
	}
	else
	{
		printf("Valid Name entered\n");
	}
}



void getCardExpiryDateTest(void)
{
	printf("\nTester name: Mohanad Magdy \n");
	printf("Function Name: getCardExpiryDate \n");
	printf("Test Case 1: right input data\n");
	printf("Input Data: 12/22\n");
	printf("Expected Result: Valid EXP Date\n");
	printf("Actual Result: ");

	uint8_t date1[6] = "12/22";
	uint8_t date2[6] = "122";
	uint8_t date3[6] = { 0 };
	uint8_t date4[] = "122/122";

	uint8_t counter = 0;
	while (date1[counter] != 0)
	{
		counter++;
	}
	if (counter != 5 || date1[0] == 0)
	{
		printf("Wrong EXP Date\n");
	}
	else
	{
		printf("Valid EXP Date\n");
	}
	printf("\nTest Case 2: too shore input data\n");
	printf("Input Data: 122\n");
	printf("Expected Result: Wrong EXP Date\n");
	printf("Actual Result: ");

	counter = 0;
	while (date2[counter] != 0)
	{
		counter++;
	}
	if (counter != 5 || date2[0] == 0)
	{
		printf("Wrong EXP Date\n");
	}
	else
	{
		printf("Valid EXP Date\n");
	}

	printf("\nTest Case 3: 0 input data \n");
	printf("Input Data: 0\n");
	printf("Expected Result: Wrong EXP Date\n");
	printf("Actual Result: ");

	counter = 0;
	while (date3[counter] != 0)
	{
		counter++;
	}
	if (counter != 5 || date3[0] == 0)
	{
		printf("Wrong EXP Date\n");
	}
	else
	{
		printf("Valid EXP Date\n");
	}

	printf("\nTest Case 4: too long input data \n");
	printf("Input Data: 122/122\n");
	printf("Expected Result: Wrong EXP Date\n");
	printf("Actual Result: ");

	counter = 0;
	while (date4[counter] != 0)
	{
		counter++;
	}
	if (counter != 5 || date4[0] == 0)
	{
		printf("Wrong EXP Date\n");
	}
	else
	{
		printf("Valid EXP Date\n");
	}
}


void getCardPANTest(void)
{
	printf("\nTester name: Mohanad Magdy \n");
	printf("Function Name: getCardExpiryDate \n");
	printf("Test Case 1: right input data\n");
	printf("Input Data: 1234567812345678\n");
	printf("Expected Result: Valid pan enterd\n");
	printf("Actual Result: ");

	uint8_t pan1[] = "1234567812345678";
	uint8_t pan2[] = "123";
	uint8_t pan3[] = { 0 };
	uint8_t pan4[] = "123456789123456789123456789";

	uint8_t counter = 0;
	while (pan1[counter] != 0)
	{
		counter++;
	}
	if (counter < 16 || pan1[0] == 0 || counter >19)
	{
		printf("Wrong pan entered\n");
	}
	else
	{
		printf("Valid pan enterd\n");
	}

	printf("\nTest Case 2: too short input data\n");
	printf("Input Data: 123\n");
	printf("Expected Result: Wrong pan entered\n");
	printf("Actual Result: ");
	counter = 0;
	while (pan2[counter] != 0)
	{
		counter++;
	}
	if (counter < 16 || pan2[0] == 0 || counter >19)
	{
		printf("Wrong pan entered\n");
	}
	else
	{
		printf("Valid pan enterd\n");
	}

	printf("\nTest Case 3: 0 as an input data\n");
	printf("Input Data: 0\n");
	printf("Expected Result: Wrong pan entered\n");
	printf("Actual Result: ");
	counter = 0;
	while (pan3[counter] != 0)
	{
		counter++;
	}
	if (counter < 16 || pan3[0] == 0 || counter >19)
	{
		printf("Wrong pan entered\n");
	}
	else
	{
		printf("Valid pan enterd\n");
	}

	printf("\nTest Case 4: too long input data\n");
	printf("Input Data: 123456789123456789123456789\n");
	printf("Expected Result: Wrong pan entered\n");
	printf("Actual Result: ");
	counter = 0;
	while (pan4[counter] != 0)
	{
		counter++;
	}
	if (counter < 16 || pan4[0] == 0 || counter >19)
	{
		printf("Wrong pan entered\n");
	}
	else
	{
		printf("Valid pan enterd\n");
	}
}
