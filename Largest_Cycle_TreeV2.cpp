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
    Node * Pointer;
    unsigned int level = 0;

    this->buffer.push_back(Root);

    while(this->buffer.size()>0)
    {
        Pointer = this->buffer.front();
        this->buffer.pop_front();

        if(Pointer->isLeave) this->buffer_leaves.push_back(Pointer);

        if(Pointer->Children.size()!=0)
        {
            for(auto Elem:Pointer->Children) this->buffer.push_front(Elem);
        } 
    }
}
/*
vector<Node *> findAncestry(Node *p)
{
    vector<Node *> retVal;
    //cout<<"Inside findAncestry("<<p->Data <<")"<<endl;
    while(p->Parent!=nullptr)
    {
        retVal.push_back(p);
        //cout<<"p->Data "<<p->Data <<endl;
        p = p->Parent;
    }
    retVal.push_back(p);
    //cout<<"p->Data "<<p->Data <<endl;

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

    //cout<<"Inside Tree::returnCommonFather("<<p1->Data<<","<<p2->Data<<")"<<endl;

    for(tt = 1;tt <Limit;tt++)
    {
        //cout<<"comp "<<ancestry1[Lim1-tt]->Data <<"!="<<ancestry2[Lim2-tt]->Data <<endl;
        if(ancestry1[Lim1-tt]->Data!=ancestry2[Lim2-tt]->Data) break;
    }
    Node * retVal = ancestry1[Lim1-tt+1];

    //cout <<"tt = "<<tt<<", Node "<<retVal->Data<<", level "<<retVal->Level<<endl;

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
/*
    cout <<endl;
    cout <<CCounter1<<" Elements could not be inserted in Arbol1 as P father and C child"<<endl;
    cout <<CCounter2<<" Elements could not be inserted in Arbol2 as C father and P child"<<endl;

    cout <<endl<<"Imprimiendo arbol1 with "<<Arbol1.N_Nodes<<endl;
    Arbol1.printTree();

    cout <<endl<<"Imprimiendo arbol2 with "<<Arbol2.N_Nodes<<endl;
    Arbol2.printTree();
*/
    if(Arbol1.N_Nodes > Arbol2.N_Nodes)
    {
        Arbol = &Arbol1;
    }else{
        Arbol = &Arbol2;
    }

    Arbol->collectLeaves();
/*
    cout <<endl<<"printing leaves..."<<endl;
    for(auto Elem:Arbol->buffer_leaves) cout<<Elem->Data<<". ";
    cout<<endl;
*/
    unsigned int SSize = Arbol->buffer_leaves.size();

    //cout<<"SSize = "<<SSize<<endl;

    if(SSize==1)
    {
        p1Max = Arbol->buffer_leaves[0];
        p2Max = Arbol->Root;
    }else{
        for(unsigned int ii=0;ii<SSize-1;ii++)
        {
            for(unsigned int jj=ii+1;jj<SSize;jj++)
            {
                p1 = Arbol->buffer_leaves[ii];
                p2 = Arbol->buffer_leaves[jj];        
                Ancestor = Arbol->returnCommonFather(p1,p2);

                if( (p1->Level - Ancestor->Level) + (p2->Level - Ancestor->Level) > Maximum)
                {
                    Maximum = (p1->Level - Ancestor->Level) + (p2->Level - Ancestor->Level);
                    p1Max = p1;
                    p2Max = p2;
                }
/*    
                cout<<"Common ancestor of "<<Arbol->buffer_leaves[ii]->Data<<" and "
                    <<Arbol->buffer_leaves[jj]->Data<<" is "<< Ancestor->Data <<", at level "
                    << Ancestor->Level <<endl;
*/    
            }
        }
    }

    if(p1Max->Data < p2Max->Data)
    {
        cout<< p1Max->Data <<" "<< p2Max->Data <<endl;
    }else{
        cout<< p2Max->Data <<" "<< p1Max->Data <<endl;
    }

}
