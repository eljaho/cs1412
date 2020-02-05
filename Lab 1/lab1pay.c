// --------------------------------------------------------------------------------
// AUTHOR:               Elias Howell
// FILENAME:             lab1pay.c
// SPECIFICATION:        Program calculates payment for a vehicle
// FOR:                  CS 1412 Programming Fundamentals II Section 002

#include <stdio.h>
#include <math.h>

int main()
{
  double payment, //Monthly payment
  principal,      //Amount borrowed
  monthlyInterest,//Monthly interest
  apr,            //Annual interest
  price,          //Price of vehicle
  downPay,        //Down payment
  numPayments;    //Number of payments (months)

  printf("Enter the purchase price: ");
  scanf("%lf", &price);
  printf("Enter the down payment: ");
  scanf("%lf", &downPay);
  printf("Enter the annual interest rate (percent): ");
  scanf("%lf", &apr);
  printf("Enter the total number of payments: ");
  scanf("%lf", &numPayments);

  //Calculates monthly interest
  monthlyInterest = (apr / 100) / 12;
  principal = price - downPay;
  payment = principal * (monthlyInterest * pow(1 + monthlyInterest, numPayments)) / (pow(1 + monthlyInterest, numPayments) - 1);

  printf("You borrowed $%.2lf and your monthly payment is $%.2lf. \n", principal, payment);

  return 0;
}
