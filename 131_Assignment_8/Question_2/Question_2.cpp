// Question_2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//// / -----------------------------------------------------------------------------------------------------------------------
//Name                          Sai Chaitanya Kilambi
//Course                        CPSC 131 Data Structures, Fall, 2022
//Assignment                    No.8 question:2
//Due date                      10/26/2022
// Purpose:
// This program stores the data in ordered linked list from a text file and displays the data in order 
//------------------------------------------------------------------------------------------------------------------------
// list of libraries
//
//importing the required libraries


#include <iostream>
#include<string>
#include<fstream>

using namespace std;
template <class T>
class ORDER
{
private:
	struct node
	{
		T info;
		node* next;
	};
	node* order;
public:
	ORDER() { order = NULL; }// constructore
	bool emptyOrder()
	{
		return (order == NULL) ? true : false;
	}
	void pushOrder(T x)//
	{
		//insert x in the list and keep the list sorted
		node* r = new node; r->info = x;
		r->next = NULL;
		//find the insertion place;
		node* p = order; node* q = order;
		if (order == NULL)
			order = r;
		else
		{
			while (p != NULL && x > p->info)
			{
				q = p; p = p->next;
			}
			if (p == q)
			{ //insert in front
				r->next = p; order = r;
			}
			else
			{ //insert at the rear
				r->next = p; q->next = r;
			}
		}
	}
	void displayOrder()
	{
		node* p = order;
		while (p != NULL)
		{
			cout << p->info << "-->"; p = p->next;
		}
		cout << "NULL\n";
	}
	T popOrdere()
	{
		//return the info of the first node and then
		//delete that node
		T popedElement;
		node* p = order;
		popedElement = p->info;
		order = p->next;
		delete p;
		return popedElement;
	}
};
int main()
{
	string presidents[6];
	std::fstream f;
	//opening the file to only read
	f.open("data.txt", std::ios::in);

	// copying the file data into an array 
	for (int i = 0; i < 6; i++) {
		f >> presidents[i];
	}
		//display a in sorted form
		ORDER<string> ord;
		for (int i = 0; i < 6; ++i)
			ord.pushOrder(presidents[i]);
		//display the list
		cout << "This is the ordered list\n";
		ord.displayOrder();
}