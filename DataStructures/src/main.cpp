/*
 * main.cpp
 *
 *  Created on: Jan 7, 2021
 *      Author: luis
 */


#include <iostream>

#include "linkedList.h"
#include "Tree.h"
#include "assortedFunctions.h"

using namespace std;

int main(int argc, char** argv)
{
	int tempI = 0;
	float tempF = 0;
	double tempD = 0;
	string tempString = argv[1];

	//shared_ptr<linkedList<float>> myList = make_shared<linkedList<float>>();
	auto myList = make_shared< linkedList<int> >();
	auto myTree = make_shared< Tree<int> >( string2num<int>(tempString) );

	cout << "Data Structures, argc = " << argc << endl;

	for(int ii = 1; ii < argc; ii++)
	{
		cout << "argv[" << ii << "] = " << argv[ii] << endl;
		tempString = argv[ii];
		tempI = string2num<int>(tempString);
		tempF = string2num<float>(tempString);
		tempD = string2num<double>(tempString);

		//cout <<"tempI ="<< tempI <<", tempF ="<< tempF <<", tempD ="<< tempD << endl << endl;
		myList->appendData(tempI);

		if( ii % 2 == 0)
		{
			tempString = argv[ii+1];
			int tempIp1 = string2num<int>(tempString);
			myTree->insertData(tempI,tempIp1);
		}
	}

	cout << "Printing linked list..." << endl;
	myList->reverselinkedList();
	cout << endl;
	myList->printlinkedList();

	cout << "Printing Tree ..." << endl;
	myTree->printTree();

	return 0;
}

