// --------------------------------------------------------------------------------
// AUTHOR:               Elias Howell
// FILENAME:             barScanner.c
// SPECIFICATION:        A barcode scanner that verifies a 12 digit code by comparing the code's last digit
//                          to its own "check digit" computation
// FOR:                  CS 1412 Programming Principles II Section 002

#include <stdio.h>

int main()
{
    int code[12], i = 0, checkDigit, computation;   //code[12] is 12 digit barcode, i is a counter, computation is specific barcode comparison operation
    
    while(scanf("%d", &code[i++]) && i < 12);   //Only accepts first 12 values, otherwise discarded if > 12

    computation = (code[0] + code[2] + code[4] + code[6] + code[8] + code[10]) * 3 + (code[1] + code[3] + code[5] + code[7] + code[9]);
    printf("Label: %d\n", computation);

    //If last digit of computation matches last digit of barcode checkDigit is 0, otherwise checkDigit is 10 minus last digit of computation
    if(computation % 10 == 0)
        checkDigit = 0;
    else
        checkDigit = 10 - computation % 10;
    printf("Check digit is: %d\n", checkDigit);

    //If checkDigit matches last digit of scanned barcode, code is validated, otherwise, error in barcode
    if(checkDigit == code[11])
        printf("validated\n");
    else
        printf("error in barcode\n");
    
    return 0;
}