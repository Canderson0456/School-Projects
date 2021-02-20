/*********************************************************************************************************
*Program: walk.c
*
*Summary: Generates a "random walk" of letters across a grid
***********************************************************************************************************
*Input: None
*
*Output: A grid with a "random walk" of letters
***********************************************************************************************************
*Psuedocode:
*
*Begin
*	Fill our grid with '.'s
*	Make a few nested for loops
*		Make sure we save A first, then continue with the rest
*		Randomly choose a direction
*		Save our letter in the empty grid space we moved to
*		If the gridspace we were trying to move into is full, generate a new move and try again
*	Print our "walked" grid
*End
***********************************************************************************************************
*P.S.
*This ended up looking a little more elaborate than my psuedocode made it seem.
*I kind of wanted to add to my psuedocode, but I'm not sure what exactly to add, and psuedocode is 
*supposed to be written before the code, so...
**********************************************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define DEBUG 0
#define ROW 10
#define COLUMN 10

int main() {

	int x = 0, y = 0, move, g[ROW + 2][COLUMN + 2];

	srand((unsigned)time(NULL));													//Randomize every time you start

	for (x = 1; x < (ROW + 1); x++) {												//Fill our grid with '.'s, leaving an outside perimeter
		for (y = 1; y < (COLUMN + 1); y++) {
			g[x][y] = '.';
		}
	}

	for (x = 0; x < (ROW + 2); x++) {												//Make sure the perimeter is full of 0s
		g[x][0] = 0;
		g[x][11] = 0;
	}
	for (y = 0; y < (ROW + 2); y++) {
		g[0][y] = 0;
		g[11][y] = 0;
	}


	if (DEBUG == 1) {
		for (x = 0; x < (ROW + 2); x++) {
			if (y > 0) {
				printf("\n");
			}
			for (y = 0; y < (COLUMN + 2); y++) {
				printf("%c", g[x][y]);
			}
		}
	}

																					//Make a few nested for loops
	for (int letter = 65, previous = 64; letter < 91; letter++) {					//Make sure we know what letter we want to put in
		for (x = 1; x < (ROW + 1); x++) {											//Move through the rows
			for (y = 1; y < (COLUMN + 1); y++) {									//Move through the columns
				if (letter == 65 && x == 1 && y == 1) {								//Make sure we save A first, then continue with the rest
					g[x][y] = letter;
					previous += 1;
				}
				else if (g[x][y] == previous && previous != letter) {				//If we aren't printing A...
					move = rand() % 4;												//Randomly choose a direction
					for (int i = 0; i < 1;) {										//Fall back to this 'loop' after a break
						if (g[x + 1][y] != '.' && g[x - 1][y] != '.' && g[x][y		//If we are surrounded on all sides, just break
							 - 1] != '.' && g[x][y + 1] != '.') {								//until we are out of the for loops
							break;
						}
						else switch (move) {
						case 0:														//Move up
							if (g[x][y - 1] == '.' && previous != letter) {
								y -= 1;
								g[x][y] = letter;									//Save our letter in the empty grid space we moved to
								previous += 1;										//Here to make sure we don't print the same letter more than once
								if (DEBUG == 1) {									//Isn't debugging fun?
									printf("up\n");
								}
								i++;
								break;
							}
							else {
								move = (rand() % 4);
								break;
							}
						case 1:														//Move right
							if (g[x + 1][y] == '.' && previous != letter) {
								x += 1;
								g[x][y] = letter;									//Save our letter in the empty grid space we moved to
								previous += 1;
								if (DEBUG == 1) {
									printf("right\n");
								}
								i++;
								break;
							}
							else {
								move = (rand() % 4);
								break;
							}
						case 2:														//Move down
							if (g[x][y + 1] == '.' && previous != letter) {
								y += 1;
								g[x][y] = letter;									//Save our letter in the empty grid space we moved to
								previous += 1;
								if (DEBUG == 1) {
									printf("down\n");
								}
								i++;
								break;
							}
							else {
								move = (rand() % 4);
								break;
							}
						case 3:														//Move left
							if (g[x - 1][y] == '.' && previous != letter) {
								x -= 1;
								g[x][y] = letter;									//Save our letter in the empty grid space we moved to
								previous += 1;
								if (DEBUG == 1) {
									printf("left\n");
								}
								i++;
								break;
							}
							else {
								move = (rand() % 4);
								break;
							}
						default: printf("Something went wrong...");
							return 0;

						}
					}
				}
			}
		}
	}

	for (x = 1; x < (ROW + 1); x++) {												//Print our "walked" grid
		printf("\n");
		for (y = 1; y < (COLUMN + 1); y++) {
			if(y == 1) {
				printf(" ");														//Just here to try and make things look slightly better
			}
			printf("%c", g[x][y]);
		}
	}

	printf("\n");																	//Just here to try and make things look slightly better, again...

	return 0;
}