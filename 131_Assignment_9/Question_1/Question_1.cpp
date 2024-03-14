// Question_1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//////// / -----------------------------------------------------------------------------------------------------------------------
//Name                          Sai Chaitanya Kilambi
//Course                        CPSC 131 Data Structures, Fall, 2022
//Assignment                    No.9 question:1
//Due date                      11/2/2022
// Purpose:
// This program demonstrates hashing 
//------------------------------------------------------------------------------------------------------------------------
// list of libraries
//
//importing the required libraries

#include<iostream>
using namespace std;

//creating a node structure
struct node {
    string monthName;
    int monthDays;
    node* next;
};
//the hash fucntion
int hashFun(string month)
{
    int x = (int)month[0];
    int y = (int)month[1];
    int z = (int)month[2];
    int idx = (x + y + z) % 5;

    return idx;
}
//the function to push the month and the days
void push(node** head, int days, string name)
{
    node* new_node = new node();
    new_node->monthDays = days;
    new_node->monthName = name;
    new_node->next = (*head);
    (*head) = new_node;
}

//main function
int main()
{
    //defining the months 
    string months[12] = { "JAN","FEB","MAR","APR","MAY","JUN","JUY","AUG","SEP","OCT","NOV","DEC" };
    int days[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
    node* hash[5];
    hash[0] = NULL, hash[1] = NULL, hash[2] = NULL, hash[3] = NULL, hash[4] = NULL;

    //creating the hashtable
    for (int i = 0; i < 12; i++)
    {
        int index = hashFun(months[i]);
        push(&hash[index], days[i], months[i]);
    }

    //printting the hash table
    cout << "This is the hash table:\n";
    for (int i = 0; i < 5; i++)
    {
        cout << "H[" << i << "]" << "-> ";
        node* temp = hash[i];
        while (temp != NULL)
        {
            cout<< temp->monthName << "," << temp->monthDays << "->";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }

    //finding the month in the hash table
    string month;
    cout << "Enter a month name: ";
    cin >> month;

    int index_to_find = hashFun(month);
    node* temp = hash[index_to_find];
    int day, count = 0;
    bool found = false;
    while (temp != NULL)
    {
        count++;
        if (temp->monthName == month)
        {
            found = true;
            day = temp->monthDays;
            break;
        }
        temp = temp->next;
    }

    if (found)
    {
        cout << "Number of days in " << month << " is " << day << " after " << count <<" comparisons"<< endl;
    }
    else
    {
        cout << "No Month Found\n";
    }

    return 0;
}