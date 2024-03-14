// -----------------------------------------------------------------------------------------------------------------------
//Name                          Sai Chaitanya Kilambi
//Course                        CPSC 131 Data Structures, Fall, 2022
//Assignment                    No.5 question:4
//Due date                      09/28/2022
// Purpose:
// This program call a recursive function that computes the given term of the Fibonacci numbers
//------------------------------------------------------------------------------------------------------------------------
// list of libraries
//
//importing the required libraries
#include <iostream>

//creating the recursive function
int g(int n, int m)
{
	if (n == m) return 3;
	else return n + g(n + 1, m);
}
//main function
int main() {

	std::cout<<g(5,9);

	
	return 0;

}