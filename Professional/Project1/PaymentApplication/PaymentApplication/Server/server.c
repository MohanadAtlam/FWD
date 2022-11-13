#define _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_DEPRECATE  
#define _CRT_NONSTDC_NO_DEPRECATE

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "STD_TYPES_FWD.h"
#include "../Card/card.h"
#include "../Terminal/terminal.h"
#include "server.h"

ST_accountsDB_t accountsDB[255] = { {2000.0,RUNNING,"1234567812345678"},{10000.0,BLOCKED,"1122334455667788"} , {7000.0,RUNNING,"1212343456567878"} };

ST_transaction_t transactionDB[255] = { 0 }; //intialized with 0s


EN_transState_t recieveTransactionData(ST_transaction_t* transData)
{
	ST_accountsDB_t *accountRefrence = NULL ;
	if (isValidAccount(&transData->cardHolderData, &accountRefrence) == ACCOUNT_NOT_FOUND)
	{
		transData->transState = FRAUD_CARD;
		if (saveTransaction(transData) != SAVING_FAILED)
		{
			printf("Fruad Card:::This acount is not in the data base\n");
			return FRAUD_CARD;
		}
	}
	if (isBlockedAccount(accountRefrence) == BLOCKED_ACCOUNT)
	{
		transData->transState = DECLINED_STOLEN_CARD;
		if (saveTransaction(transData) != SAVING_FAILED)
		{
			printf("This Card is stolen\n");
			return DECLINED_STOLEN_CARD;
		}
	}
	
	if (isAmountAvailable(&transData->terminalData,accountRefrence) == LOW_BALANCE)
	{
		transData->transState = DECLINED_INSUFFECIENT_FUND;
		if (saveTransaction(transData) != SAVING_FAILED)
		{
			printf("Insuffecient Fund:::The amount you asking for is not available in your account\n");
			return DECLINED_INSUFFECIENT_FUND;
		}
	}
	
	if (saveTransaction(transData) == SAVING_FAILED)
	{
		return INTERNAL_SERVER_ERROR;
	}
	
	accountRefrence->balance -= transData->terminalData.transAmount;
	printf("\n-------Transaction Done Account Updated-------\n");
	printf("New balance = %.1f", accountRefrence->balance);
	return APPROVED;
}


EN_serverError_t isValidAccount(ST_cardData_t* cardData, ST_accountsDB_t** accountRefrence)
{
	uint8_t search, counter;
	for (counter = 0; counter < 255; counter++)
	{
		search = strcmp(cardData->primaryAccountNumber, accountsDB[counter].primaryAccountNumber);
		if (search == 0)
			break;
	}
	if (search == 0)
	{
		*accountRefrence = &accountsDB[counter];
		return SERVER_OK;
	}
	else
	{
		*accountRefrence = NULL;
		return ACCOUNT_NOT_FOUND;
	}
}

EN_serverError_t isBlockedAccount(ST_accountsDB_t* accountRefrence)
{
	if (accountRefrence->state == RUNNING)
	{
		printf("\nthis Account is running \n");
		return SERVER_OK;
	}
	else
	{
		return BLOCKED_ACCOUNT; 
	}
}

EN_serverError_t isAmountAvailable(ST_terminalData_t* termData, ST_accountsDB_t* accountRefrence)
{
	if (termData->transAmount > accountRefrence->balance)
	{
		printf("\n------- The amount you entered is not available -------\n");
		return LOW_BALANCE;
	}
	else
	{
		printf("\n----------------- Amount available -----------------\n");
		return SERVER_OK;
	}
		
}

EN_serverError_t saveTransaction(ST_transaction_t* transData)
{
	static uint32_t transactionNum = 0;
	transData->transactionSequenceNumber = transactionNum+1;
	if (transactionNum < 255)
	{
		transactionDB[transactionNum].cardHolderData = transData->cardHolderData;
		transactionDB[transactionNum].terminalData = transData->terminalData;
		transactionDB[transactionNum].transState = transData->transState;
		transactionDB[transactionNum].transactionSequenceNumber = transData->transactionSequenceNumber;
		

		listSavedTransactions();
		transactionNum++;
		printf("\nTransaction data saved \n");
		return SERVER_OK;


	}
	else
	{
		printf("\nTransaction data saving Failed \n");
		return SAVING_FAILED;
	}
		


}

void listSavedTransactions(void)
{
	uint8_t counter = 0;
	if (transactionDB[counter].transactionSequenceNumber > 0)
	{
		while (transactionDB[counter].transactionSequenceNumber >= counter)
		{
			printf("\n#########################\n");
			printf("Transaction Sequence Number: %d \n", transactionDB[counter].transactionSequenceNumber);

			printf("Transaction Date: ");
			puts(transactionDB[counter].terminalData.transactionDate);

			printf("Transaction Amount: %.1f \n", transactionDB[counter].terminalData.transAmount);
			switch (transactionDB[counter].transState)
			{
			case  APPROVED:
				printf("Transaction State: Approved \n");
				break;
			case DECLINED_INSUFFECIENT_FUND:
				printf("Transaction State: DECLINED INSUFFECIENT FUND\n");
				break;
			case DECLINED_STOLEN_CARD:
				printf("Transaction State: DECLINED STOLEN CARD\n");
				break;
			case FRAUD_CARD:
				printf("Transaction State: DECLINED FRAUD CARD\n");
				break;
			case INTERNAL_SERVER_ERROR:
				printf("Transaction State: DECLINED INTERNAL_SERVER_ERROR\n");
				break;
			}

			printf("Terminal Max Amount: %.1f \n", transactionDB[counter].terminalData.maxTransAmount);

			printf("Cardholder Name: ");
			puts(transactionDB[counter].cardHolderData.cardHolderName);

			printf("PAN: ");
			puts(transactionDB[counter].cardHolderData.primaryAccountNumber);

			printf("Card Expiration Date: ");
			puts(transactionDB[counter].cardHolderData.cardExpirationDate);
			printf("#########################\n");
			counter++;
		}
	}
	else
	{
		printf("\n===No Transactions done yet===\n");
	}
	
	
}


//test functions
void recieveTransactionDataTest(void)
{
	ST_cardData_t cardHolderData1={"mohanad magdy mohamad","1234567812345678","12/22"};
	ST_terminalData_t terminalData1 = {1000,10000,"11/11/2022" };
	ST_transaction_t transData;
	transData.cardHolderData = cardHolderData1;
	transData.terminalData = terminalData1;

	printf("\nTester name: Mohanad Magdy \n");
	printf("Function Name: recieveTransactionData \n");
	printf("Test Case 1: \n");
	printf("Input Data: data will return approved transaction\n");
	printf("Expected Result: Approved\n");
	printf("Actual Result: ");


	switch (recieveTransactionData(&transData))
	{
	case  APPROVED:
		printf("\n Approved \n");
		break;
	case DECLINED_INSUFFECIENT_FUND:
		printf("\nDECLINED INSUFFECIENT FUND\n");
		break;
	case DECLINED_STOLEN_CARD:
		printf("\nDECLINED STOLEN CARD\n");
		break;
	case FRAUD_CARD:
		printf("\nDECLINED FRAUD CARD\n");
		break;
	case INTERNAL_SERVER_ERROR:
		printf("\nDECLINED INTERNAL_SERVER_ERROR\n");
		break;
	}
	
	transData.terminalData.transAmount=10000;


	printf("Test Case 2: \n");
	printf("Input Data: transaction amount more than the account balance\n");
	printf("Expected Result: DECLINED INSUFFECIENT FUND\n");
	printf("Actual Result: ");

	switch (recieveTransactionData(&transData))
	{
	case  APPROVED:
		printf("\n Approved \n");
		break;
	case DECLINED_INSUFFECIENT_FUND:
		printf("\nDECLINED INSUFFECIENT FUND\n");
		break;
	case DECLINED_STOLEN_CARD:
		printf("\nDECLINED STOLEN CARD\n");
		break;
	case FRAUD_CARD:
		printf("\nDECLINED FRAUD CARD\n");
		break;
	case INTERNAL_SERVER_ERROR:
		printf("\nDECLINED INTERNAL_SERVER_ERROR\n");
		break;
	}

	ST_cardData_t cardHolderData2 = { "mohanad magdy mohamad","1122334455667788","12/22" };
	transData.cardHolderData = cardHolderData2;
	transData.terminalData = terminalData1;

	printf("\nTest Case 3: \n");
	printf("Input Data: Pan number that belong to blocked account\n");
	printf("Expected Result: DECLINED STOLEN CARD\n");
	printf("Actual Result: ");

	switch (recieveTransactionData(&transData))
	{
	case  APPROVED:
		printf("\n Approved \n");
		break;
	case DECLINED_INSUFFECIENT_FUND:
		printf("\nDECLINED INSUFFECIENT FUND\n");
		break;
	case DECLINED_STOLEN_CARD:
		printf("\nDECLINED STOLEN CARD\n");
		break;
	case FRAUD_CARD:
		printf("\nDECLINED FRAUD CARD\n");
		break;
	case INTERNAL_SERVER_ERROR:
		printf("\nDECLINED INTERNAL_SERVER_ERROR\n");
		break;
	}

	ST_cardData_t cardHolderData3 = { "mohanad magdy mohamad","11223344556677889","12/22" };
	transData.cardHolderData = cardHolderData3;
	transData.terminalData = terminalData1;

	printf("\nTest Case 4: \n");
	printf("Input Data: Pan number that doent belong to any account in the data base\n");
	printf("Expected Result: DECLINED FRAUD CARD\n");
	printf("Actual Result: ");

	switch (recieveTransactionData(&transData))
	{
	case  APPROVED:
		printf("\n Approved \n");
		break;
	case DECLINED_INSUFFECIENT_FUND:
		printf("\nDECLINED INSUFFECIENT FUND\n");
		break;
	case DECLINED_STOLEN_CARD:
		printf("\nDECLINED STOLEN CARD\n");
		break;
	case FRAUD_CARD:
		printf("\nDECLINED FRAUD CARD\n");
		break;
	case INTERNAL_SERVER_ERROR:
		printf("\nDECLINED INTERNAL_SERVER_ERROR\n");
		break;
	}

}


void isValidAccountTest(void)
{
	ST_cardData_t cardHolderData1 = { "mohanad magdy mohamad","1234567812345678","12/22" };
	ST_cardData_t cardHolderData2 = { "mohanad magdy mohamad","12345678123456789","12/22" };
	ST_accountsDB_t* accRef = NULL;
	uint8_t output;

	printf("\nTester name: Mohanad Magdy \n");
	printf("Function Name: isValidAccount \n");
	printf("Test Case 1: \n");
	printf("Input Data: pan number for an acoount in the data base\n");
	printf("Expected Result: Acount Found\n");
	printf("Actual Result: ");

	output = isValidAccount(&cardHolderData1, &accRef);
	if (output == SERVER_OK)
		printf("Account Found");
	if (output == ACCOUNT_NOT_FOUND)
		printf("Account not found");

	printf("\nTest Case2 : \n");
	printf("Input Data: pan number for an acoount that is not in the data base\n");
	printf("Expected Result: Account not found\n");
	printf("Actual Result: ");

	output = isValidAccount(&cardHolderData2, &accRef);
	if (output == SERVER_OK)
		printf("Acount Found");
	if (output == ACCOUNT_NOT_FOUND)
		printf("Account not found");
}

void isAmountAvailableTest(void)
{
	ST_terminalData_t termData;
	ST_accountsDB_t accountRefrence;
	termData.transAmount = 1000;
	accountRefrence.balance = 3000;

	printf("\nTester name: Mohanad Magdy \n");
	printf("Function Name: isAmountAvailable \n");
	printf("Test Case 1: \n");
	printf("Input Data: amount that is available in the account balance\n");
	printf("Expected Result: Amount Available\n");
	printf("Actual Result: ");

	if (isAmountAvailable(&termData, &accountRefrence) == SERVER_OK)
		printf("Amount Available\n");
	else if (isAmountAvailable(&termData, &accountRefrence) == LOW_BALANCE)
		printf("Amount is not Available\n");

	termData.transAmount = 10000;
	printf("\nTest Case 2: \n");
	printf("Input Data: amount that is not available in the account balance\n");
	printf("Expected Result: Amount is not Available\n");
	printf("Actual Result: ");

	if (isAmountAvailable(&termData, &accountRefrence) == SERVER_OK)
		printf("Amount Available\n");
	else if (isAmountAvailable(&termData, &accountRefrence) == LOW_BALANCE)
		printf("Amount is not Available\n");
}

void saveTransactionTest(void)
{
	ST_cardData_t cardHolderData = { "mohanad magdy mohamad","1234567812345678","12/22" };
	ST_terminalData_t terminalData = { 1000,10000,"11/11/2022" };
	ST_transaction_t transData;
	uint8_t output;

	printf("\nTester name: Mohanad Magdy \n");
	printf("Function Name: saveTransaction \n");
	printf("Test Case 1: \n");
	printf("Expected Result: Transaction data saved\n");
	printf("Actual Result: ");

	transData.cardHolderData = cardHolderData;
	transData.terminalData = terminalData;
	transData.transactionSequenceNumber = 1;
	transData.transState = APPROVED;

	output = saveTransaction(&transData);
}

void listSavedTransactionsTest(void)
{
	printf("\nTester name: Mohanad Magdy \n");
	printf("Function Name: listSavedTransactions \n");
	printf("\nTest Case 1: \n");
	printf("Expected Result: ===No Transactions done yet===\n");
	printf("Actual Result: ");
	transactionDB[0].transactionSequenceNumber = 0;
	listSavedTransactions();

	printf("\nTest Case 2: \n");
	printf("Expected Result: (Saving formula with 0 data)\n");
	printf("Actual Result: ");
	transactionDB[0].transactionSequenceNumber = 1;
	listSavedTransactions();
}