// --------------------------------------------------------------------------------
// AUTHOR:               Elias Howell
// FILENAME:             lab1mrc.c
// SPECIFICATION:        Program calculates mileage reimbursement at a rate of $.35 per mile.
// FOR:                  CS 1412 Programming Fundamentals II Section 002

#include <stdio.h>

int main()
{
  float
  beginOdometer,  //Starting mileage
  endOdometer,    //Ending mileage
  reimbursement,
  miles;

  printf("MILEAGE REIMBURSEMENT CALCULATOR\n");
  printf("Enter beginning odometer reading => ");
  scanf("%f", &beginOdometer);
  printf("Enter ending odometer reading => ");
  scanf("%f", &endOdometer);

  //Calculates reimbursement at 35 cents per mile
  miles = endOdometer - beginOdometer;
  reimbursement = miles * .35;

  printf("You traveled %.1f miles. At $0.35 per mile, your reimbursement is $ %.2f. \n", miles, reimbursement);

  return 0;
}
