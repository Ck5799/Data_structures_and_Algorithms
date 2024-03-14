// Question_5.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
//
// / -----------------------------------------------------------------------------------------------------------------------
//Name                          Sai Chaitanya Kilambi
//Course                        CPSC 131 Data Structures, Fall, 2022
//Assignment                    No.5 question:1
//Due date                      09/28/2022
// Purpose:
// This program prints out 10 random numbers, alphabets and months
//------------------------------------------------------------------------------------------------------------------------
// list of libraries
//
//importing the required libraries

#include <iostream>
#include "STACKPAC.h"


//main function
int main()
{
    srand(time(0));

    //Declaring the stack NUM to store random Numbers
    Stack<int,100> NUM;
    NUM.clearStack();   //clearing the stack

    //Storing random Numbers to the stack NUM
    for (int i = 0; i < 10; i++) {
        int x = rand() % 30;
        NUM.pushStack(x);
    }

    //Printing the stack NUM
    std::cout << "Numbers: ";
    while (!NUM.emptyStack())
    {
        int n = NUM.popStack();
        std::cout << n << " ";
        
    }

    std::cout << std::endl;

    //Declaring the stack ALPHA to store the random characters
    Stack <char,100> ALPHA;
    ALPHA.clearStack(); //clearing the stack

    //Storing random characters to the stack ALPHA
    for (int i = 0; i < 10; i++) {
        ALPHA.pushStack(rand() % 26 + 65);
    }

    //Printing the stack ALPHA
    std::cout << std::endl;
    std::cout << "Uppercase letters: ";
    while (!ALPHA.emptyStack())
    {
        char c= ALPHA.popStack();
        std::cout << c << " ";
        
    }

    std::cout << std::endl;

    //Defining an array to store the Months
    std::string m[] = { "JAN", "FEB", "MAR", "APR", "MAY", "JUN", "JUL", "AUG", "SEP", "OCT", "NOV", "DEC" };

    //Declaring the stack MONTHS
    Stack <std::string,100> MONTHS;
    MONTHS.clearStack(); //clearing the stack

    //Storing the months randomly
    for (int i = 0; i < 10; i++) {
        MONTHS.pushStack(m[rand() % 12]);
    }

    //Printing the stack MONTHS
    std::cout << std::endl;
    std::cout << "Months: ";
    while (!MONTHS.emptyStack())
    {
        std::string s = MONTHS.popStack();
        std::cout << s << " ";
        
    }

    std::cout << std::endl;

    return 0;
}
