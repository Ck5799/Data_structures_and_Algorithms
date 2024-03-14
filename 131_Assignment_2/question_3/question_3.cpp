// question_3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
// 
// 
// / -----------------------------------------------------------------------------------------------------------------------
//Name                          Sai Chaitanya Kilambi
//Course                        CPSC 131 Data Structures, Fall, 2022
//Assignment                    No.2 question:3
//Due date                      09/07/2022
// Purpose:
// This program takes an input of a string and prints the frequency of each alphabet that appears in the string 
// considering the uppercase and lower case the same
//------------------------------------------------------------------------------------------------------------------------
// list of libraries
//
//importing the required libraries

#include <iostream>
#include <string>
#include <iomanip>

int main()
{
	int i = 0;
	int j = 0;
	std::string sentence;
	int frequency[26] = {};

	//printing the input prompt
	std::cout << "Enter a sentence: ";

	//take in the input sentence
	std::getline(std::cin, sentence);

	//using while loop to read the string
	while (sentence[i] != '\0') {
		sentence[i] = tolower(sentence[i]);
		if (sentence[i] >= 'a' && sentence[i] <= 'z') {

			//j stores the value of each alphabet namely a=0,b=1....z=25;
			j = sentence[i] - 'a';

			//if the alphabets entered is a lower case then the ascii subtraction will ber greater than or equal to 32
			//if (j >= 32) {
				//j -= 32;
			//}

			//frequency of the corresponding alphabets are noted 
			frequency[j]++;
		}
		//moving to the next charecter 
		i++;
	}
	
	//printing out the header
	std::cout << ("Letters\t\t  Frequencies\n............................\n");


	//loop to check if the charecter has a frequency >0 or not and printing the frequency of charecters with frequency >= 1 
	for (int i = 0; i < 26; i++) {

		if (frequency[i] != 0) {
			std::cout<<"    " << char(i + 'a') <<"\t"<<"\t     " << frequency[i] << std::endl;

		}

	}

	return 0;

}


