// --------------------------------------------------------------------------------
// AUTHOR:               Elias Howell
// FILENAME:             ivRates.c
// SPECIFICATION:        Program assists with various calculations for intravenous rates.
// FOR:                  CS 1412 Programming Principles II Section 002

//Quite unclear as to what exactly some of the functions listed in the handout are supposed to be doing.
//I assumed the example text in blue were input, and that the concentrations were provided by the user
//	thus the functions having to do with concentrations were highly confusing or deemed unnecessary.

#include <stdio.h>

int main()
{
	printf("INTRAVENOUS RATE ASSISTANT\n\n");
	
	int choice = get_problem();	//User defined choice

	//Loops while option 5 to quit isn't chosen
	while(choice != 5)
	{
		switch(choice)
		{
			case 1:
				get_rate_drop_factor();
				break;
			case 2:
				fig_ml_hr();
				break;
			case 3:
				by_weight();
				break;
			case 4:
				by_units();
				break;
			default:
				break;
		}
		choice = get_problem();
	}

	return 0;
}

//Gets user selection from menu
int get_problem()
{
	int choice;

	printf("Enter the number of the problem you wish to solve.\n");
	printf("%4cGIVEN A MEDICAL ORDER IN");
	printf("%-16cCALCULATE RATE IN\n");
	printf("(1) ml/hr & tubing drop factor %-12c drops / min\n");
	printf("(2) 1 L for n hr %-26c ml / hr\n");
	printf("(3) mg/kg/hr & concentration in mg/ml %-5c ml / hr\n");
	printf("(4) units/hr & concentration in units/ml %-2c ml / hr\n");
	printf("(5) QUIT\n\n");
	printf("Problem=> ");
	scanf("%d", &choice);

	return choice;
}

//Prompts user to enter data required to calculate drop rate per minute
int get_rate_drop_factor()
{
	double rate;
	double dropFactor;	//Tubing drop factor
	double dropRate;

	printf("Enter rate in ml/hr=> ");
	scanf("%lf", &rate);
	printf("Enter tubing's drop factor(drops/ml)=> ");
	scanf("%lf", &dropFactor);
	dropRate = rate * (dropFactor / 60);
	printf("The drop rate per minute is %.0lf.\n\n", dropRate);
}

//Calculates drop rate per hour
int fig_ml_hr()
{
	int hours;
	double rate;

	printf("Enter number of hours=> ");
	scanf("%d", &hours);
	rate = 1000 / hours;
	printf("The rate in mililiters per hour is %.0lf.\n\n", rate);
}

//Calculates drop rate by weight
int by_weight()
{
	double rate;			//rate in mg or kg
	double dropRate;		//IV drop rate
	double weight;			//user weight
	double concentration;

	printf("Enter rate in mg/kg/hr=> ");
	scanf("%lf", &rate);
	printf("Enter patiet weight in kg=> ");
	scanf("%lf", &weight);
	printf("Enter concentration in units/ml=> ");
	scanf("%lf", &concentration);
	dropRate = concentration * rate * weight;
	printf("The rate in mililiters per hour is %.0lf.\n\n", dropRate);
}

//Calculates drop rate by units
int by_units()
{
	double rate;			//Rates in units/hr
	double concentration;
	double dropRate;		//IV drop rate

	printf("Enter rate in units/hr=> ");
	scanf("%lf", &rate);
	printf("Enter concentration in units/ml=> ");
	scanf("%lf", &concentration);
	dropRate = rate / concentration;
	printf("The drop rate per minute is %.0lf.\n\n", dropRate);
}
