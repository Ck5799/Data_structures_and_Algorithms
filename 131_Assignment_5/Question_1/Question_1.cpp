// Question_1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
//
// / -----------------------------------------------------------------------------------------------------------------------
//Name                          Sai Chaitanya Kilambi
//Course                        CPSC 131 Data Structures, Fall, 2022
//Assignment                    No.5 question:1
//Due date                      09/28/2022
// Purpose:
// This program converts decimal number into binary,octal and hexadecimal
//------------------------------------------------------------------------------------------------------------------------
// list of libraries
//
//importing the required libraries

#include <iostream>
#include <string>
#include "STACKPAC.h"  // using the STACKPAC header file

float average(int a, int b) {
    float avg = float(a) / b;
    return avg;
}

int main()
{
    int sum1 = 0, sum2 = 0,n=0,m=0;
    srand(time(0));
    //Declaring the stack NUM to store random Numbers
    Stack<int, 100> evenStack;
    Stack<int, 100> oddStack;
    evenStack.clearStack(); //clearing the stack
    oddStack.clearStack();
    //Storing random Numbers to the stack NUM
    for (int i = 0; i < 11; i++) {
        int x = rand() % 21;
        if (x % 2 == 0) {
            sum1 += x;
            evenStack.pushStack(x);
            n++;
        }
        else {
            sum2 += x;
            oddStack.pushStack(x);
            m++;
        }
    }
    std::cout << "EVEN stack : ";

    while (!evenStack.emptyStack()) {
        std::cout  << evenStack.popStack() << " ";
    }
    std::cout << "\taverage = " << average(sum1, n)<<std::endl;
    std::cout << "ODD stack : ";
    while (!oddStack.emptyStack()) {
        std::cout  << oddStack.popStack() << " ";
    }
    std::cout << "\taverage = " << average(sum2, m) << std::endl;
    return 0;

}