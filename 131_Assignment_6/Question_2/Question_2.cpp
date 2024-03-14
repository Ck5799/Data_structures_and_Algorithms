// Question_2.cpp : This file contains the 'main' function.Program execution begins and ends there.
//
//
// /
//------------------------------------------------------------------------ -----------------------------------------------
//Name Sai Chaitanya Kilambi
//Course CPSC 131 Data Structures, Fall, 2022
//Assignment No.6 question:2
//Due date 10/12/2022
// Purpose:
// This finds the runtime of a recursive Fibonacci function and a non Fibonacci function at the value when n=43
//----------------------------------------------------------------------------------------------------------------------- -
// list of libraries
//
//importing the required libraries

#include <iostream>
#include <ctime>

using namespace std;

// recursive Fibonacci function
long Fib(int n)
{
    if (n == 0) return 0;
    if(n == 1||n==2) return 1;
    else return Fib(n - 1) + Fib(n - 2);
}

// non-recursive Fibonacci function

long FibNRec(int n)
{
    long f0 = 0, f1 = 1, fn=0;
    for (int i = 2; i <= n; ++i)
    {
        fn = f0 + f1;
        f0 = f1;
        f1 = fn;
    }
    return fn;
}

int main()
{
    time_t start, end;
    //save time before calling function
    start = clock();
    //call the function
    
    Fib(43);
    //save time after executing function
    end = clock();
    std::cout << "The Run-time for recursive Fib function is = " << (end - start) / 1000 << std::endl;   // calculating the runtime


    start= clock();
    //call the function
    FibNRec(43);
    //save time after executing function
    end = clock();
    std::cout << "The Run-time for non recursive Fib function is = " << (end - start) / 1000 << std::endl;



    system("pause");
    return 0;
}
