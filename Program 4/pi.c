/***********************************************************************************************************
*Program: pi.c
*
*Summary: Asks the user for a number, calculates pi using as many terms
************************************************************************************************************
*Input:A single number
*
*Output:Approximation of pi using as many terms as the user specified
************************************************************************************************************
*Psuedocode:
*
*Begin
*	Ask for a number
*	Begin for loop
*	Calculate pi using an infinite series
*	End for loop once pi has been calculated using specified amount of terms
*	Print pi
*End
***********************************************************************************************************/
#include <stdio.h>
#define DEBUG 0

int main() {																	//Begin
	int i, n, a = 1;
	float pi, d = 1;
	
	printf("\nEnter an integer n. The value of pi will be calculated using n ");
	printf("terms of an\ninfinite series.\n\n");								//Ask for a number
	if(DEBUG == 1){
		printf("i = %d\n", i);
		printf("d = %d\n\n", d);
	}
	printf("n: ");
	
	scanf("%d", &n);
	
	if(DEBUG == 1)
		printf("\nn = %d\n\n", n);
	
	for(i = 0; i < n; i++) {			 									//Begin for loop
		if(DEBUG == 1)	
			printf("pi = %f", pi);
		pi += (4/d)*a;															//Calculate pi using an infinite series
		d += 2;
		a *= -1;
		if(DEBUG == 1)
			printf("pi = %f d = %d\n", pi, d);
	}																			//End for loop once pi has been calculated using specified amount of terms
	
	printf("\nThe approximation of pi using %d terms is %f\n", n, pi);			//Print pi
	
	return 0;
}																				//End