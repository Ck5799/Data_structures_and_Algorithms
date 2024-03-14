// / -----------------------------------------------------------------------------------------------------------------------
//Name                          Sai Chaitanya Kilambi
//Course                        CPSC 131 Data Structures, Fall, 2022
//Assignment                    No.4 question:1
//Due date                      09/21/2022
// Purpose:
// This program displays the vowels, uppercase letters and lowercase letters in the input sentence
//------------------------------------------------------------------------------------------------------------------------
// list of libraries
//
//importing the required libraries

#include <iostream>
#include<iomanip>
#include <string> 

template <class T, int n>
class Stack
{
private:
	T Element[n];
	int counter = 0;

public:
	void clearStack()
	{
		counter = 0;
	}
	bool emptyStack()
	{
		return (counter == 0 ? true :
			false);
	}
	bool fullStack()
	{
		return (counter == n ? true :
			false);
	}
	void pushStack(T x)
	{
		Element[counter] = x;
		counter++;
	}
	T popStack()
	{
		counter--;
		return Element[counter];
	}

};

int main() 
{ 
//generating random numbers 
srand(time(NULL));

//declaring input prompt
std::string sentence; 
std::cout << "Enter a sentence: "; 
std::getline(std::cin, sentence);

//creating stacks
Stack<char,80> sUpper; 
Stack<char,80> sLower; 
Stack<char,80> sVowels;
char ch; 

//using for loop to go over the sentance charecter by charecter and sort based on the case
for (int i = 0; i < sentence.size(); ++i) {
	ch = sentence[i];
	//lower case
	if (islower(ch)) {
		sLower.pushStack(ch);
		if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') { //pushing if vowel
			sVowels.pushStack(ch);
		}
	}
	else {
		//upper case
		if (isupper(ch)) {
			sUpper.pushStack(ch);
			if (ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U') { //pushing if vowel
				sVowels.pushStack(ch);
			}
		}
	}
}
//output prompts
std::cout << " Uppercase letters:"; 

//printing the upper case letters
while(!sUpper.emptyStack()){ 
	std::cout << " " <<sUpper.popStack();
} 
std::cout << std::endl; 


//output prompts
std::cout << " Lowercase letters:";

//printing the lower case letters
while(!sLower.emptyStack()) {
	std::cout << " " << sLower.popStack();
} 
std::cout << std::endl; 

//output prompts
std::cout << " Vowels:"; 

//printing the Vowels
while(!sVowels.emptyStack()) { 
	std::cout << " " << sVowels.popStack(); 
} 
std::cout << std::endl; 
return 0;
}