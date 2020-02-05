// --------------------------------------------------------------------------------
// AUTHOR:               Elias Howell
// FILENAME:             rateOfDecay.c
// SPECIFICATION:        Calculates what's left of the isotope year by year for 5 years
// FOR:                  CS 1412 Programming Principles II Section 002

#include <stdio.h>
#include <math.h>

int main()
{
    double grams;       //Mass of isotope
    int year;           //Year increment
    double c = pow(2.71828, -0.693);    //e^-0.693
    
    printf("Enter the amount in grams of the isotope: ");    
    scanf("%lf", &grams);
    
    for(year = 1; year < 6; year++)     //Loops for the 5 year count
    {
        grams = grams * pow(c, (year/(5.272)));
        printf("Year %d | %.6lf grams\n", year, grams);
    }

    return 0;
}
