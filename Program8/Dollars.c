/*********************************************************************************************************
*Program: Dollars.c
*
*Summary: Ask the user for a number, divide that number into 20s, 10s, 5s, 2s, and 1s; print the result
***********************************************************************************************************
*Function: Main
*
*Summary: Initialize a bunch of stuff, ask for a number, and then make something else do all the hard work
*	cont: (and print some stuff)
***********************************************************************************************************
*Input: None
*
*Output: 0
***********************************************************************************************************
*Psuedocode:
*
*Begin
*	Ask user for a cash amount
*	Pass through cash amount to a function
*	Print values that were modified by the previously called function
*		(was going to do an array, but we've been talking about pointers, so whatever...)
*End
**********************************************************************************************************/
#include<stdio.h>

void cash(int full, int *tw, int *te, int *f, int *two, int *o);

int main(){																//Begin
	int full, twenties = 0, tens = 0, fives = 0, twos = 0, ones = 0;
	int *tw = &twenties, *te = &tens, *f = &fives, *two = &twos, *o = &ones;
	
	printf("Enter an amount to be broken into bills: $");						//Ask user for a cash amount
	scanf("%d", &full);
	
	
	cash(full, tw, te, f, two, o);											//Pass through cash amount to a function
	
	printf("The following numbers of the specified bills are required:\n");
	printf("$20: %d\n", *tw/*twenties*/);									//Print values that were modified by a previously called function
	printf("$10: %d\n", *te/*tens*/);
	printf("$5: %d\n", *f/*fives*/);
	printf("$2: %d\n", *two/*twos*/);
	printf("$1: %d", *o/*ones*/);
	
	return 0;															//End
}

/**********************************************************************************************************
*Function: Cash
*
*Summary: Take a dollar amount and break it down into various bill sizes
***********************************************************************************************************
*Input: 6 int pointers
*
*Output: N/A	(void)
***********************************************************************************************************
*Psuedocode:
*
*Begin
*	Create a copy of a passed through value so we can change it temporarily
*	Break up the full value into bill values	
*		Twenties = full value / twenty (truncate the rest)
*		Subtract our full value by the twenties we took out
*		Tens = new full value / 10
*		Subtract our full value by the tens we took out
*		Fives = full value / 5
*		Subtract our full value by the fives we took out
*		Twos = full value / 2
*		Subtract our full value by the twos we took out
*		Ones = what remains of our full value
*	End Breaking up into bill values
*End
**********************************************************************************************************/

void cash(int full, int *tw, int *te, int *f, int *two, int *o){	//Begin
	int fu = full;														//Create a copy of a passed through value so we can change it temporarily
																		//Break up the full value into bill values
	*tw = fu / 20;															//Twenties = full value / twenty (truncate the rest)
	fu -= (20 * (*tw));														//Subtract our full value by the twenties we took out
	
	*te = fu / 10;															//Tens = new full value / 10
	fu -= (10 * (*te));														//Subtract our full value by the tens we took out
	
	*f = fu / 5;															//Fives = full value / 5
	fu -= (5 * (*f));														//Subtract our full value by the fives we took out
	
	*two = fu / 2;															//Twos = full value / 2
	fu -= (2 * (*two));														//Subtract our full value by the twos we took out
	
	*o = fu;																//Ones = what remains of our full value
																		//End Breaking up into bill values
}																	//End

