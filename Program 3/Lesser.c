/*********************************************************************************************************
*Program: Lesser.c
*
*Summary: Asks the user for five integers, and prints out the smallest and largest integers
***********************************************************************************************************
*Psuedocode:
*
*Begin
*	Ask for five numbers
*	Find the smallest number
*	Find the largest number
*	Print the smallest and largest values
*End
**********************************************************************************************************/
#include <stdio.h>

int main() {																							   //Begin
	int a, b, c, d, e, smallest, largest;
	
	printf("Enter five integers in any order: ");
	scanf("%d %d %d %d %d", &a, &b, &c, &d, &e);														   //Ask for five numbers
	
	if (a <= b && a <= c && a <= d && a <= e)																   //Find the smallest number
		smallest = a;
	else if (b <= c && b <= d && b <= e)
		smallest = b;
	else if (c <= d && c <= e)
		smallest = c;
	else if (d <= e)
		smallest = d;
	else
		smallest = e;
	
	if (a >= b && a >= c && a >= d && a >= e)																   //Find the largest number
		largest = a;
	else if (b >= c && b >= d && b >= e)
		largest = b;
	else if (c >= d && c >= e)
		largest = c;
	else if (d >= e)
		largest = d;
	else
		largest = e;
	
	printf("Largest integer: %d\nSmallest integer: %d\n", largest, smallest);										   //Print the smallest and largest values
	
	return 0;
}																										   // End