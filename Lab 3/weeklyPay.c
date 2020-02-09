// --------------------------------------------------------------------------------
// AUTHOR:               Elias Howell
// FILENAME:             weeklyPay.c
// SPECIFICATION:        Calculates weekly pay for various employees
// FOR:                  CS 1412 Programming Principles II Section 002

#include <stdio.h>

int main()
{
	double pay;			//Employee weekly pay
	double salary;			//Employee salary provided by user
	double sales;			//Gross sales
	double hourlyWage;		//Hourly hourly
	int ot;				//Overtime hours
	int hours;			//Hours worked
	int managers = 0;		//Number of managers
	int items;			//Number of items
	int workers = 0;		//Number of workers
	int comWorkers = 0;		//Number of commisioned workers
	int pieceWorkers = 0;		//Number of piece workers
	int code;			//Employee code

	//Loops until user exits with -1, keeps track of employees paid by incrementing +1, calculations vary between employees
	while(code != -1)
	{
		printf("\nEnter paycode ( -1 to end): ");
		scanf("%d", &code);
		switch(code)
		{
			case -1:
				break;
			case 1:
				printf("Manager selected.\n");
				printf("Enter weekly salary: $");
				scanf("%lf", &pay);
				printf("The manager's pay is $%.2lf.\n", pay);	//Manager gets has a base weekly salary
				managers++;
				break;
			case 2:
				printf("Worker selected.\n");
				printf("Enter hours worked: ");
				scanf("%d", &hours);
				printf("Enter hourly wage: ");
				scanf("%lf", &hourlyWage);
				if(hours > 40)
				{
					ot = hours - 40;
					pay = (hourlyWage * 40) + (ot * (hourlyWage * 1.5));	//Calculates time and a half
				}
				else
				{
					pay = (hourlyWage * hours);
				}
				printf("The hourly workers pay is $%.2lf.\n", pay);
				workers++;
				break;
			case 3:
				printf("Commisioned worker selected.\n");
				printf("Enter gross weekly sales: $");
				scanf("%lf", &sales);
				pay = 250 + (sales * .057);	//Base 250 plus 5.7 percent of sales
				printf("The commisioned workers pay is $%.2lf.\n", pay);
				comWorkers++;
				break;
			case 4:
				printf("Piece worker selected.\n");
				printf("Enter number of items produced: ");
				scanf("%d", &items);
				pay = items * 10.68;	//Number of items created times base pay per item
				printf("The piece workers pay is: $%.2lf.\n", pay);
				pieceWorkers++;
				break;
			default:
				printf("Invalid pay code\n");
		}
		printf("\nTotal number of managers paid: %d\n", managers);
		printf("Total number of hourly workers paid: %d\n", workers);
		printf("Total number of commission workers paid: %d\n", comWorkers);
		printf("Total number of piece workers paid: %d\n", pieceWorkers);
	}

	return 0;
}
