/*********************************************************************************************************
*Program: Polynomial.c
*
*Summary: Ask the user for a number, insert said number into a polynomial expression
***********************************************************************************************************
*Input: None
*
*Output: 0
***********************************************************************************************************
*Psuedocode:
*
*Begin
*	Ask user for a number
*	Pass through input to a function
*		Calculate 2x^5
*			For(5 calculations)
*				result *= 2x
*		And so on for the rest of the exponents
*		Return calculation
*	Print calculated number
*	Return 0
*End
**********************************************************************************************************/
#include<stdio.h>

double poly(double input);

int main() {													//Begin
	double x;

	printf("This program calculates the following polynomial:\n");
	printf("2x^5 + 3x^4 - x^3 - 5x^2 + 6x - 7\n");
	printf("Please enter a value for x: ");							//Ask user for a number
	scanf_s("%lf", &x);
	printf("Result: %.8f", poly(x));									//Pass through input to a function, and Print calculated number

	return 0;														//Return 0
}																//End

/**********************************************************************************************************
*Input: A double
*
*Output: A double
***********************************************************************************************************
*Psuedocode:
*
*Begin
*	Calculate polynomial
*		for(5 calculations)
*			temp *= x
*		Endloop
*		result += (value calculated in loop * 2)
*		for(4 calculations)
*			temp *= x
*		Endloop
*		result += (value calculated in loop * 3)
*		for(3 calculations)
*			temp *= x
*		Endloop
*		result -= value calculated in loop
*		for (2 calculations)
*			temp *= x
*		Endloop
*		result -= (value calculated in loop * 5)
*		result += (6x)
*		result -= 7
*	End Calculation
*	Return Calculation
*End
***********************************************************************************************************
*Comments:
*
*Putting the psuedocode next to the actual code is next to useless here, I feel like this is all basic
*enough that anyone should be able to understand this, since the psuedocode doesn't say that much more
*than what the code is saying, just clarifying some variables is all, but whatever...
**********************************************************************************************************/
double poly(double input) {				//Begin
	double temp = 1, result = 0;
	int it = 0;
											//Calculate polynomial
	for (temp = 1, it = 0; it < 5; it++) {		//for(5 calculations)
		temp *= (input);							//temp *= x
	}											//Endloop
	result += (2 * temp);							//result += (value calculated in loop * 2)
	
	for (temp = 1, it = 0; it < 4; it++) {		//for(4 calculations)
		temp *= (input);							//temp *= 3x
	}											//Endloop
	result += (3 * temp);							//result += (value calculated in loop * 3)

	for (temp = 1, it = 0; it < 3; it++) {		//for(3 calculations)
		temp *= (input);							//temp *= x
	}											//Endloop
	result -= temp;								//result -= value calculated in loop

	for (temp = 1, it = 0; it < 2; it++) {		//for(2 calculations)
		temp *= (input);							//temp *= 5x
	}											//Endloop
	result -= (5 * temp);						//result -= (value calculated in loop * 5)

	result += (6 * input);						//result += 6x

	result -= (7);								//result -= 7
											//End Calculation
	return result;							//Return Calculation
}										//End