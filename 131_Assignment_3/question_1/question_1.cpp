// question_1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//// / -----------------------------------------------------------------------------------------------------------------------
//Name                          Sai Chaitanya Kilambi
//Course                        CPSC 131 Data Structures, Fall, 2022
//Assignment                    No.3 question:1
//Due date                      09/14/2022
// Purpose:
//This program calculates the number of words,Uppercase Letters, Lowercase letters,vowels and number of 'CARE' substrings in a sentance.  
//------------------------------------------------------------------------------------------------------------------------
// list of libraries
//
//importing the required libraries

#include <iostream>
#include<string>
#include<iomanip>


//creating a isvowel function 
bool isvowel(std::string str,int i) {

    if (str[i] == 'a' || str[i] == 'A' || str[i] == 'e' || str[i] == 'E' || str[i] == 'i' || str[i] == 'I' || str[i] == 'o' || str[i] == 'O' || str[i] == 'u' || str[i] == 'U')
        {

            return true;
        }
        else {
            return false;

        }


}

//main function

int main()
{
    //initializing the values 
    int words = 0, uppercase = 0, lowercase = 0, vowels = 0,care=0;
    std::string sentance;

    //printing the input prompt to the user
    std::cout << "Enter a sentance: ";
    std::getline(std::cin, sentance);


    //loop to go charecter by charecter in a string
    for (int i = 0; i < sentance.length(); i++) 
    {

        //to check the number of words
        if (isspace(sentance[i])) {
            words++;
        }

        //to check the number of uppercase letters
        if (isupper(sentance[i])) {
            uppercase++;
        }

        //to check the number of lower case letters 
        if (islower(sentance[i])) {
            lowercase++;
        }

        //calling the is vowel function to check the vowels

        if (isvowel(sentance,i)) {
            vowels++;
        }

        //checking for the substring 'CARE"
        if (sentance[i]=='E' && sentance[i-1] == 'R' && sentance[i-2] == 'A' && sentance[i-3] == 'C')
        {
            care++;

        }

    }


    //printing the generated output
    std::cout << std::left << std::setw(30) << std::setfill('.') << "No.of words" << std::right << words + 1 << std::endl;
    std::cout << std::left << std::setw(30) << std::setfill('.') << "No. of uppercase letters" << std::right << uppercase << std::endl;
    std::cout << std::left << std::setw(30) << std::setfill('.') << "No. of lowercase letters" << std::right << lowercase << std::endl;
    std::cout << std::left << std::setw(30) << std::setfill('.') << "No.of vowels" << std::right << vowels << std::endl;
    std::cout << std::left << std::setw(30) << std::setfill('.') << "No. of substring CARE" << std::right << care << std::endl;

    return 0;
}






    

 




