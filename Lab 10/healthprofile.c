// --------------------------------------------------------------------------------
// AUTHOR:               Elias Howell
// FILENAME:             healthprofile.c
// SPECIFICATION:        Program utilizes a structure to store and calculate health records for patients
// FOR:                  CS 1412 Programming Principles II Section 002
#include <stdio.h>

struct HealthProfile
{
	char first[50];	//First name
	char last[50];	//Last name
	int month;		//Date of birth
	int year;		//Date of birth
	int day;		//Date of birth
	char gender;	//M or F
	double height;	//Centimeters
	double weight;	//Kilograms
	double maxhr;	//Max heart rate
	double thrr[2];	//Target heart rate range
	double bmi;		//Body mass index
	int age;
}	patient;

//Gets patient data and prints patient data
void getData(struct HealthProfile patient)
{
	printf("Enter first name: ");
	scanf(" %s", &patient.first);
	printf("Enter last name: ");
	scanf(" %s", &patient.last);
	printf("Enter month of birth (1-12): ");
	scanf(" %d", &patient.month);
	printf("Enter day of birth (1-31): ");
	scanf(" %d", &patient.day);
	printf("Enter year of birth: ");
	scanf(" %d", &patient.year);
	printf("Enter gender (m or f): ");
	scanf(" %c", &patient.gender);
	printf("Enter height (in Centimeters): ");
	scanf(" %lf", &patient.height);
	printf("Enter weight (in Kilograms): ");
	scanf(" %lf", &patient.weight);

	patient.bmi = patient.weight / ((patient.height / 100) * (patient.height / 100));	//weight / height^2
	patient.age = 2020 - patient.year;													//present year - year born
	patient.maxhr = 220 - patient.age;													//max heart rate is 220 - age
	patient.thrr[0] = patient.maxhr * .5;												//50% bottom heart rate
	patient.thrr[1] = patient.maxhr * .85;												//85% high end heart rate

	//User Data
	printf("\n\nName: %s %s\n", patient.first, patient.last);
	printf("Date Of Birth: %d/%d/%d\n", patient.month, patient.day, patient.year);
	printf("Age: %d\n", patient.age);
	printf("BMI (body mass index): %.0lf\n", patient.bmi);
	printf("Maximum Heart Rate: %.0lf\n", patient.maxhr); 
	printf("Target Heart Rate: %.0lf - %.0lf\n", patient.thrr[0], patient.thrr[1]);
	printf("Height: %.0lf Centimeters\n", patient.height);
	printf("Weight: %.0lf Kilograms\n\n\n", patient.weight);

	//Reference Chart
	printf("AGE		TARGET ZONE		AVERAGE MAX\n");
	printf("20 years	100-170 bpm		200 bpm\n");
	printf("30 years	95-162  bpm		190 bpm\n");
	printf("35 years	93-157  bpm		185 bpm\n");
	printf("40 years	90-153  bpm		180 bpm\n");
	printf("45 years	88-149  bpm		175 bpm\n");
	printf("50 years	85-145  bpm		170 bpm\n");
	printf("55 years	83-140  bpm		165 bpm\n");
	printf("60 years	80-136  bpm		160 bpm\n");
	printf("65 years	78-132  bpm		155 bpm\n");
	printf("70 years	75-128  bpm		150 bpm\n\n");
}

int main()
{
	getData(patient);
}