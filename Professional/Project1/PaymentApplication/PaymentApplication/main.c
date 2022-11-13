//main.c
#define _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_DEPRECATE  
#define _CRT_NONSTDC_NO_DEPRECATE

#include<stdio.h>
#include <stdlib.h>

#include "STD_TYPES_FWD.h"
#include "Card/card.h"
#include "Terminal/terminal.h"
#include "Server/server.h"
#include "Applicaion/application.h"



int main()
{
	appStart();

	return 0;
}