/*********************************************************************************************************
*Program: Final.c
*
*Summary: Takes a filename from the command line, and outputs sorted floats and 3 roots into a file
*	cont: also specified in the command line.
***********************************************************************************************************
*Function: Main
*
*Summary: Take a filename from the command line, views the file's contents as input, sorts the values
*	cont: and deletes duplicates, calculates multiple roots of the input values, and outputs them to a
*	cont: file named by the user in the command line.
***********************************************************************************************************
*Input: 2 Command line arguments
*
*Output: 0
***********************************************************************************************************
*Psuedocode:
*
*Begin
*	if we don't have enough command line arguments, or too many
*		inform the user of an error
*	endif
*
*	fopen(the input file specified in the command line in read mode) //print an error and terminate if it can't be read
*	fopen(the output file in write mode)	//print an error and terminate if it can't open the output file
*
*	while(End of File has not been reached yet)
*		fscanf(read an int)
*		give an error if int isn't between 0 and 99 inclusive
*		if(there was no error)
*			put our int in a linked list
*		endif
*	endwhile
*
*	while(we still have values left in our linked list)
*		print our value, its square root, cube root, and 4th root into a file(named in the command line)
*	endwhile
*
*	return 0
*End
**********************************************************************************************************/
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include"myLinkedList.h"

int main(int argc, char* argv[]) {			//Begin
	_Bool many = 0, few = 0, error = 0;
	FILE* fi, * fo;
	int in;
	double one = 1, third = 3, fourth = 4;
	struct node* list = NULL, *read;

	if (argc < 3) {								//If we don't have enough command line arguments
		printf("Too few arguments!");
		few = 1;
	}

	if (argc > 3) {								//or too many
		printf("Too many arguments!");				//inform the user of an error
		many = 1;
	}

	if (!(fi = fopen(argv[1], "r+")) && !many && !few) {//fopen(the input file specified in the command line in read mode)
		printf("Can't open file %s.", argv[1]);		//print an error and terminate if it can't be read
		error = 1;
	}

	if (!(fo = fopen(argv[2], "w")) && !many && !few) {//fopen(the output file in write mode)
		printf("Can't open file %s.", argv[2]);		//print an error and terminate if it can't open the output file
		error = 1;
	}

	if (!error && !few && !many) {				//if not terminating/had an error
		while (1) {									//while(
			if (feof(fi)) {								//End of File has not been reached yet)
				break;
			}
			fscanf(fi, "%d", &in);					 	//fscanf(read an int)
			if (in < 0 || in > 99) {						//give an error if int isn't between 0 and 99 inclusive
				printf("Input %d not between 0 and 99 inclusive, skipping\n",
					in);
			}
			else {										//if(there was no error)	
				list = newSortNode(in, list);			//put our int in a linked list
			}											//endif
		}											//endwhile
		
		read = list;

		while (read->next != NULL) {					//while(we still have values left in our linked list)
			fprintf(fo, "%5d\t%5.3lf\t%5.3lf\t%5.3lf\n", read->val, //print our value, its square root, cube root, and 4th root into a file(named in the command line)
				sqrt(read->val), pow(read->val, (one / third)), pow(read->val, (one / fourth)));

			read = read->next;
		}											//endwhile

		fprintf(fo, "%5d\t%5.3lf\t%5.3lf\t%5.3lf\n", read->val, //I made the loop slightly wrong, needed one more print
			sqrt(read->val), pow(read->val, (one / third)), pow(read->val, (one / fourth)));

		fclose(fi);									//cleaning up our workstation
		fclose(fo);
		
		while(list->next != NULL) {					//freeing our linked list
			read = list->next;
			
			free(list);
			
			list = read;
		}
		free(list);
	}											//endif

	return 0;									//return 0
}											//end