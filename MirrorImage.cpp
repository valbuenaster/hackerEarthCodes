#include <iostream>
#include <list>

using namespace std;


struct Node
{
    unsigned int Data;
    struct Node * Right;
    struct Node * Left;
}typedef node;

node * createNewNode(unsigned int D)
{
    node *temp = new node;
    temp->Data= D;
    return temp;
}

node * findParent(node *ptr,unsigned int *D)
{
    node * ret_ptr;
    node * ret_ptrR;
    node * ret_ptrL;
    if(ptr==NULL)
    {
        ret_ptr = NULL;
    }else
    {
        if(ptr->Data == *D)
        {
            ret_ptr = ptr;
        }else{
            ret_ptrR = findParent(ptr->Right,D);   
            ret_ptrL = findParent(ptr->Left,D); 

            if(ret_ptrR != NULL)
            {
                //cout<<"Right"<<endl;
                //Path.push_front('R');
                ret_ptr = ret_ptrR;
            }
            if(ret_ptrL != NULL)
            {
                //cout<<"Left"<<endl;
                //Path.push_front('L');
                ret_ptr = ret_ptrL;
            }
            if((ret_ptrR == NULL)&&(ret_ptrL == NULL))
            {
                ret_ptr = NULL;
            }

        }
    }
    return ret_ptr;
}


node * findPath(node *ptr,unsigned int *D, list<char> &Path)
{
    node * ret_ptr;
    node * ret_ptrR;
    node * ret_ptrL;
    if(ptr==NULL)
    {
        ret_ptr = NULL;
    }else
    {
        if(ptr->Data == *D)
        {
            ret_ptr = ptr;
        }else{
            ret_ptrR = findPath(ptr->Right,D,Path);   
            ret_ptrL = findPath(ptr->Left,D,Path); 

            if(ret_ptrR != NULL)
            {
                //cout<<"Right"<<endl;
                Path.push_front('R');
                ret_ptr = ret_ptrR;
            }
            if(ret_ptrL != NULL)
            {
                //cout<<"Left"<<endl;
                Path.push_front('L');
                ret_ptr = ret_ptrL;
            }
            if((ret_ptrR == NULL)&&(ret_ptrL == NULL))
            {
                ret_ptr = NULL;
            }

        }
    }
    return ret_ptr;
}

int returnMirror(node * ptr,list<char> &Path)
{
    int ret = 0;
    for (list<char>::iterator it=Path.begin(); it != Path.end(); ++it)
    {
        if( *it == 'L')
        {
            if(ptr->Right !=NULL)
            {
                ptr = ptr->Right;
            }else
            {
                ret = -1;
                break;
            }
        }
        if( *it == 'R')
        {
            if(ptr->Left !=NULL)
            {
                ptr = ptr->Left;
            }else
            {
                ret = -1;
                break;
            }
        }

    }

    if(ret == 0) ret = ptr->Data;

    return ret;
}

int main()
{
    unsigned int N=0;
    unsigned int Q=0;

    unsigned int P = 0;
    unsigned int C = 0;
    char D = ' ';

    unsigned int mq = 0;

    list<char> defPath;

    cin >> N >> Q;

    node *Tree = createNewNode(1);
    node *tempNode;

    for(unsigned int n = 0;n<N-1;n++)
    {
        cin >> P >> C >> D;

        tempNode = findParent(Tree,&P);
        defPath.clear();
        if(tempNode!=NULL)
        {
            if(D=='R') tempNode->Right = createNewNode(C);
            if(D=='L') tempNode->Left = createNewNode(C);
        }

    }

    for(unsigned int q = 0;q<Q;q++)
    {
        cin >> mq;
        defPath.clear();
        node *AA =  findPath(Tree,&mq,defPath);

        cout<< returnMirror(Tree,defPath) <<endl;
    }
/*
    cout<<"Root "<< Tree->Data<<endl;
    cout<<"Left "<< Tree->Left->Data <<endl;
    cout<<"Right "<< Tree->Right->Data <<endl<<endl;

    unsigned int bac = 8;
    defPath.clear();
    node *AA =  findPath(Tree,&bac,defPath);

    for (list<char>::iterator it = defPath.begin() ; it != defPath.end(); ++it) cout << *it<<" ";
    cout << endl;
*/
    delete Tree;
}
