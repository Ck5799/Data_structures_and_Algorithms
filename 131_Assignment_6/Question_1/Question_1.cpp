// Question_1.cpp : This file contains the 'main' function.Program execution begins and ends there.
//
//
// /
//------------------------------------------------------------------------ -----------------------------------------------
//Name Sai Chaitanya Kilambi
//Course CPSC 131 Data Structures, Fall, 2022
//Assignment No.6 question:1
//Due date 10/12/2022
// Purpose:
// This finds the runtime of a recursive function and also calculates the value when n=15
//----------------------------------------------------------------------------------------------------------------------- -
// list of libraries
//
//importing the required libraries

#include <iostream>
#include <ctime>

using namespace std;


//given recursive function
long  f(int n)
{
    if(n == 1)  return 2;  //base case

       else          return 2 * f(n - 1);   //recursive case
}

int main()
{
    time_t start, end;
    //save time before calling function
    start = clock();
    //call the function
    std::cout <<"The Value of f(15) is " << f(15) << std::endl;
    //save time after executing function
    end = clock();
    std::cout << "Run-time = "<< (end - start) / 1000 << std::endl;   // calculating the runtime
    system("pause");
    return 0;
}
