/*
 * Tree.h
 *
 *  Created on: Jan 8, 2021
 *      Author: luis
 */

#ifndef SRC_TREE_H_
#define SRC_TREE_H_

#include <iostream>
#include <vector>
#include <memory>

using namespace std;

template<typename var>
struct NodeT
{
	unsigned int ID;
	unsigned int Level;
	var Data;

	bool flagA = false;
	bool flagB = false;
	bool flagC = false;

	shared_ptr<NodeT> Parent = nullptr;
	vector< shared_ptr<NodeT> > Children;
};

template<typename var>
class Tree
{
	unsigned int counter_ID = 0;
	shared_ptr<NodeT<var>> Root;
	vector< vector< shared_ptr< NodeT<var> > > > NodesperLevel;
public:
	Tree()
	{
		this->Root = nullptr;
	};

	Tree(var Data)
	{
		this->Root = make_shared< NodeT<var> >();
		this->Root->Data = Data;
		this->Root->ID = counter_ID;
		this->Root->Level = 0;
		counter_ID++;

		vector< shared_ptr< NodeT<var> > > temp;
		temp.push_back(this->Root);
		this->NodesperLevel.push_back(temp);
	};

	shared_ptr< NodeT<var> > makeNode(shared_ptr< NodeT<var> > Parent, var Data)
	{
		shared_ptr< NodeT<var> > retVal = make_shared<NodeT<var>>();
		retVal->Data = Data;
		retVal->Parent = Parent;
		retVal->Level = Parent->Level + 1;
		retVal->ID = this->counter_ID;

		Parent->Children.push_back(retVal);
		this->counter_ID++;
		return retVal;
	};

	bool insertData(var Parent_Data, var Data)
	{
		bool retVal = false;

		for(auto vectLevel: this->NodesperLevel)
		{
			for(auto node: vectLevel)
			{
				if(node->Data == Parent_Data)
				{
					retVal = true;
					auto temp = makeNode(node, Data);

					if(temp->Level <= this->NodesperLevel.size() -1)
					{
						this->NodesperLevel[temp->Level].push_back(temp);
					}else{
						vector< shared_ptr< NodeT<var> > > tempVect;
						tempVect.push_back(temp);
						this->NodesperLevel.push_back(tempVect);
					}
					break;
				}
			}
		}

		return retVal;
	};

	bool insertData(unsigned int Parent_ID, var Data)
	{
		bool retVal = false;

		for(auto vectLevel: this->NodesperLevel)
		{
			for(auto node: vectLevel)
			{
				if(node->ID == Parent_ID)
				{
					retVal = true;
					auto temp = makeNode(node, Data);

					this->NodesperLevel[temp->Level].push_back(temp);
					break;
				}
			}
		}

		return retVal;
	};

	void printTree()
	{
		unsigned int L = 0;
		for(auto vectLevel: this->NodesperLevel)
		{
			cout << "Level " << L << endl;
			for(auto node: vectLevel)
			{
				cout << node->Data << " ";
			}
			cout << endl;
			L++;
		}
	};

	~Tree(){};
};


#endif /* SRC_TREE_H_ */
