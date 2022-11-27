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
	ST_cardData_t cardData;
	printf("\nTester name: Mohanad Magdy \n");
	printf("Function Name: getCardHolderName \n");
	printf("Test Case 1: right input data\n");
	printf("Input Data: mohanad magdy mohamad\n");
	printf("Expected Result: Valid Name entered\n");
	printf("Actual Result: ");

	if (getCardHolderName(&cardData) == CARD_OK)
	{
		printf("Valid Name entered\n");
	}
	else
	{
		printf("Wrong Name entered\n");
	}

	printf("\nTest Case 2: too short input data\n");
	printf("Input Data: mohanad \n");
	printf("Expected Result: Wrong Name entered\n");
	printf("Actual Result: ");

	if (getCardHolderName(&cardData) == CARD_OK)
	{
		printf("Valid Name entered\n");
	}
	else
	{
		printf("Wrong Name entered\n");
	}

	printf("\nTest Case 3: 0 as an input data\n");
	printf("Input Data: 0 \n");
	printf("Expected Result: Wrong Name entered\n");
	printf("Actual Result: ");

	if (getCardHolderName(&cardData) == CARD_OK)
	{
		printf("Valid Name entered\n");
	}
	else
	{
		printf("Wrong Name entered\n");
	}

	printf("\nTest Case 4: too long input data\n");
	printf("Input Data: mohanad magdy mohamad fahmy ahmed \n");
	printf("Expected Result: Wrong Name entered\n");
	printf("Actual Result: ");

	if (getCardHolderName(&cardData) == CARD_OK)
	{
		printf("Valid Name entered\n");
	}
	else
	{
		printf("Wrong Name entered\n");
	}

	printf("\nTest Case 5: letters and numbers data\n");
	printf("Input Data: mohanad magdy mohama4 \n");
	printf("Expected Result: Wrong Name entered\n");
	printf("Actual Result: ");

	if (getCardHolderName(&cardData) == CARD_OK)
	{
		printf("Valid Name entered\n");
	}
	else
	{
		printf("Wrong Name entered\n");
	}
}



void getCardExpiryDateTest(void)
{
	ST_cardData_t cardData;

	printf("\nTester name: Mohanad Magdy \n");
	printf("Function Name: getCardExpiryDate \n");
	printf("Test Case 1: right input data\n");
	printf("Input Data: 12/22\n");
	printf("Expected Result: Valid EXP Date\n");
	printf("Actual Result: \n");

	if (getCardExpiryDate(&cardData) == CARD_OK)
	{
		printf("\nValid EXP Date\n");
	}
	else
	{
		printf("\nWrong EXP Date\n");
	}

	printf("\nTest Case 2: too shore input data\n");
	printf("Input Data: 122\n");
	printf("Expected Result: Wrong EXP Date\n");
	printf("Actual Result: ");

	if (getCardExpiryDate(&cardData) == CARD_OK)
	{
		printf("\nValid EXP Date\n");
	}
	else
	{
		printf("\nWrong EXP Date\n");
	}


	printf("\nTest Case 3: 0 input data \n");
	printf("Input Data: 0\n");
	printf("Expected Result: Wrong EXP Date\n");
	printf("Actual Result: ");

	if (getCardExpiryDate(&cardData) == CARD_OK)
	{
		printf("\nValid EXP Date\n");
	}
	else
	{
		printf("\nWrong EXP Date\n");
	}

	printf("\nTest Case 4: too long input data \n");
	printf("Input Data: 122/122\n");
	printf("Expected Result: Wrong EXP Date\n");
	printf("Actual Result: ");

	if (getCardExpiryDate(&cardData) == CARD_OK)
	{
		printf("\nValid EXP Date\n");
	}
	else
	{
		printf("\nWrong EXP Date\n");
	}

	printf("\nTest Case 5: data has letters in it \n");
	printf("Input Data: dd/20\n");
	printf("Expected Result: Wrong EXP Date\n");
	printf("Actual Result: ");

	if (getCardExpiryDate(&cardData) == CARD_OK)
	{
		printf("\nValid EXP Date\n");
	}
	else
	{
		printf("\nWrong EXP Date\n");
	}

	printf("\nTest Case 6: invalid data form \n");
	printf("Input Data: 12-22\n");
	printf("Expected Result: Wrong EXP Date\n");
	printf("Actual Result: ");

	if (getCardExpiryDate(&cardData) == CARD_OK)
	{
		printf("\nValid EXP Date\n");
	}
	else
	{
		printf("\nWrong EXP Date\n");
	}

}


void getCardPANTest(void)
{
	ST_cardData_t cardData;

	printf("\nTester name: Mohanad Magdy \n");
	printf("Function Name: getCardPAN \n");
	printf("Test Case 1: right input data\n");
	printf("Input Data: 1234567812345678\n");
	printf("Expected Result: Valid pan enterd\n");
	printf("Actual Result: ");

	if (getCardPAN(&cardData) == CARD_OK)
	{
		printf("\nValid pan enterd\n");
	}
	else
	{
		printf("\nWrong pan entered\n");
	}

	printf("\nTest Case 2: too short input data\n");
	printf("Input Data: 123\n");
	printf("Expected Result: Wrong pan entered\n");
	printf("Actual Result: ");

	if (getCardPAN(&cardData) == CARD_OK)
	{
		printf("\nValid pan enterd\n");
	}
	else
	{
		printf("\nWrong pan entered\n");
	}

	printf("\nTest Case 3: 0 as an input data\n");
	printf("Input Data: 0\n");
	printf("Expected Result: Wrong pan entered\n");
	printf("Actual Result: ");

	if (getCardPAN(&cardData) == CARD_OK)
	{
		printf("\nValid pan enterd\n");
	}
	else
	{
		printf("\nWrong pan entered\n");
	}

	printf("\nTest Case 4: too long input data\n");
	printf("Input Data: 123456789123456789123456789\n");
	printf("Expected Result: Wrong pan entered\n");
	printf("Actual Result: ");

	if (getCardPAN(&cardData) == CARD_OK)
	{
		printf("\nValid pan enterd\n");
	}
	else
	{
		printf("\nWrong pan entered\n");
	}

	printf("\nTest Case 5: data with letters in it\n");
	printf("Input Data: a2345678912345678\n");
	printf("Expected Result: Wrong pan entered\n");
	printf("Actual Result: ");

	if (getCardPAN(&cardData) == CARD_OK)
	{
		printf("\nValid pan enterd\n");
	}
	else
	{
		printf("\nWrong pan entered\n");
	}
}
