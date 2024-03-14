// Question_2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
// / -----------------------------------------------------------------------------------------------------------------------
//Name                          Sai Chaitanya Kilambi
//Course                        CPSC 131 Data Structures, Fall, 2022
//Assignment                    No.5 question:2
//Due date                      09/28/2022
// Purpose:
// This program checks if the given sentence is a palindrome or not
//------------------------------------------------------------------------------------------------------------------------
// list of libraries
//
//importing the required libraries
#include <iostream>
#include <string>
#include "STACKPAC.h"  // using the STACKPAC header file


//function that checs if palindrome or not 
void checkPalindrome(std::string s)
{
	Stack <char, 100> a;           //creating a stack
	a.clearStack();               //clearing the stack
	std::string sen = "";
	
	//to go over the input string and take only the alphabets into the stack
	for (int j = 0; j < s.length(); j++)
	{
		char c = s[j];
		if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) {
			sen += tolower(c);  //converting the alphabets to the lower case
		}

	}

	//pusing the string into the stack
	for (int j = 0; j < sen.length(); j++) {
		a.pushStack(sen[j]);
	}

	//comparing the stack and the string to see if it is a palindrome or not 
	for (int j = 0; j < sen.length(); j++) {
		char c = a.popStack();
		if (c != sen[j]) {
			std::cout << "This phrase is not a palindrome\n";
			return;
		}
	}
	std::cout << "This phrase is a palindrome\n";
}


//main function
int main()
{
	std::string s;

	//input prompt for the number of phrases
	std::cout << "How many phrases would you like to try? ";
	std::getline(std::cin,s);

	
	int n = stoi(s);
	while(n--)
	{
		std::cout << std::endl;
		std::cout << "Enter a phrase: ";

		//taking the input of the string 
		std::getline(std::cin, s);

		//calling the function
		checkPalindrome(s);
	}
	
	return 0;


}

