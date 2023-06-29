//
//  kxc210022.program1.cpp
//
//  Created by Krish Chanda on 9/1/22.
//
//  Software
//  Machine: Macbook Pro
//  Operating System: Mac OS
//  IDE: Xcode
//  Compiler: clang
//

#include <iostream>
#include <time.h>
using namespace std;


//***************************************************
// The swap function swaps a and b in memory.       *
//***************************************************
void swap(int& a, int& b)
{
    int temp = a;
    a = b;
    b = temp;
}

//***************************************************
// Binary Search                                    *
//***************************************************

int binarySearch(int array[], int size, int value)
{
    int first = 0,         // First array element
        last = size - 1,       // Last array element
        middle,                // Mid point of search
        position = -1;         // Position of search value
    bool found = false;    // Flag

 

    while (!found && first <= last)
    {

        middle = (first + last) / 2;     // Calculate mid point
        if (array[middle] == value)      // If value is found at mid
        {
            found = true;
            position = middle;
        }
        else if (array[middle] > value)  // If value is in lower half
            last = middle - 1;
        else
            first = middle + 1;           // If value is in upper half
    
        
    }

 
    return position;
}

//***************************************************
// Linear Search                                    *
//***************************************************

int linearSearch(int arr[], int size, int value)
{
    int index = 0;      // Used as a subscript to search the array
    int position = -1;  // To record the position of search value
    bool found = false; // Flag to indicate if value was found

 

    while (index < size && !found)
    {
        if (arr[index] == value) // If the value is found
        {
            found = true; // Set the flag
            position = index; // Record the value's subscript
        }
 
        index++; // Go to the next element
    }
 
    return position; // Return the position, or -1
}

//*****************************************************************
// The bubbleSort function sorts an int array in ascending order. *
//*****************************************************************

void bubbleSort(int array[], int size)
{
    int maxElement;
    int index;

    for (maxElement = size - 1; maxElement > 0; maxElement--)
    {
        for (index = 0; index < maxElement; index++)
        {
            if (array[index] > array[index + 1])
            {
                swap(array[index], array[index + 1]);
            }
        }
    }
}

//********************************************************************
// The selectionSort function sorts an int array in ascending order. *
//********************************************************************
void selectionSort(int array[], int size)
{
    int minIndex, minValue;

    for (int start = 0; start < (size - 1); start++)
    {
        minIndex = start;
        minValue = array[start];
        for (int index = start + 1; index < size; index++)
        {
            if (array[index] < minValue)
            {
                minValue = array[index];
                minIndex = index;
            }
        }
        swap(array[minIndex], array[start]);
    }
}



// Iterates through the array to display the values in each index

void showArray(int array[], int size)
{
    for (int i = 0; i < size; i++){
        cout << "Array[" << i << "]  =  " << array[i] << endl; // displays each element and index of an array
    }
}

// Gets a random target Index from an array

int getTarget(int array[], int size)
{
    int index = rand() % size;
    return array[index];
}

// fills array with random int values

void fillArray(int intArray[], int sizeInt, bool boolArray[], int sizeBool)
{
    // Sets all values in the bool array to false
    for (int i = 0; i < sizeBool; i++){
        boolArray[i] = false;
    }
    
    // iterates through the int array to assign each index to a rand value from the index bool array
    int counter = 0;
    while (counter < sizeInt)
    {
        int randIndex = rand() % sizeBool; // gets random index for bool
        
        if (boolArray[randIndex] == false ) // while conditional loop
        {
            intArray[counter] = randIndex; // sets int array index to rand while loop index
            boolArray[randIndex] = true;
            counter++;
        }
        
    }
    
    // Comment/Thought: What does the Boolean array provide in a practical fashion? Take a moment to think.
    // Answer: The bool array provides a means to put random numbers into the int array without any duplicate numbers
    
}

// Function tests 1000000 linear searches to calculate the time it took to go through all the searches and find a targeted value
void testLinearSearch(int array[], int size)
{
    
    double start = clock(); // start time
    
    for (int i = 0; i < 1000000; i++)
    {
        int randTarget = getTarget(array, size); // getTarget call
        
        linearSearch(array, size, randTarget); // linear search call
        
    }
    
    double stop = clock(); // end time
    
    // calculate time in (ms) of how long it took to go through 1000000 linear searches
    double clocksPerSec = CLOCKS_PER_SEC;
    double time = ((stop - start) / clocksPerSec ) * 1000;
    
    
    cout << "Test Linear Search" << endl;
    cout << "Elapsed  =  " << time << "  ms" << endl; // print time out
    
    // Comment/Thought: Why does the linear search need to be called a million times? Why should CLOCKS_PER_SEC be cast to a double?
    // Answer: If we only take a small sample, the result time would not have high accuracy, so we use a large sample to get a more accurate time.
    // CLOCKS_PER_SEC has to be cast to a double to ensure accuracy of the result because the rounding of int value will not give a percise answer.

    
}



void testBinarySearch(int array[], int size)
{
    double start = clock(); // start time
    
    for (int i = 0; i < 1000000; i++)
    {
        int randTarget = getTarget(array, size); // getTarget call
        
        binarySearch(array, size, randTarget); // linear search call
        
    }
    
    double stop = clock(); // end time
    
    // calculate time in (ms) of how long it took to go through 1000000 linear searches
    double clocksPerSec = CLOCKS_PER_SEC;
    double time = ((stop - start) / clocksPerSec ) * 1000;
    
    
    cout << "Test Binary Search" << endl;
    cout << "Elapsed  =  " << time << "  ms" << endl; // print time out
    
    // Comment/Thought: Why does the binary search need to be called a million times? Why should CLOCKS_PER_SEC be cast to a double?
    // Answer: If we only take a small sample, the result time would not have high accuracy, so we use a large sample to get a more accurate time.
    // CLOCKS_PER_SEC has to be cast to a double to ensure accuracy of the result because the rounding of int value will not give a percise answer.

}



//********************************************************************
// MAIN                                                              *
//********************************************************************

int main(int argc, const char * argv[]) {
    
    // array declarations
    int array1[10];
    bool array2[100];
    
    int array3[1000];
    bool array4[10000];
    
    // variable declarations
    int target;
    int index;
    
    srand(clock());
    
    
    cout << "Krish Chanda \nCS 1337-503\nProgram 1" << endl;
    cout << "=======================" << endl;
    
    
    // Bubble sort
    cout << "Bubble Sort\n";
    fillArray(array1, 10, array2, 100);
    cout << "Before\n";
    showArray(array1, 10);
    cout << "-----\n";
    bubbleSort(array1, 10);
    cout << "After\n";
    showArray(array1, 10);
    cout << "-----\n###################################\n";
    cout << "   \n";
    
    // Selection Sort
    cout << "Selection Sort\n";
    fillArray(array1, 10, array2, 100);
    cout << "Before\n";
    showArray(array1, 10);
    cout << "-----\n";
    selectionSort(array1, 10);
    cout << "After\n";
    showArray(array1, 10);
    cout << "-----\n###################################\n";
    cout << "   \n";
    
    
    // linear search
    cout << "Linear Search\n";
    fillArray(array1, 10, array2, 100);
    target = getTarget(array1, 10);
    showArray(array1, 10);
    index = linearSearch(array1, 10, target);
    cout << "Target:" << target << "  Index:" << index << endl;
    cout << "  " << endl;
    cout << "###################################\n";
    cout << "  " << endl;
    
    
    // binary search
    cout << "Binary Search\n";
    fillArray(array1, 10, array2, 100);
    selectionSort(array1, 10);
    target = getTarget(array1, 10);
    showArray(array1, 10);
    index = binarySearch(array1, 10, target);
    cout << "Target:" << target << "  Index:" << index << endl;
    cout << "  " << endl;
    cout << "###################################\n";
    cout << "  " << endl;
    
    // Benchmark Test
    cout << "Benchmarks\n";
    fillArray(array3, 1000, array4, 10000);
    selectionSort(array3, 1000);
    testLinearSearch(array3, 1000);
    testBinarySearch(array3, 1000);
    
    // Comment/Thought: Which took longer to run, the linearSearch or the binarySearch?
    // The linear Search took longer than the binary search.
    
    
        
    
    
    return 0;
}
