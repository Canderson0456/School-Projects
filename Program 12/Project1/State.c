/*********************************************************************************************************
*Program: State.c
*
*Summary: Using an array of structs, determine if an input is an abbreviation for a US state
***********************************************************************************************************
*Function: Main
*
*Summary: Ask for and get user input, determine if input is abbreviation for US state
***********************************************************************************************************
*Input: None
*
*Output: 0
***********************************************************************************************************
*Psuedocode:
*
*Begin
*	Do the hard part, initialize a constant array of structs, will take a while...
*	Ask for input
*	Make sure input is valid (only letters)
*	for(as long as there are still states to check)
*		if(input is the same as the abbreviation)
*			Tell user, break out of loop
*		endif
*	endfor
*	if(input didn't match anything)
*		tell user
*	endif
*
*	return 0
*End
**********************************************************************************************************/
#include<stdio.h>
#define USTERRITORIES 56

int main() {									//Begin
	struct state { char* name, * ab; };

	const struct state US[USTERRITORIES] =			//Do the hard part, initialize a constant array of structs, will take a while...
	{
	{"Alabama", "AL"}, {"Alaska", "AL"}, {"American Samoa", "AS"},
	{"Arizona", "AZ"}, {"Arkansas", "AR"}, {"California", "CA"},
	{"Colorado", "CO"}, {"Connecticut", "CT"}, {"Delaware", "DE"},
	{"District of Colombia", "DC"}, {"Florida", "FL"},
	{"Georgia", "GA"}, {"Guam", "GU"}, {"Hawaii", "HI"}, {"Idaho", "ID"},
	{"Illinois", "IL"}, {"Indiana", "IN"}, {"Iowa", "IA"},
	{"Kansas", "KS"}, {"Kentucky", "KY"}, {"Louisiana", "LA"},
	{"Maine", "ME"}, {"Maryland", "MD"}, {"Massachusetts", "MA"},
	{"Michigan", "MI"}, {"Minnesota", "MN"}, {"Mississippi", "MS"},
	{"Missouri", "MO"}, {"Montana", "MT"}, {"Nebraska", "NE"},
	{"Nevada", "NV"}, {"New Hampshire", "NH"}, {"New Jersey", "NJ"},
	{"New Mexico", "NM"}, {"New York", "NY"}, {"North Carolina", "NC"},
	{"North Dakota", "ND"}, {"Northern Mariana Is", "MP"}, {"Ohio", "OH"},
	{"Oklahoma", "OK"}, {"Oregon", "OR"}, {"Pennsylvania", "PA"},
	{"Puerto Rico", "PR"}, {"Rhode Island", "RI"}, {"South Carolina", "SC"},
	{"South Dakota", "SD"}, {"Tennessee", "TN"}, {"Texas", "TX"},
	{"Utah", "UT"}, {"Vermont", "VT"}, {"Virginia", "VA"},
	{"Virgin Islands", "VI"}, {"Washington", "WA"}, {"West Virginia", "WV"},
	{"Wisconsin", "WI"}, {"Wyoming", "WY"}
	};

	char input[3];
	int done = 0;

	printf("Enter a 2-letter U.S. state abbreviation: ");
	scanf_s("%s", &input, 3);						//Ask for input

	if((input[0] < 'A') || (input[0] > 'Z' && input[0] < 'a') || 
		(input[0] > 'z') || (input[1] < 'A') ||		//Make sure input is valid (only letters)
		(input[1] > 'Z' && input[1] < 'a') || (input[1] > 'z'))
		printf("Error, bad input");

	for (int i = 0; i < USTERRITORIES; i++) {		//for(as long as there are still states to check)
		if ((US[i].ab[0] == input[0] || US[i].ab[0] == input[0] - 32) && //if(input is the same as the abbreviation)
			(US[i].ab[1] == input[1] || US[i].ab[1] == input[1] - 32)) {
			printf("%s is an abbreviation for %s", input, US[i].name);
			done = 1;										//Tell user, break out of loop
			break;
		}												//endif
	}												//endfor

	if (done != 1)									//if(input didn't match anything)
		printf("%s is not an abbreviation for any of the 50 U.S. states.", input);//tell user
													//endif
	return 0;										//return 0;
}												//End