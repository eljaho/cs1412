// --------------------------------------------------------------------------------
// AUTHOR:               Elias Howell
// FILENAME:             bst.c
// SPECIFICATION:        Program utilizes binary search and recursion to search an array for a specified number
// FOR:                  CS 1412 Programming Principles II Section 002
#include <stdio.h>

void sort(int array[], int arraySize);
void getData(int *elements, int array[], int *number);
int findNumber(int *elements, int array[], int *number, int *halfway);

int main()
{
    int *array, elements, number;   //Array, number of elements, and number to find in array
    getData(&elements, array, &number);
    sort(array, elements);
    int halfway = (elements - 1) / 2;   //Halfway index of an array
    int index = findNumber(&elements, array, &number, &halfway);    //Index the provided number was found at

    printf("Found number %d in index %d.\n", number, index);

    return 0;
}

//Sorts an arrays integers in ascending order (least to greatest), compares one integer at a time
void sort(int array[], int arraySize)
{   
    int ph; //Placeholder
    for(int i = 0; i < arraySize; i++)
    {
        for(int j = 1 + i; j < arraySize; j++)
        {
            if(array[i] > array[j])
            {
                ph = array[i];
                array[i] = array[j];
                array[j] = ph;
            }
        }
    }
}

//Gets required user data: the number of elements in the array, the integers in the array, and the number to find
void getData(int *elements, int array[], int *number)
{
    printf("Input the number of elements to store in the array: ");
    scanf("%d", &*elements);
    printf("Input %d elements to the array:\n", *elements);
    //Iterates through the number of elements provided so the user can assign each element an integer value
    for(int i = 0; i < *elements; i++)
    {
        printf("element - %d:", i);
        scanf(" %d", &array[i]);
    }
    printf("Input the number to search : ");
    scanf("%d", &*number);
}

//Recursive binary search. Gets halfway index and compares content of halfway to the number being searched
//Utilizes the fact that the array was presorted in ascending order
int findNumber(int *elements, int array[], int *number, int *halfway)
{
    if(array[*halfway] == *number)
    {
        return *halfway;
    }
    else if(array[*halfway] > *number)  //If halfway index value is larger than search number: subtract one from halfway index, call itself
    {
        *halfway -= 1;
        return findNumber(elements, array, number, halfway);
    }
    else    //If halfway index value is smaller than search number: add one to halfway index, call itself
    {
        *halfway += 1;
        return findNumber(elements, array, number, halfway);
    }
}