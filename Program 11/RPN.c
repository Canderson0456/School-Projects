/*********************************************************************************************************
*Program: RPN.c
*
*Summary: Using multiple files, calculate an equation in reverse polish notation
***********************************************************************************************************
*Function: Main
*
*Summary: Ask for and get user input, calculate input. End program when input is not number or operator
***********************************************************************************************************
*Input: None
*
*Output: 0
***********************************************************************************************************
*Psuedocode:
*
*Begin
*	while(the user hasn't input something other than a number or a mathematical operator)
*		Ask user for an RPN expression
*		Get our input/RPN
*			While(there is still input to read)
*				Put numbers on the stack
*				Evaluate if there is an operator
*				Print if we see a =
*				Look at the next char
*			Endwhile
*	Endwhile
*	Return 0
*End
**********************************************************************************************************/
#include<stdio.h>
#include<stdlib.h>
#include"stack.h"

void clear(void);

int main() {							//Begin
	int n = 0, in = 0;

	while (n == 0) {						//while(the user hasn't input something other than a number or a mathematical operator)
		make_empty();
		printf("Enter an RPN expression: ");	//Ask user for an RPN expression
		while (in = getchar()){					//Get our input/RPN, While(there is still input to read)
			if (in == '\n')							//if we come across a newline character, break
				break;
			if (stack_overflow()) {					//if we try to input more than can be stored, tell user and reset
				printf("Expression is too complex\n");
				clear();
				break;
			}
			if (stack_underflow()) {				//if we try to process more numbers than we actually have, tell user and reset
				printf("Not enough operands in expression\n");
				clear();
				break;
			}
			int tmp1 = 0, tmp2 = 0;
			if (n == 0) {							//if we have not input a letter yet
				switch (in) {							//switch(process the input we received)
					case 10:								//in the case that we have a newline character(which shouldn't ever happen, but redundancy for redundancy sake), look at next input
						break;
					case 0:									//if we see a null character, look at next input
						break;
					case ' ':								//if we see a space, look to next input
						break;
					case '*':								//if we see a star, multiply the two most recent numbers on the stack
						push(pop() * pop());
						break;
					case '+':								//if we see a plus, add the last two numbers
						push(pop() + pop());
						break;
					case '/':								//if we see a /, divide the last two numbers
						tmp2 = pop();						//have to use tmp1 and tmp2 so we can divide in the right order. addition and multiplication didn't have this issue
						tmp1 = pop();
						push(tmp1 / tmp2);
						break;
					case '-':								//if we see a minus, subtract last two numbers
						tmp2 = pop();						//(in proper order)
						tmp1 = pop();
						push(tmp1 - tmp2);
						break;
					case '=':								//if we see an =, print our result
						printf("Value of expression: %d\n", pop());
						break;
					case '0':								//put a 0 on the stack			//Put numbers on the stack
						push(in - 48);
						break;
					case '1':								//put a 1 on the stack						  |
						push(in - 48);
						break;
					case '2':								//put a 2 on the stack						  |
						push(in - 48);
						break;
					case '3':								//etc.										  V
						push(in - 48);
						break;
					case '4':
						push(in - 48);
						break;
					case '5':
						push(in - 48);
						break;
					case '6':
						push(in - 48);
						break;
					case '7':
						push(in - 48);
						break;
					case '8':
						push(in - 48);
						break;
					case '9':
						push(in - 48);
						break;
					default:								//if we input anything else, end the program
						n = 1;
						break;
					}
				}
			else
				break;
		}
	}
}

/**********************************************************************************************************
*Function: Clear
*
*Summary: Clear the input buffer, or wait for an input if you call this function at the wrong time
***********************************************************************************************************
*Input: None
*
*Output: None
***********************************************************************************************************
*Psuedocode:
*
*Begin
*	while(there are still characters in the input buffer, trash 'em)
*End
**********************************************************************************************************/

void clear(void) {				//Begin
	while (getchar() != '\n');		//while(there are still characters in the input buffer, trash 'em)
}								//End

//I feel a little silly writing out the whole psuedocode block for that...