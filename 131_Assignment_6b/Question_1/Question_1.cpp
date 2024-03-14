// Question_1.cpp : This file contains the 'main' function.Program execution begins and ends there.
//
//
// /
//------------------------------------------------------------------------ -----------------------------------------------
//Name Sai Chaitanya Kilambi
//Course CPSC 131 Data Structures, Fall, 2022
//Assignment No.6b question:1
//Due date 10/12/2022
// Purpose:
// This program performs postfix arthmatic
//----------------------------------------------------------------------------------------------------------------------- -
// list of libraries
//
//importing the required libraries

#include <iostream>
#include<string>
#include "STACKPAC.h"
using namespace std;

bool isNum(string str) 
{
	for (int i = 0; i < str.length(); i++) 		
		if (isdigit(str[i]) == false) 	
			return false;
	return true; 
}
int main(){ 	

	Stack<int, 100> s1;
	s1.clearStack();
	// s is string for taking in input 
	string s; 	
	// s2 is string array to store split words 
	string s2[100]; 	
	cout<<"Enter a postfix expression:"; 	
	// getline is used to take input string which have spaces 	
	getline(cin,s); 	
	// ind is index for s2 to store words 
	int i,ind=0; 
	string word=""; 	
	// we access each character in s if we get space then store that word in s2 	
	// else add each character to word 
	for(i=0;i<s.length();i++){ 	
		if(s[i]==' ')
		{ 			
			s2[ind]=word; 			
			ind++; 			
			// making word empty to use it for another word
			word=""; 	
		} 		
		else 		
			word=word+s[i];
	} 	
	// str have the postfix expression
	string str=""; 	
	// t is used to ask inputs
	string t; 	
	// accessing each word in s2
	// check whether it is number using isNum or + or - or * or / if true then add them to str 	
	// else ask user to enter int value of that variable 	
	for(i=0;i<ind;i++){ 	
		if(isNum(s2[i]) || s2[i]=="+" || s2[i]=="*" || s2[i]=="-" || s2[i]=="/" )
		{ 			
			str = str + s2[i]+" "; 
		} 		
		else{ 			
			//do while loop because if again user enters string value rather than int 		
			do{ 			
				cout << "Enter value of "<<s2[i]<<":"; 		
				cin >> t; 	
			}
			while(isNum(t)!=true); 
			// adding newly entered value to str 	
			str = str + t + " "; 	
		}			 
	} 	
	// num stores the number which is in string form 	
	int num=0; 	
	// accessing each element in the str i.e postfix expression 	
	for(i=0;i<str.length();i++){
		// space or num is not zero then num is pushed to stack and making num to 0 for next number 		
		if(str[i]==' ' && num!=0){ 
			s1.pushStack(num); 		
			num=0;		
		} 		
		// if we encounterd number then we convert that char to number 
		else if(isdigit(str[i])){ 	
			num = num * 10 + int(str[i]-'0');
		} 		
		// if we encountered +,/,*,- then we pop top 2 elements of stack and do respective operation and push them again into stack
		else if(str[i]=='+' || str[i]=='*' || str[i]=='-' || str[i]=='/'){ 
			int a,b; 
			a=s1.popStack();
 			b= s1.popStack();
		switch(str[i]){ 	
		case '+':s1.pushStack(b+a);break; 				
		case '-':s1.pushStack(b-a);break;
		case '*':s1.pushStack(b*a);break;
		case '/':s1.pushStack(b/a);break;
		} 
		} 	
	} 
	// after doing all operations there will be only 1 element in stack which is the value of postfix expression 
	cout<<"\tValue of postfix expression is "<<s1.popStack(); 	
	return 0; 
} 


