// / -----------------------------------------------------------------------------------------------------------------------
//Name                          Sai Chaitanya Kilambi
//Course                        CPSC 131 Data Structures, Fall, 2022
//Assignment                    No.3 question:3
//Due date                      09/14/2022
// Purpose:
// This program checks if the two given inputs are anagrams or not  
//------------------------------------------------------------------------------------------------------------------------
// list of libraries
//
//importing the required libraries
#include <iostream>
#include<string>
#include<algorithm>

//fuction to remove the spaces if any in the input
void remove_space(std::string& s) {

	for (int i = 0; i < s.length()  ; i++) {
		if (s[i] == ' ') {
			s.erase(i, 1);
		}

	}
}

//coverting all the letters in the input to lower casse
void convert_to_lower(std::string& s1) {
	for (int i = 0; i < s1.length(); i++) {
		s1[i] = tolower(s1[i]);
	}
}

//sorting the letters in the string based on the ascii value
std::string string_sorting(std::string& s2) {

	std::sort(s2.begin(), s2.end());
	return s2;

	
}

//fuction that checks if it is a anagram or not
bool isAnagram(std::string st1, std::string st2) 
{
	
	int i=0;
	remove_space(st1);
	remove_space(st2);
	convert_to_lower(st1);
	convert_to_lower(st2);
	string_sorting(st1);
	string_sorting(st2);

	while (st1[i] != '\0') 
	{  
		if(st1[i]!=st2[i])           
		{                 
			return 0;             
		}             
		i++;         
	}          

		return 1;
}

//main function
int main()
{
	std::string str1,str2;
	char flag = 'y';

	//creating a while loop that continues till the user tells to stop
	while (flag == 'y')
	{

		// first input prompt 	
		std::cout << "Enter a string: ";

		std::getline(std::cin, str1);

		
		//second input prompt
		std::cout<< "Enter another string: ";

		std::getline(std::cin, str2);

		//calling the isAnagram function
		if (isAnagram(str1, str2)) {

			//printing the output
			std::cout<< "\" " << str1 <<"\" "<<" and "<< "\" "<<str2<< "\" "<<" are Anagrams\n";
		}
		else {
			std::cout << "\" " << str1 << "\" " << " and " << "\" " << str2 << "\" " << " are not Anagrams\n";
		}
		
		std::cout << std::endl << "CONTINUE(y/n)? ";
		std::cin >> flag;
		std::cin.ignore();
		if (flag == 'n')
			break;

	}
	return 0;
}
