// / -----------------------------------------------------------------------------------------------------------------------
//Name                          Sai Chaitanya Kilambi
//Course                        CPSC 131 Data Structures, Fall, 2022
//Assignment                    No.2 question:1
//Due date                      09/07/2022
// Purpose:
// his program copies the data from a text file and calculates the total number of students, total number of female students, total number of graduate students and total number of undergrad students in orange campus 
//------------------------------------------------------------------------------------------------------------------------
// list of libraries
//
//importing the required libraries

#include<iostream>

#include<fstream>


//function for copying the data from the file.txt file into a 3D array
void copyData(std::string f_name, int X[2][4][2]) {
	std::fstream f;
	f.open(f_name, std::ios::in);
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 4; j++) {
			for (int k = 0; k < 2; k++) {
				f >> X[i][j][k];
			}
		}
	}
	f.close();
}
//function for calculating total number of students
int findTotalStud(int X[2][4][2]) {
	int total = 0;
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 4; j++) {
			for (int k = 0; k < 2; k++) {
				total += X[i][j][k];
			}
		}
	}
	return total;
}

//function for calculating total number of Female students
int findFemales(int X[2][4][2]) {
	int total = 0;
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 4; j++) {
			total += X[i][j][0];
		}
	}
	return total;

}

//function for calculating total number of Graduate students
int findGrads(int X[2][4][2]) {
	int total = 0;
	for (int j = 0; j < 4; j++) {
		for (int k = 0; k < 2; k++) {
			total += X[1][j][k];
		}
	}
	return total;
}

//function for calculating total number of undergraduate students at orange campus
int findunderGradOrange(int X[2][4][2]) {
	int total = 0;
	for (int k = 0; k < 2; k++) {
		total += X[0][1][k];
	}
	return total;
}

//main function
int main() {
	int stud[2][4][2];//created a 3D array

	//calling copy function
	copyData("file.txt", stud);

	//calling the function to calculate the total number of students
	int totalStud = findTotalStud(stud);
	std::cout << "The total number of Students: " << totalStud << std::endl;//print statement

	//calling the function to calculate the total number of female students
	int totalFemales = findFemales(stud);
	std::cout <<"The total number of Female Students: "<< totalFemales << std::endl;//print statement

	//calling the function to calculate the total number of Graduate students
	int totalGrads = findGrads(stud);
	std::cout <<"The total number of Graduates: "<< totalGrads << std::endl;//print statement

	//calling the function to calculate the total number of UnderGraduate students at orange campus
	int underGradOrange = findunderGradOrange(stud);
	std::cout <<"The total number of Under Graduates of Orange Campus: " <<underGradOrange << std::endl;//print statement

	return 0;
}