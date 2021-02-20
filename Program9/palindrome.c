/*********************************************************************************************************
*Program: Palindrome.c
*
*Summary: Ask the user for a word/phrase, then tell them if that word/phrase is a palindrome
***********************************************************************************************************
*Function: Main
*
*Summary: Initialize a bunch of stuff, ask for an input, send input to a function
*	(cont): print something based off how the function returns.
***********************************************************************************************************
*Input: None
*
*Output: 0
***********************************************************************************************************
*Psuedocode:
*
*Begin
*	Ask user for a word/phrase
*	Pass through user input to a function
*	Based off functions return value, print something
*	Return 0
*End
**********************************************************************************************************/
#include<stdio.h>
#define STRING_MAX 100
#define TRUE 1
#define FALSE 0

int is_palindrome(char *b, int size);

int main(){								//Begin
	char phrase[STRING_MAX];
	int size = 0;							//Was going to use a char, as it should be less than 100 at all times, let alone 127/255, but int makes it easier to read, and allows for much larger strings, if you change the STRING_MAX
	
	printf("Enter a word/phrase: ");		//Ask user for a word/phrase
	for(char *current = phrase; *(current - 1) != '\n' &&
		current - phrase < STRING_MAX;current++){
			scanf("%c", current);
			size++;
	}
	
	if(is_palindrome(phrase, size) == TRUE)	//Based off functions return value,
		printf("The word/phrase is a palindrome.");	//Print something
	else
		printf("The word/phrase is not a palindrome.");
	
	return 0;								//Return 0
}										//End

/**********************************************************************************************************
*Function: is_palindrome
*
*Summary: Takes a "string" and checks if it a palindrome or not
***********************************************************************************************************
*Input: A pointer to the first element of an array, and a number representing the array size
*
*Output: 0 or 1
***********************************************************************************************************
*Psuedocode:
*
*Begin
*	Read through a given string,
*		For(as long as there are letters we have yet to compare)
*			While(the last charcter isn't a letter)
*				Look at the character before it instead
*			End while loop
*			While(the first character isn't a letter)
*				Look at the character after it instead
*			End while loop
*			If(the last character is the same as the first character, or the capitalized/lowercase version)
*				Increment the first character being read, decrement the last
*			Else
*				Return 0
*		End for loop
*	Stop Reading
*	Return 1
*End
**********************************************************************************************************/

int is_palindrome(char *b, int size){				//Begin
	char *e = (b + (size - 1));							//e(nd) is being told to point to the last used/filled element in the array that b(eginning) points to the first element of
														//Read through a given string,
	for(;e >= b;e--, b++){									//For(as long as there are letters we have yet to compare)
		
		while(*e > 'z' || *e < 'a' && *e > 'Z' || *e < 'A'){	//While(the last character isn't a letter)	//using the chars instead of the ascii values for ease of reading and writing
			e--;													//Look at the character before it instead
		}														//End while loop
		
		while(*b < 'A' || *b > 'Z' && *b < 'a' || *b > 'z'){	//While(the first character isn't a letter)
			b++;													//Look at the character after it instead
		}														//End while loop
			
		if(*e == *b || (*e - 32) == *b || (*e + 32) == *b){		//If(the last character is the same as the first character, or the capitalized/lowercase version)
			e--; b++;												//Increment the first character being read, and decrement the last
		}
		else													//Else
			return FALSE;											//Return 0
	}														//End for loop
														//Stop Reading
	return TRUE;										//Return 1
}													//End