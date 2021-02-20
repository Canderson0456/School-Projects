#include<stdbool.h>
#include<stdio.h>

#define STACK_SIZE 100

int contents[STACK_SIZE];		//Create an array of size STACK_SIZE

int top = 0, of = 0, uf = 0;	//Variables. Usefull.

int stack_overflow(void) {		//Inform if we have overflowed our array/stack
	return of;
}

int stack_underflow(void) {		//Ditto, but for underflow
	return uf;
}

void make_empty(void) {			//Basically reset everything and start from scratch
	top = 0;
	uf = 0;
	of = 0;
}

bool is_empty(void) {			//Informs if our array/stack is looking at the very beginning
	return top == 0;
}

bool is_full(void) {			//Informs if our array/stack has gone further than STACK_SIZE
	return top == STACK_SIZE;
}

void push(int i) {				//Puts a number on our stack(if it won't overflow it)
	if (is_full()) {
		++of;
	}
	else {
		contents[top++] = i;
	}
}

int pop(void) {					//Takes a number from our stack(if it won't underflow it)
	if (is_empty()) {
		++uf;
	}
	else
		return contents[--top];
}