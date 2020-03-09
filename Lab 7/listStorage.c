// --------------------------------------------------------------------------------
// AUTHOR:               Elias Howell
// FILENAME:             listStorage.c
// SPECIFICATION:        Stores lists of names and ages in parallel arrays, sorts names alphabetically, finds youngest and average age
// FOR:                  CS 1412 Programming Principles II Section 002
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void avgAge();
int youngest();

int main()
{   
    char *list[6] = {"Ryan, Elizabeth", "McIntyre, Osborne", "DuMond, Kristin", "Larson, Lois", "Thorpe, Trinity", "Ruiz, Pedro"}, temp[6][30]; //List of people, temporary array for alphabetizing
    char list2[6][30] = {"Ryan, Elizabeth", "McIntyre, Osborne", "DuMond, Kristin", "Larson, Lois", "Thorpe, Trinity", "Ruiz, Pedro"};          //Second list for use within main, nonpointer
    int ages[] = {62, 84, 18, 42, 15, 35};      //Ages list
    int arraySize = sizeof(ages) / 4;           //Size of array
    int position = youngest(ages, arraySize);   //Element position
    
    printf("Original list\n---------------------------\n");
    for(int i = 0; i < arraySize; i++)
    {
        printf("%s %d\n", list[i], ages[i]);
    }
    
    //Prints the youngest of the list
    printf("\nYoungest: %s, %d\n", list[position], ages[position]);
    avgAge(ages, arraySize);
    
    //Alphabetizes the names within the array by comparing each string and juggling them with strcpy between temp and list2
    for(int i = 0; i <= arraySize; i++)
    {
        for(int j = 1 + i; j <= arraySize; j++)
        {
            if(strcmp(list2[i], list2[j]) > 0)
            {
                strcpy(temp, list2[i]);
                strcpy(list2[i], list2[j]);
                strcpy(list2[j], temp);
            }
        }
    }

    printf("\nAlphabetized list\n---------------------------\n");

    for(int i = 0; i <= arraySize; i++)
    {
        printf("%s\n", list2[i]);
    }

    return 0;
}

//Averages the ages of people within the ages array, add them all up, divide by the size of the array
void avgAge(int *ages, int arraySize)
{
    double avg = 0;

    for(int i = 0; i < arraySize; i++)
    {
        avg += ages[i];
    }

    avg /= arraySize;
    printf("Age Average: %.2lf\n", avg);
}


//Gets the position of the smallest number in the array and returns that position to main to be printed in list
int youngest(int *ages, int arraySize)
{
    int ageToBeat = 122;    //Human record age, used as a basis for comparison 
    int position;           //Element position

    for(int i = 0; i < arraySize; i++)
    {
        if(ages[i] < ageToBeat)
        {
            ageToBeat = ages[i];
            position = i;
        }
    }
    return position;
}