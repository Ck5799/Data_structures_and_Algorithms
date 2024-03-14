// / -----------------------------------------------------------------------------------------------------------------------
//Name                          Sai Chaitanya Kilambi
//Course                        CPSC 131 Data Structures, Fall, 2022
//Assignment                    No.4 question:4
//Due date                      09/21/2022
// Purpose:
// This program prints out the the table of students with GPA > 3.0 and GPA <=3.0 
//------------------------------------------------------------------------------------------------------------------------
// list of libraries
//
//importing the required libraries

#include<iostream> 
#include<fstream> 
#include<string> 
#include<iomanip>

template <class T, int n>
class Stack
{
private:
	T Element[n];
	int counter=0;

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



int main(){ 
	//	name of the file 	
	std::string filename = "data.txt"; 	 
	//	variables 
	std::string word; 	
	float gpa; 	 
	//	stacks 	
	Stack<std::string,80> lowStack; 	
	Stack<std::string,80> highStack; 	 
	//	open file to read word by word 	
	std::fstream file; 	
	file.open(filename.c_str()); 	 
	//	read file till EOF 	
	while(file>>word){ 
		//		read gpa of student 'word' 		
		file>>gpa; 		 
		//		push student into stack accordingly 		
		if(gpa<=3.0){ 			
			lowStack.pushStack(word); 		
		} 		
		else{ 			
			highStack.pushStack(word); 		
		}
	} 	 
	//	print output 	
	std::cout<<"  GPA <= 3.0    GPA > 3.0"<<std::endl; 	
	std::cout<<"_________________________"<<std::endl; 	
	while(!lowStack.emptyStack() && !highStack.emptyStack())
	{ 		
		std::cout<<std::setw(15)<<std::left<< lowStack.popStack(); 		
		std::cout<<std::setw(10)<<std::right<< highStack.popStack()<<std::endl;
		 	
	} 	 
	//	if lowStack is still not empty 
	while(!lowStack.emptyStack())
	{ 		
		std::cout<<std::setw(15)<<std::left<< lowStack.popStack() <<std::endl;
		 	
	} 	 
	//	if highStack is still not empty 	
	while(!highStack.emptyStack())
	{ 		
		std::cout<<std::setw(25)<<std::right<< highStack.popStack() <<std::endl;
		
	} 	
	//	close the file (IMPORTANT)
	file.close(); 
	return 0; 
}

