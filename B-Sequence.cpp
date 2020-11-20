#include <iostream>

using namespace std;


struct Node
{
    unsigned int Data = 0;
    struct Node * Left = NULL;
    struct Node * Right = NULL;
    struct Node * Parent = NULL;
}typedef Leaf;

class Tree
{
    public:
    static unsigned int n_items;
    Leaf *Root;
    Leaf *ptrLeftMost;

    Tree();
    void insert(unsigned int *data);
    bool insertLeft(Leaf * ptr, unsigned int *data);
    bool insertRight(Leaf * ptr, unsigned int *data);
    void printTree();
    ~Tree();
};

unsigned int Tree::n_items = 0;

Tree::Tree()
{
    Root = new Leaf;
    this->ptrLeftMost = Root;
}

Tree::~Tree()
{
    delete Root;
}

bool Tree::insertLeft(Leaf * ptr, unsigned int *data)
{
    //cout <<"LEFT"<<endl;
    bool returnValue = false;
    Leaf *Localptr = ptr;

    if(Localptr->Left==NULL)
    {
        //cout <<"Entra a if(Localptr->Left==NULL)"<<endl;
        Leaf *node = new Leaf;
        node->Data = *data;
        node->Parent = Localptr;
        //if(node->Parent == NULL) cout <<"node->Parent is NULL"<<endl;
        Localptr->Left = node;
        returnValue = true;
    }else{
        while( ((Localptr->Data)>*data) && (Localptr->Left!=NULL) )
        {
            //cout <<"while"<<endl;
            Localptr = Localptr->Left;
        }

        if( Localptr->Left==NULL )
        {
            //cout <<"Entra a if( Localptr->Left==NULL )"<<endl;
            if((Localptr->Data) > *data)
            {
                //cout <<"Entra a if((Localptr->Data) > *data)"<<endl;
                Leaf *node = new Leaf;
                node->Data = *data;
                node->Parent = Localptr;
                //if(node->Parent == NULL) cout <<"node->Parent is NULL"<<endl;
                Localptr->Left = node;
                this->ptrLeftMost = node;
                returnValue = true;
            }
//
            //cout <<"Entra al else de if( Localptr->Left==NULL )"<<endl;
            //cout <<"Antes"<<endl;
            Leaf *n_parent = Localptr->Parent;
            //if(Localptr->Parent==NULL)cout<<"Localptr->Parent is NULL!!!"<<endl;
            //cout <<"Despues"<<endl;

            if( ( (Localptr->Data)<*data )&&( (n_parent->Data)>*data ) )
            {
                //cout <<"Entra a if(((Localptr->Data)<*data)&&((n_parent->Data)>*data))"<<endl;
                Leaf *node = new Leaf;
                node->Data = *data;
                node->Left = Localptr;
                Localptr->Parent = node;
                node->Parent = n_parent;
                n_parent->Left = node;
                //this->ptrLeftMost = node;
                returnValue = true;
            }
//
        }else{
            //cout <<"Entra al else de if( Localptr->Left==NULL )"<<endl;
            //cout <<"Antes"<<endl;
            Leaf *n_parent = Localptr->Parent;
            //if(Localptr->Parent==NULL)cout<<"Localptr->Parent is NULL!!!"<<endl;
            //cout <<"Despues"<<endl;

            if( ( (Localptr->Data)<*data )&&( (n_parent->Data)>*data ) )
            {
                //cout <<"Entra a if(((Localptr->Data)<*data)&&((n_parent->Data)>*data))"<<endl;
                Leaf *node = new Leaf;
                node->Data = *data;
                node->Left = Localptr;
                Localptr->Parent = node;
                node->Parent = n_parent;
                n_parent->Left = node;
                returnValue = true;
            }
        }
    }
    return returnValue;
}

bool Tree::insertRight(Leaf * ptr, unsigned int *data)
{
    //cout <<"RIGHT"<<endl;
    bool returnValue = false;
    Leaf *Localptr = ptr;

    if(Localptr->Right==NULL)
    {
        //cout <<"Entra a if(Localptr->Right==NULL)"<<endl;
        Leaf *node = new Leaf;
        node->Data = *data;
        node->Parent = Localptr;
        //if(node->Parent == NULL) cout <<"node->Parent is NULL"<<endl;
        Localptr->Right = node;
        returnValue = true;
    }else{
        while( ((Localptr->Data)>*data) && (Localptr->Right!=NULL) )
        {
            //cout <<"while"<<endl;
            Localptr = Localptr->Right;
        }

        if( Localptr->Right==NULL )
        {
            //cout <<"Entra a if( Localptr->Right==NULL )"<<endl;
            if((Localptr->Data) > *data)
            {
                //cout <<"Entra a if((Localptr->Data) > *data)"<<endl;
                Leaf *node = new Leaf;
                node->Data = *data;
                node->Parent = Localptr;
                //if(node->Parent == NULL) cout <<"node->Parent is NULL"<<endl;
                Localptr->Right = node;
                returnValue = true;
            }
//
            Leaf *n_parent = Localptr->Parent;

//cout <<"Importante if((("<<Localptr->Data<<")<"<<*data<<")&&(("<<n_parent->Data<<")>"<<*data<<"))"<<endl;

            if( ( (Localptr->Data)<*data )&&( (n_parent->Data)>*data ) )
            {
                //cout <<"AA Entra a if(((Localptr->Data)<*data)&&((n_parent->Data)>*data))"<<endl;
                Leaf *node = new Leaf;
                node->Data = *data;
                node->Right = Localptr;
                Localptr->Parent = node;
                node->Parent = n_parent;
                n_parent->Right = node;
                returnValue = true;
            }
//
        }else{
            //cout <<"Entra al else de if( Localptr->Right==NULL )"<<endl;
            //cout <<"Antes"<<endl;
            Leaf *n_parent = Localptr->Parent;
            //if(Localptr->Parent==NULL)cout<<"Localptr->Parent is NULL!!!"<<endl;
            //cout <<"Despues"<<endl;

            if( ( (Localptr->Data)<*data )&&( (n_parent->Data)>*data ) )
            {
                //cout <<"Entra a if(((Localptr->Data)<*data)&&((n_parent->Data)>*data))"<<endl;
                Leaf *node = new Leaf;
                node->Data = *data;
                node->Right = Localptr;
                Localptr->Parent = node;
                node->Parent = n_parent;
                n_parent->Right = node;
                returnValue = true;
            }
        }
    }
    return returnValue;
}


void Tree::insert(unsigned int *data)
{
    //cout <<endl<<"data to insert "<<*data<<endl;
    if(Root->Data==0)//Empty tree
    {
        //cout <<"Entra a if(Root->Data==0)"<<endl;
        Root->Data = *data;
        n_items++;
    }else{

        if((Root->Data)!= *data)
        {
            if((Root->Data)< *data)
            {
                //cout <<"Entra a if((Root->Data)< *data)"<<endl;
                Leaf *node = new Leaf;
                node->Data = *data;

                Leaf *tempnode = Root;
                node->Left = tempnode;

                Leaf *auxptr = Root->Right;
                node->Right = auxptr;
                if(auxptr!=NULL) auxptr->Parent = node;

                tempnode->Right = NULL;
                tempnode->Parent = node;

                Root = node;
                n_items++;
            }else{
                Leaf *ptr = Root;

                if(insertLeft(ptr,data))
                {
                    //cout <<"Entra a insertLeft(ptr,data)"<<endl;
                    n_items++;              
                }else{
                    Leaf *ptr = Root;
                    if(insertRight(ptr,data))
                    {
                        //cout <<"Entra a insertRight(ptr,data)"<<endl;
                        n_items++; 
                    }
                }
            }
        } 
    }
}
/*
void Tree::printTree()
{
    Leaf *node = this->Root;

    while(node->Left!=NULL)
    {
        //cout << node->Data<<"' ";
        node = node->Left;
    }
    //cout << node->Data<<"' "<<endl;
    while(node->Parent!=NULL)
    {
        cout << node->Data<<" ";
        node = node->Parent;
    }
    cout << node->Data<<" ";
    node = node->Right;
    while(node->Right!=NULL)
    {
        cout << node->Data<<" ";
        node = node->Right;
    }
    cout << node->Data<<endl;
}
*/

void Tree::printTree()
{
    Leaf *node = this->ptrLeftMost;
    while(node->Parent!=NULL)
    {
        cout << node->Data<<" ";
        node = node->Parent;
    }
    cout << node->Data<<" ";
    node = node->Right;
    while(node->Right!=NULL)
    {
        cout << node->Data<<" ";
        node = node->Right;
    }
    cout << node->Data<<endl;
}
int main()
{
    unsigned int N = 0;
    unsigned int Si= 0;
    unsigned int Q = 0;
    unsigned int val = 0;

    Tree Bseq;

    cin >> N;

    for(unsigned int nn=0;nn<N;nn++)
    {
        cin >> Si;
        //Insert the data into the tree
        Bseq.insert(&Si);
    }

    cin >> Q;

    for(unsigned int qq=0;qq<Q;qq++)
    {
        cin >> val;
        //inser 'val' if possible
        //Print size of sequence
        Bseq.insert(&val);
        cout<<Bseq.n_items<<endl;
        //Bseq.printTree();
    }

    //print sequence
    //cout<<"Printing sequence...size.."<<Bseq.n_items<<endl;
    Bseq.printTree();
}
