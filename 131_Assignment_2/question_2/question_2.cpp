// question_2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//// / -----------------------------------------------------------------------------------------------------------------------
//Name                          Sai Chaitanya Kilambi
//Course                        CPSC 131 Data Structures, Fall, 2022
//Assignment                    No.2 question:2
//Due date                      09/07/2022
// Purpose:
// This program uses the arrays and vectors concept to store and display names ,age and also calculates the average age 
//------------------------------------------------------------------------------------------------------------------------
// list of libraries
//
//importing the required libraries

#include <iostream>
#include <iomanip>
#include<string>
#include <vector>

//creating a template class
template <class T>

//function to display the elements in an array
void displayAll(T A[], int n)
{
    for (int i = 0; i < n; i++) {
        std::cout << A[i]<<" ";
    }
}
//creating a template class
template<class V>

//function to display the elements in a vector 
void DisplayAll(std::vector <V> B)
{
    for (int i = 0; i < B.size(); i++)
    {
        std::cout << B[i] << " ";
    }
}

//function to compute the average age
double computeAgeAve(int A[], int n) {
    double avg = 0.0;
    for (int i = 0; i < n; i++) {
        avg += A[i];
    }
    avg = avg / n;
    return avg;
}

//main function
int main()
{
    int age[5] = { 33, 67, 55, 72, 44 };
    std::string names[3] = { "Trump","Clinton","Obama" };

    //calling the display function for age array
    std::cout << "Array age: ";
    displayAll(age, 5);
    std::cout << std::endl;

    //calling the display function for names array
    std::cout << "Array names: ";
    displayAll(names, 3);
    std::cout << std::endl;

    //copying the elements from the age array to the vage vector
    std::vector<int> vage;
    for (int i = 0; i < 5; i++) {
        vage.push_back(age[i]);
    }

    //copying the elements from the age array to the vnames vector
    std::vector<std::string> vnames;
    for (int i = 0; i < 3; i++) {
        vnames.push_back(names[i]);
    }

    std::cout << std::endl;

    //calling the display function for age array
    std::cout << "Vector vage: ";
    DisplayAll(vage);
    std::cout << std::endl;

    //calling the display function for vnames vector
    std::cout << "Vector vnames: ";
    DisplayAll(vnames);
    std::cout << std::endl;

    std::cout << std::endl;

   //calling the compute avg age function 
    std::cout << "Age average= " <<std::fixed <<std::setprecision(2) << computeAgeAve(age, 5);

    return 0;

}