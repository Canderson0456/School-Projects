/***********************************************************************************************************
*Program: n2t.c
*
*Summary: Asks the user for a number between 1 and 99 inclusive, then prints the number out in text form
************************************************************************************************************
*Psuedocode:
*
*Begin
*	Ask for a number between 1 and 99 inclusive
*	Seperate the tens place from the ones place
*	Convert the tens place into text and print
*	Convert the ones place into text and print
*End
***********************************************************************************************************/
#include <stdio.h>

int main(){																									//Begin
	int tens, ones, input, done;
	
	printf("Enter a two-digit number (1-99): ");															//Ask for a number between 1 and 99 inclusive
	scanf("%d", &input);
	
	if(input >= 1 && input <= 99) {																			//Makes sure the user is honest with their number
		tens = input/10;																					//Seperate the tens place from the ones place
		ones = input%10;
		printf("The English representation of %d is ", input);
		
		if(ones != 0){																						//Checks if we need to print a hyphen after the tens text
			switch (tens) {																					//Convert the tens place into text and print
				case 0:	break;
				case 1:	
					switch(ones) {
						case 1: printf("Eleven."); done = 1; break;											//Covers the slightly different naming conventions
						case 2: printf("Twelve."); done = 1;	break;											//given to two-digit numbers starting with a 1
						case 3: printf("Thirteen."); done = 1; break;
						case 4: printf("Fourteen."); done = 1; break;
						case 5: printf("Fifteen."); done = 1; break;
						case 6: printf("Sixteen."); done = 1; break;
						case 7: printf("Seventeen."); done = 1; break;
						case 8: printf("Eighteen."); done = 1; break;
						case 9: printf("Nineteen."); done = 1; break;
					}
					break;
				case 2: printf("Twenty-"); break;
				case 3: printf("Thirty-"); break;
				case 4: printf("Fourty-"); break;
				case 5: printf("Fifty-"); break;
				case 6: printf("Sixty-"); break;
				case 7: printf("Seventy-"); break;
				case 8: printf("Eighty-"); break;
				case 9: printf("Ninety-"); break;
			}
		}
		
		else
			switch(tens) {																					//Convert the tens place into text (Part 2, electric boogaloo)
				case 0: printf("Zero."); done = 1; break;													
				case 1: printf("Ten."); done = 1; break;														//The first "Convert tens place" printed the tens place given
				case 2: printf("Twenty."); done = 1; break;													//there was a number other than 0 in the ones place, this one
				case 3: printf("Thirty."); done = 1; break; 													//makes sure that we are covered even if we do have a 0.
				case 4: printf("Fourty."); done = 1; break;
				case 5: printf("Fifty."); done = 1; break;
				case 6: printf("Sixty."); done = 1; break;
				case 7: printf("Seventy."); done = 1; break;
				case 8: printf("Eighty."); done = 1; break;
				case 9: printf("Ninety."); done = 1; break;
			}
	}
	
	else
		printf("The value is not between 1 and 99 inclusive");											//Tells the user we know they are a liar, or put in the wrong number
		
	if(done != 1){																						//Makes sure we haven't already printed everything we need to
		switch(ones) {																					//Convert the ones place into text and print
			case 1: printf("One."); break;
			case 2: printf("Two."); break;
			case 3: printf("Three."); break;
			case 4: printf("Four."); break;
			case 5: printf("Five."); break;
			case 6: printf("Six."); break;
			case 7: printf("Seven."); break;
			case 8: printf("Eight."); break;
			case 9: printf("Nine."); break;
			}
		
		}
		
	return 0;
}																											//End