// Question_2.cpp : This file contains the 'main' function. Program execution begins and ends there.
////// / -----------------------------------------------------------------------------------------------------------------------
//Name                          Sai Chaitanya Kilambi
//Course                        CPSC 131 Data Structures, Fall, 2022
//Assignment                    No.9 question:2
//Due date                      11/2/2022
// Purpose:
// This program implements Radix sort on an array 
//------------------------------------------------------------------------------------------------------------------------
// list of libraries
//
//importing the required libraries
#include<iostream>

using namespace std;


//Max Function 
int getMax(int list[9]) {
    int mx = list[0];
    int i;
    for (i = 1; i < 9; i++)
        if (list[i] > mx)
            mx = list[i];
    return mx;
}

//radix sort function
void radixsort(int list[9]) {

    //calling max function
    int m = getMax(list);

    int exp;

    //sort every digit and cout but pass the exp variable of that number (hassong function)
    for (exp = 1; m / exp > 0; exp *= 10) {
        int output[9];
        int i, count[10] = { 0 };

        // Store count of occurrences in count[]
        for (i = 0; i < 9; i++)
            count[(list[i] / exp) % 10]++;

        // Change count[i] so that count[i] now contains actual position of this digit in output[]
        for (i = 1; i < 10; i++)
            count[i] += count[i - 1];

        // Build the output array
        for (i = 9 - 1; i >= 0; i--) {
            output[count[(list[i] / exp) % 10] - 1] = list[i];
            count[(list[i] / exp) % 10]--;
        }

        //copy output into original arry
        for (i = 0; i < 9; i++)
            list[i] = output[i];
    }
}

//printing the array
void print(int list[9]) {
    int i;
    for (i = 0; i < 9; i++)
        cout<<"\t"<<list[i];
}

//main function
int main()
{
    int list[9] = { 199, 200, 77, 45, 15, 278, 66, 9, 100 };
    
    //printing the elements of the array before sort
    cout<<"List of numbers before sort: \n";
    for (int i = 0; i < 9; i++)
        cout << "\t" << list[i];

    //calling the sort function
    radixsort(list);
    
    //printing the elements of the array after sort
    cout<<"\n\nList of numbers after sort: \n";
    print(list);
    cout<<"\n\n";
    return 0;
}