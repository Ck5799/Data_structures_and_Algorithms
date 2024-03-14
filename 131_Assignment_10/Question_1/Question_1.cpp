//////// / -----------------------------------------------------------------------------------------------------------------------
//Name                          Sai Chaitanya Kilambi
//Course                        CPSC 131 Data Structures, Fall, 2022
//Assignment                    No.10 question:1
//Due date                      11/9/2022
// Purpose:
// Insert all data from the file into an ordered Linked list
//------------------------------------------------------------------------------------------------------------------------
// list of libraries
//
//importing the required libraries
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

struct node {
	int acctNo;
	string name;
	float balance;
	struct node* next;
};
void showBalance(struct node* head) {
	int accNo;
	cout << "Enter Account Number: ";
	cin >> accNo;
	struct node* temp = head;
	while (temp != NULL) {
		if (temp->acctNo == accNo) break;
		temp = temp->next;
	}
	if (temp == NULL)
		cout << "Invalid Account Number\n";
	else
		cout <<temp->name<< ", your balance is " << temp->balance << endl;
}
void deposit(struct node* head) {
	int accNo;
	cout << "Enter Account Number: ";
	cin >> accNo;
	struct node* temp = head;
	while (temp != NULL) {
		if (temp->acctNo == accNo) break;
		temp = temp->next;
	}
	if (temp == NULL)
		cout << "Invalid Account Number\n";
	else {
		float amt;
		cout << "Enter amount to be deposited: \n";
		cin >> amt;
		temp->balance += amt;
		cout << temp->name <<", your balance is " << temp->balance << endl;
	}
}
void withdraw(struct node* head) {
	int accNo;
	cout << "Enter Account Number: ";
	cin >> accNo;
	struct node* temp = head;
	while (temp != NULL) {
		if (temp->acctNo == accNo) break;
		temp = temp->next;
	}
	if (temp == NULL)
		cout << "Invalid Account Number\n";
	else {
		float amt;
		cout <<temp->name << ", how much would you like to withdraw? ";
		cin >> amt;
		if (amt > temp->balance) {
			cout << "Not enough balance\n";
			return;
		}
		temp->balance -= amt;
		cout << temp->name << ", your new balance is " << temp->balance << endl;
	}
}
void showAll(struct node* head) {
	struct node* temp = head;
	cout << "All->";
	while (temp != NULL) {
		cout << temp->acctNo << "," << temp->name << "->" ;
		temp = temp->next;
	}
	cout << "NULL\n";
}
void closeAcc(struct node* head) {
	int accNo;
	cout << "Enter Account Number: ";
	cin >> accNo;
	if (head->acctNo == accNo) {
		cout << head->name;
		head = head->next;
		cout << ", we closed your account\n";
		return;
	}
	struct node* temp = head;
	struct node* prev = head;
	while (temp != NULL) {
		if (temp->acctNo == accNo) break;
		prev = temp;
		temp = temp->next;
	}
	if (temp == NULL)
		cout << "Invalid Account Number\n";
	else {
		cout << temp->name;
		prev->next = temp->next;
		temp->next = NULL;
		free(temp);
		cout << ", we closed your account\n";
	}
}
int main() {
	struct node* head = NULL;
	head = new struct node;
	//dummy node
	head->acctNo = -1;
	head->name = " ";
	head->balance = 0.0;
	struct node* temp = head;
	ifstream file("data.txt");
	string line;
	while (getline(file, line)) {
		struct node* neww = NULL;
		neww = new struct node;
		stringstream ss(line);
		int a;
		ss >> a;
		string n;
		ss >> n;
		float bal;
		ss >> bal;
		neww->acctNo = a;
		neww->name = n;
		neww->balance = bal;
		neww->next = NULL;
		temp->next = neww;
		temp = temp->next;
	}
	char c;
	do {
		int ch;
		cout << "Please enter your choice(1-5): ";
		cin >> ch;
		switch (ch) {
		case 1:
			showBalance(head->next);
			break;
		case 2:
			deposit(head->next);
			break;
		case 3:
			withdraw(head->next);
			break;
		case 4:
			showAll(head->next);
			break;
		case 5:
			closeAcc(head->next);
			break;
		default:
			cout << "Invalid choice";
			break;
		}

		cout << "Continue? (y/n)" << endl;
		cin >> c;
	} while (c != 'n');
	return 0;
}