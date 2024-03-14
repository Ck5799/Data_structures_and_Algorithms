// Question_3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
// / -----------------------------------------------------------------------------------------------------------------------
//Name                          Sai Chaitanya Kilambi
//Course                        CPSC 131 Data Structures, Fall, 2022
//Assignment                    No.5 question:3
//Due date                      09/28/2022
// Purpose:
// This program call a recursive function that computes the sum of squares
//------------------------------------------------------------------------------------------------------------------------
// list of libraries
//
//importing the required libraries
#include <iostream>

//creating the recursive function
int sumOfsq(int n) {
	if (n == 3) {
		return 9; //fact
	}
	else {
		return sumOfsq(n - 1) + std::pow(n, 2);  //recursion
	}
}

//main function
int main()
{
	int n=8;  //testing foe the value 8
	std::cout <<"When n=8 the answer is: "<< sumOfsq(n); //calling and printing the output from the recursive function
	return 0;
}

