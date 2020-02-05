// --------------------------------------------------------------------------------
// AUTHOR:               Elias Howell
// FILENAME:             sheetmusic.c
// SPECIFICATION:        Program implements discount policies
// FOR:                  CS 1412 Programming Principles II Section 002

#include <stdio.h>

int main()
{
    double totalPurchase;   //Purchase total
    double salesTax;
    double discounted;      //Amount discounter
    double discountedTotal; 
    double total;           //Final total
    int teacher;            //Teacher or not?

    printf("\nEnter the purchase total: ");
    scanf("%lf", &totalPurchase);
    printf("If you are a teacher please enter a 1, otherwise enter a 0: ");
    scanf("%d", &teacher);

    if(totalPurchase >= 100 && teacher != 0)    //If purchase is greater than 100 and a teacher
    {
        discounted = totalPurchase * 0.12;      //12% discount
        discountedTotal = totalPurchase - discounted;
        salesTax = discountedTotal * 0.05;      //5% sales tax
        total = discountedTotal + salesTax;

        printf("\nTotal purchases             $ %.2lf \n", totalPurchase);
        printf("Teacher's discount (12%%)    %.2lf \n", discounted);
        printf("Discounted total            %.2lf \n", discountedTotal);
        printf("Sales tax (5%%)              %.2lf \n", salesTax);
        printf("Total                       $ %.2lf \n", total);
    }
    else if(total < 100 && teacher != 0)       //If purchase is less than 100 and a teacher
    {
        discounted = totalPurchase * 0.1;      //10% discount
        discountedTotal = totalPurchase - discounted;
        salesTax = discountedTotal * 0.05;     //Sales tax
        total = discountedTotal + salesTax;

        printf("\nTotal purchases             $ %.2lf \n", totalPurchase);
        printf("Teacher's discount (10%%)    %.2lf \n", discounted);
        printf("Discounted total            %.2lf \n", discountedTotal);
        printf("Sales tax (5%%)              %.2lf \n", salesTax);
        printf("Total                       $ %.2lf \n", total);
    }
    else    //Not a teacher
    {
        salesTax = totalPurchase * 0.05;       //Sales tax
        total = totalPurchase + salesTax;

        printf("\nTotal purchases             $ %.2lf \n", totalPurchase);
        printf("Sales tax (5%%)                 %.2lf \n", salesTax);
        printf("Total                       $ %.2lf \n", total);
    }

    return 0;
}
