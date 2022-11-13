
#define _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_DEPRECATE  
#define _CRT_NONSTDC_NO_DEPRECATE

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "STD_TYPES_FWD.h"
#include "../Card/card.h"
#include "../Terminal/terminal.h"
#include "../Server/server.h"
#include "application.h"

#define MAX_AMOUNT		10000.0

void appStart(void)
{
	ST_cardData_t cardData = { 0 };
	ST_terminalData_t termData = { 0 };
	ST_transaction_t transData = { 0 };
	uint8_t choise[4] = { 0 };

	printf("Enter your choise : \n");
	printf("1.For Transaction process \n");
	printf("2.To exit the program \n");
	printf("--->  ");
	gets(choise);

	while (atoi(choise) != 2)
	{
		switch (atoi(choise))
		{
		case 1:
		{
			if (getCardHolderName(&cardData) == CARD_OK && getCardExpiryDate(&cardData) == CARD_OK && getCardPAN(&cardData) == CARD_OK)
			{
				transData.cardHolderData = cardData;

				if (getTransactionDate(&termData) == TERMINAL_OK && isCardExpired(&cardData, &termData) == TERMINAL_OK && getTransactionAmount(&termData) == TERMINAL_OK)
				{
					if (setMaxAmount(&termData, MAX_AMOUNT) == TERMINAL_OK && isBelowMaxAmount(&termData) == TERMINAL_OK)
					{
						transData.terminalData = termData;
						if (recieveTransactionData(&transData) == SERVER_OK)
						{
							printf("\n\nTransaction Completed \n");
						}
						else
						{
							printf("Recive transaction Failed \n");
						}
					}
					else
					{
						printf("Terminal error \n");
					}
				}
				else
				{
					printf("Terminal error \n");
				}
			}
			else
			{
				printf("Card error \n");
			}

			break;
		}
		default:
			printf("\n==Wrong choise==\n");
			break;
		}


		printf("Enter a new choise ->  ");
		gets(choise);

	}

	if (atoi(choise) == 2) 
	{
		printf("\n====Exiting the program====\n");
	}

}
