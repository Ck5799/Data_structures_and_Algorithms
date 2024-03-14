// / -----------------------------------------------------------------------------------------------------------------------
//Name                          Sai Chaitanya Kilambi
//Course                        CPSC 131 Data Structures, Fall, 2022
//Assignment                    No.3 question:2
//Due date                      09/14/2022
// Purpose:
// This program gives the short form notation for the inputed university name  
//------------------------------------------------------------------------------------------------------------------------
// list of libraries
//
//importing the required libraries
#include <iostream>
#include<string>
#include<cstring>


//creating a function that returns the short form of the university name 
std::string ShortForm(std::string uni)
{
	std::string small = "";
	small.push_back(uni[0]);

	//for loop for going over the input 
	for (int j = 2; j < uni.length(); j++)
	{
		if (uni[j - 1] == ' ' && uni[j] != 0)
		{
			//skipping the word "of"
			if ((uni[j] == 'o' || uni[j] == 'O') && (uni[j + 1] == 'f' || uni[j + 1] == 'F'))
				continue; 

			else
				small.push_back(uni[j]);
		}
	}
	return small;
}



//main function
int main()
{
	
	std::string university;
	 char flag='y'; 	
	 //creating the while loop over the flag variable that determines if the loop should continue or not 
	 while(flag=='y')
	 { 		
		
	 // to store university name as entered by user 		
		 std::cout<<"Enter a university name: "; 
		 
		 std::getline(std::cin, university);

		 std::cout<<"\t"<<university<<" or "<<ShortForm(university); 

		 std::cout<<std::endl<<"CONTINUE(y/n)? "; 	

		 std::cin>>flag;
		 std::cin.ignore();
		 //ending the loop if the flag variable is 'n'
		 if (flag == 'n') 
			 break;

	 } 	
	 return 0; 
}


