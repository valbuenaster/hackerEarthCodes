#include <iostream>
#include <list>
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;

struct Nd
{
    unsigned int Data;
    unsigned int Level;
    bool isLeave = true;

    struct Nd * Parent = nullptr;
    vector<struct Nd *> Children;

}typedef Node;

class Tree
{
    public:
    unsigned int N_Nodes;
    list<Node*> buffer;
    vector<Node*> buffer_leaves;
    Node * Root;

    Tree();
    Tree(unsigned int data);
    bool addNode(Node * pointer,unsigned int &dataParent,unsigned int &data);
    void printTree();
    void collectLeaves();
    Node * returnCommonFather(Node *p1,Node *p2);

    ~Tree();
};

Tree::Tree()
{
    Root = new Node;
    Root->Level = 0;
    this->N_Nodes = 1;
}

Tree::Tree(unsigned int data)
{
    Root = new Node;
    Root->Data = data;
    Root->Level = 0;
    this->N_Nodes = 1;
}

Tree::~Tree()
{
    delete Root;
}

void Tree::printTree()
{
//By Level
    Node * Pointer;
    unsigned int level = 0;

    this->buffer.push_back(Root);

    while(this->buffer.size()>0)
    {
        Pointer = this->buffer.front();
        this->buffer.pop_front();

        if((Pointer->Level)>level) cout<<endl;
        cout<< Pointer->Data<< " ";
        level = Pointer->Level;

        if(Pointer->Children.size() != 0)
        {
            for(auto Elem:Pointer->Children) this->buffer.push_back(Elem);
        }
    }
    cout<<endl;
}

bool Tree::addNode(Node * pointer,unsigned int &dataParent,unsigned int &data)
{
    bool retVal = false;

    if(pointer->Data == dataParent)
    {
        Node * Temp = new Node;
        Temp->Data = data;
        Temp->Parent = pointer;
        Temp->Level = (pointer->Level) + 1;

        pointer->isLeave = false;

        pointer->Children.push_back(Temp);
        retVal = true;           
        this->N_Nodes +=1;
    }else{
        if(pointer->Children.size()==0)
        {
            retVal = false;
        }else{
            for(auto Elem:pointer->Children) retVal |= addNode(Elem, dataParent, data);
        }
    }
    return retVal;
}

void Tree::collectLeaves()
{
    this->buffer_leaves.clear();

//By depth
//The last element is the deepest leave
    Node * Pointer;
    unsigned int maxlevel = 0;
    Node * maxDepthPointer = nullptr;

    this->buffer.push_back(Root);

    while(this->buffer.size()>0)
    {
        Pointer = this->buffer.front();
        this->buffer.pop_front();

        if(Pointer->isLeave)
        {
            if(maxlevel < Pointer->Level)
            {
                maxlevel = Pointer->Level;
                if(maxDepthPointer!=nullptr)
                {
                    this->buffer_leaves.push_back(maxDepthPointer);
                }
                maxDepthPointer = Pointer;
            }else{
                this->buffer_leaves.push_back(Pointer);
            }
        }

        if(Pointer->Children.size()!=0)
        {
            for(auto Elem:Pointer->Children) this->buffer.push_front(Elem);
        } 
    }
   this->buffer_leaves.push_back(maxDepthPointer); 
}
/*
vector<Node *> findAncestry(Node *p)
{
    vector<Node *> retVal;
    while(p->Parent!=nullptr)
    {
        retVal.push_back(p);
        p = p->Parent;
    }
    retVal.push_back(p);

    return retVal;
}
Node * Tree::returnCommonFather(Node *p1,Node *p2)
{
    vector<Node *> ancestry1 = findAncestry(p1);
    vector<Node *> ancestry2 = findAncestry(p2);
    unsigned int tt = 0;
    unsigned int Lim1 = ancestry1.size();
    unsigned int Lim2 = ancestry2.size();
    unsigned int Limit = min(Lim1,Lim2);

    for(tt = 1;tt <Limit;tt++)
    {
        if(ancestry1[Lim1-tt]->Data!=ancestry2[Lim2-tt]->Data) break;
    }
    Node * retVal = ancestry1[Lim1-tt+1];


    return retVal;
}
*/

Node * Tree::returnCommonFather(Node *p1,Node *p2)
{
    Node * retVal;
    Node * pp1 =p1;
    Node * pp2 =p2;
    unsigned int diff = 0;

    if(pp1->Level > pp2->Level)
    {
        diff =pp1->Level - pp2->Level;
        for(unsigned int aa=0;aa<diff;aa++) pp1 = pp1->Parent;
    }else
    {
        diff =pp2->Level - pp1->Level;
        for(unsigned int aa=0;aa<diff;aa++) pp2 = pp2->Parent;
    }

    while(pp1->Parent!=pp2->Parent)
    {
        pp1 = pp1->Parent;
        pp2 = pp2->Parent;
    }

    return pp1->Parent;
}

int main()
{
    unsigned int N = 0;
    unsigned int P = 0;
    unsigned int C = 0;

    unsigned int Maximum = 0;

    Tree Arbol1;
    Tree Arbol2;
    Tree *Arbol;
    Node * Ancestor;
    Node * p1;
    Node * p2;
    Node * p1Max;
    Node * p2Max;
    cin >> N;

    unsigned int CCounter1 = 1;
    unsigned int CCounter2 = 1;

    for(unsigned int nn = 0;nn<N-1;nn++)
    {
        cin >> P >> C;

        if(nn==0)
        {
            Arbol1.Root->Data = P;
            Arbol2.Root->Data = C;
        }
        if(!Arbol1.addNode(Arbol1.Root, P, C)) CCounter1++;
        if(!Arbol2.addNode(Arbol2.Root, C, P)) CCounter2++;
    }

    if(Arbol1.N_Nodes > Arbol2.N_Nodes)
    {
        Arbol = &Arbol1;
    }else{
        Arbol = &Arbol2;
    }

    Arbol->collectLeaves();
    unsigned int SSize = Arbol->buffer_leaves.size();

    if(SSize==1)
    {
        p1Max = Arbol->buffer_leaves[0];
        p2Max = Arbol->Root;
    }else{

        p1Max = Arbol->buffer_leaves.back();
        Arbol->buffer_leaves.pop_back();

        SSize = Arbol->buffer_leaves.size();

        for(unsigned int ii=0;ii<SSize;ii++)
        {
            p2 = Arbol->buffer_leaves[ii];        
            Ancestor = Arbol->returnCommonFather(p1Max,p2);

            if((Ancestor->Level == 0) && ( (p1Max->Level) + (p2->Level) > Maximum ))
            {
                Maximum = (p1Max->Level) + (p2->Level);
                p2Max = p2;
            }   
        }
    }

    if(p1Max->Data < p2Max->Data)
    {
        cout<< p1Max->Data <<" "<< p2Max->Data <<endl;
    }else{
        cout<< p2Max->Data <<" "<< p1Max->Data <<endl;
    }
    //cout<<endl<<"p1Max->Data = "<< p1Max->Data <<", p1Max->Level = "<< p1Max->Level <<endl;
    //cout<<"p2Max->Data = "<< p2Max->Data <<", p2Max->Level = "<< p2Max->Level <<endl;
}
