#include <iostream>
#include <vector>
using namespace std;

struct Nd
{
    long long int ID;
    unsigned long long int RC;
    long long int Age;
    unsigned long long int Level;
    unsigned long long int aawras;

    struct Nd* Parent = nullptr;
    vector<struct Nd*> Children;
}typedef Node;

class Tree
{
    public:
        unsigned long long int Witness;
        vector<Node*>bufferLevel;
        Node * Root;

        Tree(long long int IDi,unsigned long long int RCi);
        void addNode(long long int IDi,unsigned long long int RCi);

        ~Tree();
};

Tree::Tree(long long int IDi,unsigned long long int RCi)
{
    this->Root = new Node;

    this->Root->ID = IDi;
    this->Root->RC = RCi;
    this->Root->Age = 0;
    this->Root->Level = 0;
    this->Root->aawras = -1;

    this->Witness = 0;

    this->bufferLevel.push_back(this->Root);
}

Tree::~Tree()
{
    delete this->Root;
}

void Tree::addNode(long long int IDi,unsigned long long int RCi)
{
    Node * Temp = new Node;
    Temp->ID = IDi;
    Temp->RC = RCi;
    Temp->Age = 0;

    while( (this->bufferLevel[this->Witness]->RC) <= 
        (this->bufferLevel[this->Witness]->Children.size()) )
    {
        this->Witness++;
    } 

    Temp->Level = this->bufferLevel[this->Witness]->Level + 1;
    Temp->Parent = this->bufferLevel[this->Witness];

    for(auto &Elem:this->bufferLevel) Elem->Age +=1;

    Temp->aawras = this->bufferLevel[this->Witness]->Children.size()+1;

    this->bufferLevel[this->Witness]->Children.push_back(Temp);
    this->bufferLevel.push_back(Temp);
}

int main()
{
    unsigned long long int N = 0;
    long long int IDi = 0;
    unsigned long long int RCi = 0;

    cin >> N >> RCi;

    Tree Arbol = Tree(0,RCi);

    for(unsigned long long int nn = 0;nn<N;nn++)
    {
        cin >> IDi >> RCi;
        Arbol.addNode(IDi,RCi);
    }

    for(auto Elem:Arbol.bufferLevel)
    {
        if(Elem->ID==0) continue;
        cout << Elem->Parent->ID<<" "<<Elem->Level<<" "<<Elem->aawras<<endl;
    }


}
