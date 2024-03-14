// Q_1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
//
//
// / -----------------------------------------------------------------------------------------------------------------------
//Name                          Sai Chaitanya Kilambi
//Course                        CPSC 131 Data Structures, Fall, 2022
//Assignment                    No.14 question:1
//Due date                      12/07/2022
// Purpose:
// This program demonstrates operator overloading
//------------------------------------------------------------------------------------------------------------------------
// list of libraries
//
//importing the required libraries

#include <iostream>
using namespace std;

//creating FRACT class
class FRACT {
private:
    int num, den;

public:
    void readFraction()
    {
        cout << "Enter a fraction: ";
        cin >> num;
        cin.ignore();
        cin >> den; // cin.ignore() to skip the “/”
    }
    FRACT friend operator+(FRACT f1, FRACT f2)
    {
        FRACT sum;
        sum.num = (f1.num * f2.den + f1.den * f2.num);
        sum.den = (f1.den * f2.den);
        return sum;
    }
    FRACT friend operator-(FRACT f1, FRACT f2)
    {
        FRACT diff;
        diff.num = (f1.num * f2.den - f1.den * f2.num);
        diff.den = (f1.den * f2.den);
        return diff;
    }
    FRACT friend operator*(FRACT f1, FRACT f2)
    {
        FRACT prod;
        prod.num = (f1.num * f2.num);
        prod.den = (f1.den * f2.den);
        return prod;
    }
    FRACT friend operator/(FRACT f1, FRACT f2)
    {
        //finding reciprocal of f2 (flipping numerator and denominator)
        FRACT reciprocal;
        reciprocal.num = f2.den;
        reciprocal.den = f2.num;
        //multiplying reciprocal of f2 with f1 to get the result of f1/f2
        return f1 * reciprocal;
    }

 
    void friend displayFract(FRACT f, bool parentheses = false)
    {
        //if parentheses is true, printing in format (a/b), otherwise simply printing
        //in format: a/b
        if (parentheses) {
            cout << "(" << f.num << "/" << f.den << ")";
        }
        else {
            cout << f.num << "/" << f.den;
        }
    }
};

//main function
int main()
{
    FRACT frac1, frac2, fracSum, fracDiff, fracPro, fracDiv;
    frac1.readFraction();
    frac2.readFraction();

    //performing operations
    fracSum = frac2 + frac1;
    fracDiff = frac2 - frac1;
    fracPro = frac2 * frac1;
    fracDiv = frac2 / frac1;

    //display result
    displayFract(frac2);
    cout << " + ";
    displayFract(frac1);
    cout << " = ";
    displayFract(fracSum);
    cout << endl;

    displayFract(frac2);
    cout << " - ";
    displayFract(frac1);
    cout << " = ";
    displayFract(fracDiff);
    cout << endl;

    displayFract(frac2);
    cout << " * ";
    displayFract(frac1);
    cout << " = ";
    displayFract(fracPro);
    cout << endl;


    displayFract(frac2, true);
    cout << " / ";
    displayFract(frac1, true);
    cout << " = ";
    displayFract(fracDiv, true);
    cout << endl;
    system("pause");
    return 0;
}