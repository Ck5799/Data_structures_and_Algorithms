// / -----------------------------------------------------------------------------------------------------------------------
//Name                          Sai Chaitanya Kilambi
//Course                        CPSC 131 Data Structures, Fall, 2022
//Assignment                    No.4 question:2
//Due date                      09/21/2022
// Purpose:
// This program reverses the name that is present in the text file 
//------------------------------------------------------------------------------------------------------------------------
// list of libraries
//
//importing the required libraries
#include <iostream> 
#include <fstream> 
#include<iomanip>
#include <string> 
   
// A structure to represent a stack  
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
std::string reverse(std::string str)  
{  	 	int n = str.size();  	
Stack<char,6>stack ;   
//first of all push all characters to stack 	
for (int i = 0; i < n; i++)  		
	stack.pushStack(str[i]);   	

// Pop all characters of string and  	
// put them back to str  	
for (int i = 0; i < n; i++)  		
	str[i] = stack.popStack();       
return str; 
}   
int main()
{   
	std::string fName = "file.txt";
	std::fstream file;    
	file.open(fName,std::ios::in); 
	//open a file to perform read operation using file object    
	if (file.is_open())
	{       std::string name;       
	while(getline(file, name))
	{ //read data from file object and put it into string.          
		std::cout<<std::left<<std::setw(15) << std::setfill('-')<<name <<std::right<<std::setw(15) << reverse(name) << std::endl;
	}       
	file.close(); //close the file object.    
	}
	return 0;
}

