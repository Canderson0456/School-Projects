/*********************************************************************************************************
*Program: EAN.c
*
*Summary: Computes the ckeck digit of a European Article Number
***********************************************************************************************************
*Psuedocode:
*
*Begin
*	Ask the user for the first 12 digits of an EAN
*	Add the second, fourth, sixth, eigth, tenth and telfth digits
*	Add the first, third, fifth, seventh, ninth, and eleventh digits
*	Multiply the first sum by 3 and add it to the second sum
*	Subtract it all by 1
*	Compute its remainder when divided by 10
*	Subtract 9 by the remainder
*	Print the value
*End
**********************************************************************************************************/
#include <stdio.h>

int main() {																								//Begin
	int a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q;

	printf("Please insert the first 12 digits of an EAN: ");
	scanf_s("%1d%1d%1d%1d%1d%1d%1d%1d%1d%1d%1d%1d", &a, &b, &c, &d, &e, &f, &g, &h, &i, &j, &k, &l);		//Ask the user for the first 12 digits of an EAN

	m = b + d + f + h + j + l;																				//Add the second, fourth, sixth, eigth, tenth and telfth digits
	n = a + c + e + g + i + k;																				//Add the first, third, fifth, seventh, ninth, and eleventh digits
	o = (m * 3) + n;																						//Multiply the first sum by 3 and add it to the second sum
	o--;																									//Subtract it all by 1 (using a decrement instead of a subtraction to show I understand how to do more than just operands with a precedence of 3 and 4)
	p = o % 10;																								//Compute its remainder when divided by 10
	q = 9 - p;																								//Subtract 9 by the remainder

	printf("\nCheck digit: %d\n", q);																		//Print the value

	return 0;
}																											//End