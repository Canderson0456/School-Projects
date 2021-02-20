/*********************************************************************************************************
*Program: RaggedSort.c
*
*Summary: Using command line input, receive a number of strings, and then sort them alphabetically
***********************************************************************************************************
*Function: Main
*
*Summary: Using command line input, receive a number of strings, and then sort them alphabetically
***********************************************************************************************************
*Input: Integer (from command line)
*
*Output: 0
***********************************************************************************************************
*Psuedocode:
*
*Begin
*	create an array of pointers(as many as the user specifies in command line)
*	for(however many words the user wants to enter)
*		printf(tell user to input word)
*		scanf(words to put in a temporary variable)
*		malloc a pointer in array created at start to store the word we just got
*		put word in newly allocated pointer
*	endfor
*	for(as many words as was input)
*		make every letter lowercase
*	endfor
*	Start sorting...
*	for(as long as it would take to put the last word into the first position in the array)
*		for(as many words as the user input - 1 (so [i+1] won't go into memory outside of array))
*			if(the first word is further in the alphabet than the second)
*				swap [i] and [i+1] word's positions in array
*			endif
*		endfor
*	endfor
*	for(as many words as the user input)
*		printf(every word in the now (hopefully) sorted array)
*	endfor
*	return 0
*End
**********************************************************************************************************/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(int argc, char *argv[]){						//Begin
	char *strings[atoi(argv[1])], buff[15];					//Create an array of pointers(as many as the user specifies in command line), creating a temporary string variable to store our input in until we can store it in our raggedjaggedjaggedragged array
	int longest = 0;
	
	for(int i = 0; i < atoi(argv[1]); i++) {				//for(however many words the user wants to enter)	//take and store inputs								
		printf("Enter a word: ");								//tell user to input word
		scanf("%s", buff);										//scanf(words to put in a temporary vairable)
		strings[i] = malloc((strlen(buff) * sizeof(char)));		//malloc a pointer in array created at start to store the word we just got
		strcpy(strings[i], buff);								//put word in newly allocated pointer
	}														//end loop
	
	for(int i = 0; i < atoi(argv[1]); i++) {				//for(as many words as was input)
		for(int let = 0; let < strlen(strings[i]); let++) {		//for(as many letters there are in current word)
			if(strings[i][let] < 'a') {								//if(a word has an uppercase letter)
				strings[i][let] += 32;									//make ever letter lowercase
			}														//endif
		}														//endfor
	}														//endfor
		
	//Start sorting... (NO GOD. NO GOD NO PLEASE NO. NO. NO. NOOOOOOOOOOOOOOOOO)
	for(int it = 0; it < (atoi(argv[1]) - 1); it++){		//for(as long as it would take to put the last word into the first position in the array)
		for(int i = 0; i < (atoi(argv[1])-1); i++){				//for(as many words as the user input - 1 (so [i+1] won't go into memory outside of array))
			if(strcmp(strings[i], strings[i+1]) > 0){				//if(the first word is further in the alphabet than the second)
				strcpy(buff, strings[i]);
				strcpy(strings[i], strings[i+1]);						//swap [i] and [i+1] word's position in array
				strcpy(strings[i+1], buff);
			}														//endif
		}														//endfor
	}														//endfor
	
	printf("\nSorted words: ");
	
	for(int i = 0; i < atoi(argv[1]); i++) {				//for(as may words as the user input)
		printf("%s ", strings[i]);								//printf(every word in the now (hopefully) sorted array)
	}														//endfor
	
	return 0;												//return 0
}														//End