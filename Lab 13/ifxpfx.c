// --------------------------------------------------------------------------------
// AUTHOR:               Elias Howell
// FILENAME:             ifxpfx.c
// SPECIFICATION:        This program converts an ordinary infix arithmetic expression to a postfix expression.
// FOR:                  CS 1412 Programming Principles II Section 002


/* 				Additional Comments
 * I eliminated superfluous or unncessary code that I noticed in the assignment sheet.
 * I recently switched coding style from Allman to KNF BSD as I think it looks better.
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


/* I set the size of the stack to 300 as I can't imagine you entering a larger expression. */
char stack[300];
int top = -1;


void convertToPostfix(char infix[], char postfix[]);
void push(char c);
char pop();
int isOperator(char c);
int precedence(char operator);


int main(int argc, char *argv[]) {
	
	char infix[300];	/* This is the infix expression defined by the user. */
	char postfix[300];	/* This is the converted postfix expression. */
	
	printf("\nEnter expression using single digit integers: ");
	scanf(" %[^\n]%*c", infix);
	
	convertToPostfix(infix, postfix);
	
	puts("\nPostfix");
	puts(postfix);
	
	return (0);
	
}


/* Determines if character c is an operator. */
int isOperator(char c) {
	if (c == '+' || c == '^' || c == '*' ||	c == '/' || c == '%' || c == '-')
		return (1);
	else
		return (0);
}


/* Determines precedence of an operator by returning 0-3 (least to greatest). */
int precedence(char operator) {
	if (operator == '-' || '+')
		return (1);
	else if (operator == '/' || '*')
		return (2);
	else if (operator == '%' || operator == '^')
		return (3);
	else
		return (0);
}


/* Pushes character c to the top of the stack. */
void push(char c) {
	if (top >= 299)
		exit (0);
	else {
		top += 1;
		stack[top] = c;
	}
}


/* If the stack isn't empty, set character c equal to the top of the stack. */
char pop() {
	char c;
	
	if (top <= -1)
		exit (0);
	else {
		c = stack[top];
		top -= 1;
		return (c);
	}
}


/* This function converts the original infix expression to postfix */
void convertToPostfix(char infix[], char postfix[]) {
	/* Iterables: i and j .
	 * Infix/Postfix Characters: c and x.
	*/
	int i = 0;
	int j = 0;
	char c, x;
	
	push('(');
	strcat(infix, ")");
	
	c = infix[i];
	
	/* This while loop iterates through the provided infix expression character by character until it reaches NULL. */
	while (c != NULL) {
		if (c == '(') {
			push(c);
			push(' ');
		}
		else if (isalnum(c)) {
			postfix[j] = c;
			j += 1;
		}
		else if (isOperator(c) == 1) {
			x = pop();
			/* Append operator to the postfix expression while operator x is greater or equal than operator c. */
			while (precedence(x) >= precedence(c) && isOperator(x) == 1) {
				postfix[j] = x;
				j += 1;
				x = pop();
			}
			/* Push the analyzed operator to the stack, and add a space. */
			push(x);
			push(c);
			push(' ');
		}
		/* If iteration finds closing parenthesis pop() until it reaches an opening parenthesis. */
		else if (c == ')') {
			x = pop();
			while (x != '(') {
				postfix[j] = x;
				j += 1;
				x = pop();
			}
		}
		/* Invalid character found in expression, terminate program. */
		else if (c != ' ') {
			printf("\nInvalid character(s) found in your expression... Better luck next time.\n");
			exit (0);
		}
		i += 1;
		c = infix[i];
	}
	postfix[j] = NULL;
}