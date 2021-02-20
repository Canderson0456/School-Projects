RPN.exe: RPN.o stack.o
	gcc -o RPN.exe RPN.o stack.o

stack.o: stack.c stack.h
	gcc -c stack.c
	
RPN.o: RPN.c stack.c stack.h
	gcc -c RPN.c