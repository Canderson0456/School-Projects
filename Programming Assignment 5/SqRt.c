/***********************************************************************************************************
*Program: SqRt.c
*
*Summary: Asks the user for a number, returns the square root using Newtons method of Calculation
************************************************************************************************************
*Input:A number
*
*Output:A double/Square Root of Input
************************************************************************************************************
*Psuedocode:
*
*Begin
*	Ask for a number
*	Begin loop
*	Divide input number by Y (value 1 to begin)
*	Caculate average of divided value + Y, set Y to newly calculated value
*	End loop when last calculated average and current calculated average have a difference of <.00001
*	Print SqRt number
*End
***********************************************************************************************************/
#include <stdio.h>
#include <math.h>
#define DEBUG 0
#define FUN 1

int main(){													//Begin
	double y = 1, xy, ly;
	float x;
	
	printf("Enter a positive number: ");					//Ask for a number
	scanf("%f", &x);
	
	if(DEBUG == 1)
		printf("x = %f\n", x);
	
	if(x <= 0) {											//End if the User decides to square root a negative or 0
			if(FUN == 1)
				printf("\nno...");
			else
				printf("\nCan not root negatives or zero");
		return 0;
	}
		
	
	do{														//Begin loop
		ly = y;
		
		xy = (x/y);											//Divide input number by Y (value 1 to begin)
		
		if(DEBUG == 1)
			printf("xy = %f\n", xy);
		
		y = ((xy + y)/2);									//Caculate average of divided value + Y, set Y to newly calculated value
		
		if(DEBUG == 1)
			printf("y = %f\n", y);
		
	} while((fabs(fabs(y) - fabs(ly))) > .00001);			//End loop when last calculated average and current calculated average have a difference of <.00001
	
	printf("\nSquare root: %.8f", y);							//Print SqRt number
	
	return 0;
}															//End