/*********************************************************************************************************
*Program: myLinkedList.c
*
*Summary: It's a linked list. That's about it.
***********************************************************************************************************
*Function: newSortNode
*
*Summary: Creates a new node to be used in the linked list, and places it at the end of the list
***********************************************************************************************************
*Input: A int to be stored in the node, and a pointer to the beginning of the list
*
*Output: A pointer to the first node of the linked list
***********************************************************************************************************
*Psuedocode:
*
*Begin
*	struct(a node, which is a int and a struct pointer)
*
*	allocate space for the new node
*	store our input int in our node
*	insert the node into our list, in a sorted order, deleting duplicates
*
*	return pointer pointing to the beginning of our list
*End
**********************************************************************************************************/
#include<stdio.h>
#include<stdlib.h>

struct node {
	int val;
	struct node* next;
};

struct node* newSortNode(int in, struct node* list) {								//Begin
	_Bool newList = 0;
	struct node* new = calloc(1, sizeof(struct node)), * beg = list, * read, * prev = list;	//struct(a node, which is a int and a struct pointer)

	new->val = in;																			//store our input int in our node

	if (list == NULL) {																		//starts our linked list, if this is the first node we are making
		beg = new;
		newList = 1;
	}

	read = list;

	if (!newList) {																			//insert the node into our list, in a sorted order, deleting duplicates
		_Bool done = 0;
		if (new->val > read->val) {																//if(our input is larger than the first node)
			new->next = read;																		//make our input node our new first node
			beg = new;
		}																						//endif
		else {
			_Bool loop = 0;
			while (new->val <= read->val) {														//while our input is less than the node we are looking at, find where it goes
				if (new->val == read->val) {														//if our input is a duplicate, delete our input node and return
					free(new);
					done = 1;
				}
				if (!done) {
					if (read->next == NULL) {														//if we have made it to the end of our linked list, just put our input at the end
						if (read->val > new->val) {													
							read->next = new;
							done = 1;
						}
						break;
					}
					else {																			//else look at the next node and loop again
						if (loop) {
							prev = prev->next;
						}
						read = read->next;
					}
					loop = 1;
				}
				else break;																			//if our input equaled a value in our list already, return
			}																					//endwhile
			if (!done) {																		//if we aren't returning, insert our node into the list, already found where it goes
				new->next = prev->next;
				prev->next = new;
			}
		}
	}																						//done with our new node

	return beg;																				//return pointer pointing to the beginning of our list
}																						//End