/*
 * main.cpp
 *
 *  Created on: Jan 7, 2021
 *      Author: luis
 */


#include <iostream>

#include "linkedList.h"
#include "assortedFunctions.h"

using namespace std;

int main(int argc, char** argv)
{
	//int tempI = 0;
	//float tempF = 0;
	double tempD = 0;
	string tempString;

	shared_ptr<linkedList> myList = make_shared<linkedList>();

	cout << "Data Structures, argc = " << argc << endl;

	for(int ii = 1; ii < argc; ii++)
	{
		cout << "argv[" << ii << "] = " << argv[ii] << endl;
		tempString = argv[ii];
		//tempI = string2num<int>(tempString);
		//tempF = string2num<float>(tempString);
		tempD = string2num<double>(tempString);

		//cout <<"tempI ="<< tempI <<", tempF ="<< tempF <<", tempD ="<< tempD << endl << endl;
		myList->appendData(tempD);
	}

	cout << "Printing linked list..." << endl;
	myList->reverselinkedList();
	cout << endl;
	myList->printlinkedList();

	return 0;
}

