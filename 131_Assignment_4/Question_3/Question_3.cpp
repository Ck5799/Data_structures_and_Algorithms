// /---------------------------------------------------------------------------------------------------------------------- -
//Name Sai Chaitanya Kilambi
//Course CPSC 131 Data Structures, Fall, 2022
//Assignment No.4 question:3
//Due date 09/21/2022
// Purpose:
// This program generates 13 random numbers<100 and stores them in an array, compute their average and sort them into two 
// vector depending on if they are > avg or < avg  
// ------------------------------------------------------------------------------------------------------------------------
// list of libraries
//
//importing the required libraries

#include <iostream>
#include<vector>


int main()

{

    int num[13];

    //generating 13 random numbers less than 100
    for (int i = 0; i < 13; i++)

    {

        num[i] = rand() % 100;

    }

    for (int i = 0; i < 13; i++)

    {

        std::cout << num[i] << " ";

    }

    std::cout << std::endl;


    //computing Average 
    double avg = 0;

    for (int i = 0; i < 13; i++)

    {

        avg += num[i];

    }

    avg = avg / 13.0;
    
    
    //storing the numbers in vLess and vAbove 
    std::vector<int> vLess, vAbove;

    for (int i = 0; i < 13; i++)

    {

        if (num[i] < avg)

            vLess.push_back(num[i]);

        else

            vAbove.push_back(num[i]);

    }

    //printing vLess vector
    for (int i = 0; i < vLess.size(); i++)

    {

        std::cout << vLess[i] << " ";

    }

    std::cout << std::endl;


    //printing vAbove vector
    for (int i = 0; i < vAbove.size(); i++)

    {

        std::cout << vAbove[i] << " ";

    }
    std::cout << std::endl;

    return 0;

}
