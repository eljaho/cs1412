// --------------------------------------------------------------------------------
// AUTHOR:               Elias Howell
// FILENAME:             ars.c
// SPECIFICATION:        Program creates a reservation for a user by receiving input and creating/updating reservation.txt
//												by storing that information.
// FOR:                  CS 1412 Programming Principles II Section 002
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

struct reservation
{
	int flightNo;
	int fcSeatsAvail;	//First class seats available
	int fcSeatsSold;	//First class seats sold
	int coachSeatsAvailable;
	int coachSeatsSold;
	int departureTime;
	int arrivalTime;
	char arrivalDate[50];
	char departureDate[50];
	char destination[50];
	char departureCity[50];
}customer;

//Creates reservation for a customer. This includes getting customer input, and storing their information in a text file
//	to create a reservation.
void make_reservation(struct reservation customer)
{
	FILE *o;
	o = fopen("reservation.txt", "w");

	printf("\nEnter flight number: ");
	scanf(" %d", &customer.flightNo);
	fprintf(o, "Flight number: %d", customer.flightNo);
	fputs("\n", o);

	printf("Enter city of departure: ");
	scanf(" %s", &customer.departureCity);
	fputs("Leaving from: ", o);
	fputs(customer.departureCity, o);
	fputs("\n", o);

	printf("Enter city destination: ");
	scanf(" %s", &customer.destination);
	fputs("Destination: ", o);
	fputs(customer.destination, o);
	fputs("\n", o);

	printf("Enter the date of departure (DDMMYY): ");
	scanf(" %s", &customer.departureDate);
	fputs("Date of departure: ", o);
	fputs(customer.departureDate, o);
	fputs("\n", o);

	printf("Enter the time of departure (HHMM): ");
	scanf(" %d", &customer.departureTime);
	fprintf(o, "Time of departure: %d", customer.departureTime);
	fputs("\n", o);

	printf("Enter the date of arrival (DDMMYY): ");
	scanf(" %s", &customer.arrivalDate);
	fputs("Date of arrival: ", o);
	fputs(customer.arrivalDate, o);
	fputs("\n", o);

	printf("Enter the time of arrival (HHMM): ");
	scanf(" %d", &customer.arrivalTime);
	fprintf(o, "Time of arrival: %d", customer.arrivalTime);
	fputs("\n", o);

	printf("Number of first-class seats still available: ");
	scanf(" %d", &customer.fcSeatsAvail);
	fprintf(o, "Number of first-class seats still available: %d", customer.fcSeatsAvail);
	fputs("\n", o);

	printf("Number of first-class seats sold: ");
	scanf(" %d", &customer.fcSeatsSold);
	fprintf(o, "Number of first-class seats sold: %d", customer.fcSeatsSold);
	fputs("\n", o);

	printf("Number of coach seats still available: ");
	scanf(" %d", &customer.coachSeatsAvailable);
	fprintf(o, "Number of coach seats still available: %d", customer.coachSeatsAvailable);
	fputs("\n", o);

	printf("Number of coach seats sold: ");
	scanf(" %d", &customer.coachSeatsSold);
	fprintf(o, "Number of coach seats sold: %d", customer.coachSeatsSold);
	fputs("\n", o);

	fclose(o);
	printf("\nReservation created... reservation.txt updated.\n\n");
}

//Cancels the previously reserved flight and updating their reservation.txt
void cancel_reservation(struct reservation customer)
{
	FILE *o;
	o = fopen("reservation.txt", "w");
	fputs("Reservation has been cancelled.", o);
	fclose(o);
	printf("\nReservation cancelled... reservation.txt updated.\n\n");
}

int main()
{
	int selection;

	printf("1. Schedule your reservation\n2. Update a reservation\n3. Cancel a reservation.\n\nSelection (1, 2, or 3): ");
	scanf("%d", &selection);
	switch(selection)
	{
		case 1:
			make_reservation(customer);
			break;
		case 2:
			make_reservation(customer);
			break;
		case 3:
			cancel_reservation(customer);
			break;
		default:
			printf("Invalid selection.");
			break;
	}

	return 0;
}
//test
