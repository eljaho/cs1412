// --------------------------------------------------------------------------------
// AUTHOR:               Elias Howell
// FILENAME:             calculator.c
// SPECIFICATION:        A simple calculator used for basic calculations
// FOR:                  CS 1412 Programming Principles II Section 002

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void scan_data(char *operator, double *operand);
void do_next_op(char *operator, double *operand, double *total);

int main()
{
    char operator = 0;  //calculation to be made
    double operand = 0; //number to be operated upon
    double total = 0;   //running total or left hand operand

    //Loops until q is provided in scan_data to exit the program
    while(1 == 1)
    {
        scan_data(&operator, &operand);
        do_next_op(&operator, &operand, &total);

        //Exits if scanned operator is q and provides final result
        if(operator == 'q' || operator == 'Q')
        {
            printf("final result is %.1lf\n");
            exit(0);
        }
        else
            printf("result so far is %.1lf\n", total);
    }
    return 0;
}

//Scans input for a right hand operand and operator, confirms operator and operand are valid, q to quit
void scan_data(char *operator, double *operand)
{   
    if (scanf(" %c", &*operator) != 1)  //If not a character
        exit(0);
    if(scanf(" %lf", &*operand) != 1)   //If not a number
        exit(0);
    switch(*operator)
    {
        case '+':
            break;
        case '-':
            break;
        case '*':
            break;
        case '/':
            break;
        case '^':
            break;
        case 'q':
        case 'Q':
            break;
        default:
            exit(0);
    }
}

//Does next operation depending on scanned operator from scan_data
void do_next_op(char *operator, double *operand, double *total)
{
    switch(*operator)
    {
        case '+':
            *total = *total + *operand;
            break;
        case '-':
            *total = *total - *operand;
            break;
        case '*':
            *total = *total * *operand;
            break;
        case '/':
            *total = *total / *operand;
            break;
        case '^':
            *total = pow(*total, *operand);
            break;
    }
}