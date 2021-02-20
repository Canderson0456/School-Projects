#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#define DEBUG 0
#define MAX_STRING 21

/*********************************************************************************************************
*Program: SmLaWord.c
*
*Summary: User tells program how many words they want compared, and what words. Program tells you word
*	*cont: that comes first and last in alphabetical order/sort the smallest and largest word.
*	*cont:(I would call them alphabetically first and last, but we can be confusing. Job Security)
***********************************************************************************************************
*Function: Main
*
*Summary: Will receive words from user, finds the smallest and largest words, then prints what it finds
***********************************************************************************************************
*Input: A number from the command line
*
*Output: 0
***********************************************************************************************************
*Psuedocode:
*
*Begin
*	for(as long as the user still wants to put another word)
*		Ask user for a word
*	Endloop
*	Make sure every letter is lowercase
*	for(as long as there are more words to compare to)
*		find the smallest word(closest to int 'a')
*		find the largest word(Furthest from int 'a')
*	Endloop
*	Print the smallest and largest words
*	Return 0
*End
**********************************************************************************************************/

int main(int argc, char* argv[]) {					//Begin
	int i = 0, word_count = atoi(argv[1]), t;				

#if DEBUG
	printf("word# is %d\n", word_count);
#endif

	char words[word_count][MAX_STRING], * highest = *words;
	char* lowest = *words;

	for (i = 0; i < word_count; i++) {					//for(as long as the user wants to input another word)
		printf("Enter a word: ");							//ask user for a word
		scanf("%s", &words[i]);
	}

	for (i = 0; i < word_count; i++) {					//Make sure every letter is lowercase
		for (t = 0; t < strlen(words[i]); t++) {
			if (words[i][t] < 97 && words[i][t] != 0)
				words[i][t] += 32;
		}
	}

#if DEBUG
	for (i = 0; i < word_count; i++) {
		printf("%s", words[i]);
	}
#endif

	for (i = 0; i < word_count; i++) {					//for(as long as there are more words to compare to)
		
		if (words[i][0] < lowest[0]) {						//find the smallest word(closest to int 'a')
			lowest = words[i];								//checking our current smallest word's first letter with all other words first letters
		}
		else if (words[i][0] == lowest[0] && abs(strcmp(words[i], lowest))) {//checking if our smallest word and the word we are comparing it to are the same word
			for (t = 1; t < strlen(lowest) && t < strlen(words[i]); t++) {//if they aren't the same word, compare every letter in both words until we find one that is different
				if (words[i][t] < lowest[t]) {				//once we find that different letter, either make our comparison word the new smallest word, or...
					lowest = words[i];
					t = strlen(lowest) + strlen(words[i]);	//(i'm setting t to a large number to stop the loop because i thought it would look cooler than simply using a break...)
				}
				else if (lowest[t] < words[i][t]) {			//if the smallest word is still the smallest word, move on.
					break;
				}
			}
		}

		if (words[i][0] > highest[0]) {						//find the largest word(Furthest from int 'a')
			highest = words[i];
		}													//this is pretty much exactly the same thing as for the smallest word, but reversed to find the largest
		else if (words[i][0] == highest[0] && abs(strcmp(words[i], highest))) {//check largest with comparison word(as long as they aren't the same word)
			for (t = 1; t < strlen(highest) && t < strlen(words[i]); t++) {
				if (words[i][t] > highest[t]) {				//if new word larger, larger(highest) = new word
					highest = words[i];
					t = (strlen(words[i]) + strlen(highest));
				}
				else if (highest[t] > words[i][t]) {		//if old word larger, keep old word
					break;
				}
			}
		}
	}													//Endloop
	
	printf("\nSmallest word: %s\nLargest word: %s", lowest, highest);
														//Print the smallest and largest words

	return 0;											//return 0
}													//End