// Question_2.cpp : This file contains the 'main' function.Program execution begins and ends there.
//
//
// /
//------------------------------------------------------------------------ -----------------------------------------------
//Name Sai Chaitanya Kilambi
//Course CPSC 131 Data Structures, Fall, 2022
//Assignment No.6b question:2
//Due date 10/12/2022
// Purpose:
// This program performs postfix arthmatic
//----------------------------------------------------------------------------------------------------------------------- -
// list of libraries
//
//importing the required libraries
#include <iostream>
#include<string>


using namespace std;


//function to check if both the brackets are present
bool checkBalance(string str)

{
    bool f = true;
    int c;
    c = 0;
    int i;
    //for loop over the string
    for (i = 0; i < str.length(); i++)
    {
        if (str[i] == '(')
        {
            c++;
        }
        else
        {
            c--;
        }
        if (c < 0)
        {
            f = false;
            break;
        }
    }

    if (c != 0)
    {
        f = false;
    }
    return f;
}

//main function
int main()

{
    while (1)
    {
        //input prompt
        cout << "\nEnter an algebraic expression with $ at the end : ";

        string str, str1;

        cin >> str;


        //going over the input
        for (int i = 0; i < str.size(); i++)

        {

            if (str[i] == ')' || str[i] == '(')

            {

                str1 = str1 + str[i];

            }

        }


        // calling the check function
        if (checkBalance(str1))

        {

            cout << "( and ) are balanced" << endl;

        }

        else

        {

            cout << "( and ) are not balanced" << endl;

        }
        //input prompt fo the flag

        cout << "\nCONTINUE(y/n)?";

        char ch;

        cin >> ch;
        
        if (ch != 'y')

        {

            break;

        }

    }

    return 0;

}