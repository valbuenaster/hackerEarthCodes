/*
 * linkedList.h
 *
 *  Created on: Jan 7, 2021
 *      Author: luis
 */

#ifndef SRC_LINKEDLIST_H_
#define SRC_LINKEDLIST_H_

#include <iostream>
#include <memory>
using namespace std;

struct Nd
{
	double data = 0.0;
	shared_ptr<struct Nd> nextLink = nullptr;
}typedef Node;


class linkedList
{
	shared_ptr< Node > Head;

public:
	linkedList();
	linkedList(double data);

	void appendData(double data);
	void printlinkedList();
	void reverselinkedList();
	~linkedList();
};



#endif /* SRC_LINKEDLIST_H_ */
