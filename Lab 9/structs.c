// --------------------------------------------------------------------------------
// AUTHOR:               Elias Howell
// FILENAME:             structs.c
// SPECIFICATION:        Program utilizes a structure to store information about a product and prints that information
// FOR:                  CS 1412 Programming Principles II Section 002
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Item available for purchase in a market
struct item
{
	char type;
	char subtype;
	char side;		//aisle side A or B
	char name[20];
	int cost;
	int received;	//date received
	int packaged;	//date packaged
	int expires;	//expiration date
	int aisle;		//aisle no.
};

void scanner(struct item scanned);

int main()
{	
	struct item scanned;
	scanner(scanned);
	return 0;
}

//Function scans product information and prints product info depending on its product category
void scanner(struct item scanned)
{
	printf("Product Category ('M' for meat, 'P' for produce, 'D' for dairy, 'C' for canned goods, 'N' for nonfoods): ");
	scanf(" %c", &scanned.type);
	switch(scanned.type)
	{
		case 'M':
			printf("Product Name: ");
			scanf(" %s", &scanned.name);
			printf("Product Cost (in cents): ");
			scanf(" %d", &scanned.cost);
			printf("Product Category ('R' for red meat, 'P' for poultry, or 'F' for fish): ");
			scanf(" %c", &scanned.subtype);
			printf("Date Packaged (MMYY): ");
			scanf(" %d", &scanned.packaged);
			printf("Expiration Date (MMYY): ");
			scanf(" %d", &scanned.expires);
			printf("\n%s %dC %04d %04d %c\n", scanned.name, scanned.cost, scanned.expires, scanned.packaged, scanned.subtype);
			break;
		case 'P':
			printf("Product Name: ");
			scanf(" %s", &scanned.name);
			printf("Product Cost (in cents): ");
			scanf(" %d", &scanned.cost);
			printf("Product Category ('F' for fruit, or 'V' for vegetable): ");
			scanf(" %c", &scanned.subtype);
			printf("Date Received (MMYY): ");
			scanf(" %d", &scanned.received);
			printf("\n%s %dC %04d %c\n", scanned.name, scanned.cost, scanned.received, scanned.subtype);
			break;
		case 'D':
			printf("Product Name: ");
			scanf(" %s", &scanned.name);
			printf("Product Cost (in cents): ");
			scanf(" %d", &scanned.cost);
			printf("Expiration Date (MMYY): ");
			scanf(" %d", &scanned.expires);
			printf("\n%s %dC %04d\n", scanned.name, scanned.cost, scanned.expires);
			break;
		case 'C':
			printf("Product Name: ");
			scanf(" %s", &scanned.name);
			printf("Product Cost (in cents): ");
			scanf(" %d", &scanned.cost);
			printf("Expiration Date (MMYY): ");
			scanf(" %d", &scanned.expires);
			printf("Aisle Number: ");
			scanf(" %d", &scanned.aisle);
			printf("Aisle Side('A' or 'B'): ");
			scanf(" %c", &scanned.side);
			printf("\n%s %dC %04d %d%c\n", scanned.name, scanned.cost, scanned.expires, scanned.aisle, scanned.side);
			break;
		case 'N':
			printf("Product Name: ");
			scanf(" %s", &scanned.name);
			printf("Product Cost (in cents): ");
			scanf(" %d", &scanned.cost);
			printf("Second Product Category ('C' for cleaning product, 'P' for pharmacy, 'O' for other): ");
			scanf(" %c", &scanned.subtype);
			printf("Aisle Number: ");
			scanf(" %d", &scanned.aisle);
			printf("Aisle Side('A' or 'B'): ");
			scanf(" %c", &scanned.side);
			printf("\n%s %dC %d%c %c\n", scanned.name, scanned.cost, scanned.aisle, scanned.side, scanned.subtype);
			break;
		default:
			printf("\nInvalid category. Goodbye.\n");
			break;
	}
}
