/*
 * linkedList.cpp
 *
 *  Created on: Jan 7, 2021
 *      Author: luis
 */


#include "linkedList.h"

using namespace std;

linkedList::linkedList()
{
	this->Head = nullptr;
}

linkedList::linkedList(double data)
{
	this->Head = make_shared<Node>();
	this->Head->data = data;
}

void linkedList::appendData(double data)
{
	auto Temp = make_shared<Node>();
	Temp->data = data;
	Temp->nextLink = this->Head;
	this->Head = Temp;
}

void linkedList::printlinkedList()
{
	shared_ptr<Node> Pointer = this->Head;
	while(Pointer->nextLink != nullptr)
	{
		cout << Pointer->data << " ";
		Pointer = Pointer->nextLink;
	}
	cout << Pointer->data << endl;
}

void linkedList::reverselinkedList()
{
	shared_ptr<Node> Pointer = this->Head;
	shared_ptr<Node> goNext = nullptr;
	shared_ptr<Node> auxPointer = nullptr;

	while(Pointer->nextLink != nullptr)
	{
		goNext = Pointer->nextLink;
		Pointer->nextLink = auxPointer;
		auxPointer = Pointer;
		Pointer = goNext;
	}
	Pointer->nextLink = auxPointer;

	this->Head = Pointer;
}

linkedList::~linkedList()
{}
