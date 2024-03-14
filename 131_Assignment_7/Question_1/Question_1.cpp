// Question_1.cpp : This file contains the 'main' function.Program execution begins and ends there.
//
//
// /
//------------------------------------------------------------------------ -----------------------------------------------
//Name Sai Chaitanya Kilambi
//Course CPSC 131 Data Structures, Fall, 2022
//Assignment No.7 question:1
//Due date 10/18/2022
// Purpose:
// This prints the elements in a linked list and also outputs the name of max
//----------------------------------------------------------------------------------------------------------------------- -
// list of libraries
//
//importing the required libraries

#include <iostream>

using namespace std;

//defining the node
struct node
{
    int age;
    node* next;
};

int main()

{    
    int Age[5] = { 19, 21, 17, 22, 33 };
    
    //creating the linked list
    node* linked_list = nullptr;
    
    //going over the linked list
    for (int i = 0; i < 5; i++)
    {
        node* temp = linked_list;
       
        // insert age
        linked_list = new node;
        linked_list->age = Age[i];

        // adjust pointers
        linked_list->next = temp;

    }

    //displaying the linked list
    cout << "All node: ";
    node* temp = linked_list;

    while (temp != nullptr)
    {
        cout << temp->age << "->";
        temp = temp->next;
    }

    cout << "null\n";

    //calculating the average of the elements in the linked list
    float avg = 0;
    int n = 0;
    temp = linked_list;

    while (temp != nullptr)
    {
        avg += temp->age;
        temp = temp->next;
        n++;
    }
    avg /= n;
    cout << "Age average: " << avg << endl;

//finding the elements that are above the average
    
    int above = 0;
    temp = linked_list;

    while (temp != nullptr)
    {
        if (temp->age >= avg) {
            above++;
        }
        temp = temp->next;

    }
    //output
    cout << "Only " << above << " person(s) is above average" << endl;

    return 0;
}
