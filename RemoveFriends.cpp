#include <iostream>

using namespace std;

struct Node
{
    unsigned int Popularity;
    struct Node *Next = nullptr;
};

Node * addNode(Node * head, unsigned int pop)
{
    Node *temp = new Node;
    temp->Popularity = pop;
    temp->Next = head;

    return temp;
}

void printList(Node * Pointer)
{
    while(Pointer->Next!=nullptr)
    {
        cout << Pointer->Popularity<<" ";
        Pointer = Pointer->Next;    
    }
    cout << Pointer->Popularity<<endl;
}

Node * reverse(Node * Pointer)
{
    Node * pointerStore = nullptr;
    Node * pointerNext = nullptr;

    while(Pointer->Next!=nullptr)
    {
        pointerNext = Pointer->Next;
        Pointer->Next = pointerStore;
        pointerStore = Pointer;
        Pointer = pointerNext;
    }
    Pointer->Next= pointerStore;

    return Pointer;
}

Node * removeFriend(Node * Pointer, unsigned int &k)
{
    Node * prevNode = nullptr;
    Node * retHead = Pointer;

    while(Pointer->Next!=nullptr)
    {
    
        if(Pointer->Popularity < Pointer->Next->Popularity)
        {
            if(prevNode ==nullptr)
            {
                //cout<<"Se rompe aqui"<<endl;
                retHead = Pointer->Next;

            }else{
                prevNode->Next = Pointer->Next;
            }
            k-=1;
            if(k==0) break;
        }else{
            prevNode = Pointer;
        }
        Pointer = Pointer->Next;
    }
//    cout<<"prevNode= "<<prevNode->Popularity<<" ";
//    cout<<", Node= "<<Pointer->Popularity<<endl;

    return retHead;
}


int main()
{
    unsigned int T = 0;
    unsigned int N = 0;
    unsigned int K = 0;
    unsigned int popularity = 0;

    cin >> T;
    for(unsigned int tt = 0;tt<T;tt++)
    {
        cin >> N >> K;
        Node *Head = new Node;

        for(unsigned int nn = 0;nn<N;nn++)
        {
            cin >> popularity;
            if(nn==0)
            {
                Head->Popularity = popularity;
            }else{
                Head = addNode(Head,popularity);
            }
            cout << "Aqui, nn = " << nn << ", popularity = " << popularity <<", N = "<< N << endl;
        }    
        
        //cout<<"printing back..."<<endl;
        //printList(Pointer);

        Head = reverse(Head);
        Node* Pointer = Head;
        //cout<<"printing reversed"<<endl;
        //printList(Pointer);

        Node* PointerNew = Pointer;
        while(K>0)
        {
            PointerNew = removeFriend(PointerNew,K);
            cout<<"New K = "<<K<<endl;
            //cout<<"printing new"<<endl;
            //printList(PointerNew);
            //cout<<endl;
        }
        printList(PointerNew);
        delete Head;
    }

}
