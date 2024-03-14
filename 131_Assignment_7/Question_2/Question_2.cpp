// Question_2.cpp : This file contains the 'main' function.Program execution begins and ends there.
//
//
// /
//------------------------------------------------------------------------ -----------------------------------------------
//Name Sai Chaitanya Kilambi
//Course CPSC 131 Data Structures, Fall, 2022
//Assignment No.7 question:2
//Due date 10/18/2022
// Purpose:
// This prints the elements in a linked list and also outputs the name of max
//----------------------------------------------------------------------------------------------------------------------- -
// list of libraries
//
//importing the required libraries
#include<iostream>
#include<string>
#include<fstream>
using namespace std;

//define the node
struct node {
    string name;
    int age;
    node* next;
};

//function to output the max element 
void largestElement(struct node* head)
{
    //assigning the first element of the linked list to max variable
    int max = head->age;
    string name;

    //loop to check the max value of each element in the linked list
    while (head != NULL) {

        if (max < head->age) {
            max = head->age;
            name = head->name;

        }
        head = head->next;
    }
cout<<"The oldest person is "<<name;
}

//function to display the linked list
void display(node* head) {

    node* p = head;
    cout << "Name   " << "Age" << endl;
    cout << "--------------\n";
    while (p != nullptr) {
        cout << p->name << "\t" << p->age << endl;
        p = p->next;
    }
}


int main() {

    // defining the node
    node* head = nullptr;

    //opening the file 
    char filename[] = "pro5.txt";
    ifstream infile(filename);
    string name;
    int age;

    //copying the data from the file to the linked list
    while (infile >> name >> age) {
        node* n = new node;
        n->name = name;
        n->age = age;
        n->next = nullptr;
        if (head == nullptr) {
            head = n;

        }
        else {
            n->next = head;
            head = n;
        }

    }

    //closing the file 
    infile.close();

    //calling the display function
    display(head);

    //calling the function to output the max element 
    largestElement(head);

    return 0;
}
