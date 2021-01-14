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

template<typename var>
struct Node
{
	var data;
	shared_ptr<Node> nextLink = nullptr;
};

template<typename var>
class linkedList
{
	shared_ptr< Node<var> > Head;

public:
	linkedList()
	{
		this->Head = nullptr;
	};

	linkedList(var data)
	{
		this->Head = make_shared<Node<var>>();
		this->Head->data = data;
	};

	void appendData(var data)
	{
		auto Temp = make_shared<Node<var>>();
		Temp->data = data;
		Temp->nextLink = this->Head;
		this->Head = Temp;
	};

	void printlinkedList()
	{
		shared_ptr<Node<var>> Pointer = this->Head;
		while(Pointer->nextLink != nullptr)
		{
			cout << Pointer->data << "   ";
			Pointer = Pointer->nextLink;
		}
		cout << Pointer->data << endl;
	};

	void reverselinkedList(){
		shared_ptr<Node<var>> Pointer = this->Head;
		shared_ptr<Node<var>> goNext = nullptr;
		shared_ptr<Node<var>> auxPointer = nullptr;

		while(Pointer->nextLink != nullptr)
		{
			goNext = Pointer->nextLink;
			Pointer->nextLink = auxPointer;
			auxPointer = Pointer;
			Pointer = goNext;
		}
		Pointer->nextLink = auxPointer;

		this->Head = Pointer;
	};

	~linkedList(){};
};

#endif /* SRC_LINKEDLIST_H_ */
