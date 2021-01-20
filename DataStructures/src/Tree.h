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
#include <list>
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

	bool operator == (const NodeT obj)
	{
		bool retVal = true;

		retVal &= (ID == obj.ID);
		retVal &= (Level == obj.Level);
		retVal &= (Data == obj.Data);
		retVal &= (flagA == obj.flagA);
		retVal &= (flagB == obj.flagB);
		retVal &= (flagC == obj.flagC);

		return retVal;
	}
};


template<typename var>
class Tree
{
	unsigned int counter_ID = 0;
	shared_ptr<NodeT<var>> Root;
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
		list< shared_ptr< NodeT<var> > > bag;
		shared_ptr< NodeT<var> > node;
		bag.push_back(this->Root);

		while(bag.size() > 0)
		{
			node = bag.front();

			for(auto m : node->Children) bag.push_back(m);
			if(node->Data == Parent_Data)
			{
				retVal = true;
				auto temp = makeNode(node, Data);
				break;
			}

			bag.pop_front();
		}
		return retVal;
	};

	bool insertData(unsigned int Parent_ID, var Data)
	{
		bool retVal = false;
		list< shared_ptr< NodeT<var> > > bag;
		shared_ptr< NodeT<var> > node;
		bag.push_back(this->Root);

		while(bag.size() > 0)
		{
			node = bag.front();

			for(auto m : node->Children) bag.push_back(m);
			if(node->ID == Parent_ID)
			{
				retVal = true;
				auto temp = makeNode(node, Data);
				break;
			}

			bag.pop_front();
		}
		return retVal;
	};

	void removeNodeFromVector(shared_ptr< NodeT<var> > node,
			                  vector< shared_ptr< NodeT<var> > > & nodeVector)
	{
		unsigned int counter = 0;

		for(auto n: nodeVector)
		{
			if(n == node)
			{
				nodeVector.erase( nodeVector.begin() + counter);
			}else{
				counter++;
			}
		}
	};

	shared_ptr< NodeT<var> > findNode(unsigned int id, var data)
	{
		shared_ptr< NodeT<var> > retVal;
		list< shared_ptr< NodeT<var> > > bag;
		shared_ptr< NodeT<var> > node;
		bag.push_back(this->Root);

		while(bag.size() > 0)
		{
			node = bag.front();
			for(auto m : node->Children) bag.push_back(m);

			if((node->ID == id)&&(node->Data == data))
			{
				retVal = node;
				break;
			}
			bag.pop_front();
		}
		return retVal;
	};

	shared_ptr< NodeT<var> > findNode(unsigned int id)
	{
		shared_ptr< NodeT<var> > retVal;
		list< shared_ptr< NodeT<var> > > bag;
		shared_ptr< NodeT<var> > node;
		bag.push_back(this->Root);

		while(bag.size() > 0)
		{
			node = bag.front();
			for(auto m : node->Children) bag.push_back(m);

			if(node->ID == id)
			{
				retVal = node;
				break;
			}
			bag.pop_front();
		}
		return retVal;
	};

	/* It is required to overload the comparizon operation of
	 * the object that takes the place of var.
	 * */
	shared_ptr< NodeT<var> > findNode(var data)
	{
		shared_ptr< NodeT<var> > retVal;
		list< shared_ptr< NodeT<var> > > bag;
		shared_ptr< NodeT<var> > node;
		bag.push_back(this->Root);

		while(bag.size() > 0)
		{
			node = bag.front();
			for(auto m : node->Children) bag.push_back(m);

			if(node->Data == data)
			{
				retVal = node;
				break;
			}
			bag.pop_front();
		}
		return retVal;
	};

	void updateLevel4Children(shared_ptr< NodeT<var> > Ptr)
	{
		list< shared_ptr< NodeT<var> > > bag;
		shared_ptr< NodeT<var> > node;

		for(auto c : Ptr->Children) bag.push_back(c);

		while(bag.size() > 0)
		{
			node = bag.front();
			bag.pop_front();
			node->Level = node->Parent->Level + 1;

			for(auto c : node->Children) bag.push_front(c);
		}
	};

	bool removeNodeByID(unsigned int id)
	{
		bool retVal = false;
		auto node = this->findNode(id);
		auto nodeParent = node->Parent;

		removeNodeFromVector(node,nodeParent->Children);

		for(auto & n : node->Children)
		{
			n->Level -= 1;
			updateLevel4Children(n);
			nodeParent->Children.push_back(n);
		}

		return retVal;
	};

	bool removeNodeByData(var data)
	{
		bool retVal = false;
		auto node = this->findNode(data);
		auto nodeParent = node->Parent;

		removeNodeFromVector(node,nodeParent->Children);

		for(auto & n : node->Children)
		{
			n->Level -= 1;
			updateLevel4Children(n);
			nodeParent->Children.push_back(n);
		}

		return retVal;
	};

	bool removeNode(unsigned int id, var data)
	{
		bool retVal = false;
		auto node = this->findNode(id, data);
		auto nodeParent = node->Parent;

		removeNodeFromVector(node,nodeParent->Children);

		for(auto & n : node->Children)
		{
			n->Level -= 1;
			updateLevel4Children(n);
			nodeParent->Children.push_back(n);
		}

		return retVal;
	};

	void printTree()
	{
		int L = -1;
		shared_ptr< NodeT<var> > retVal;
		list< shared_ptr< NodeT<var> > > bag;
		shared_ptr< NodeT<var> > node;
		bag.push_back(this->Root);

		while(bag.size() > 0)
		{
			node = bag.front();
			for(auto m : node->Children) bag.push_back(m);

			if( static_cast<int>( node->Level ) != L)
			{
				cout << endl << "Level " << node->Level << endl;
				L = node->Level;
			}
			cout << node->Data << "("<< node->Level <<") ";

			bag.pop_front();
		}
		cout << endl ;
	};

	~Tree(){};
};


#endif /* SRC_TREE_H_ */
