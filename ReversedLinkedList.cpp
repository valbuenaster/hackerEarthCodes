#include <iostream>
#include <vector>

using namespace std;

struct Node 
{
    unsigned int data;
    struct Node *next;
}typedef Link;

Link* createNewLink(unsigned int Data,Link* prev_pointer)
{
    Link * pointer = new Link;
    pointer->data = Data;
    pointer->next = prev_pointer;

    return pointer;
}

Link * reverseList(Link * Head)
{
    Link *Now = Head;
    Link *p1 = NULL;
    Link *p2 = NULL;

    while(Now->next!=NULL)
    {
        p1 = Now->next;
        Now->next = p2;
        p2 = Now;
        
        Now = p1;
    }
    Now->next = p2;

    return Now;
}

Link * reverseEvenSegment(Link * Head)
{
    Link * pointer = Head;
    Link * prev_p = NULL;
    vector<Link *> Cadena;
    vector<bool> reverse;
    unsigned int counter = 0;
    unsigned int s_now = 0;
    unsigned int s_bef = 0;

    Link * reversed = NULL;

    while(pointer->next!=NULL)
    {
        if(counter==0)
        {
            Cadena.push_back(createNewLink(pointer->data,NULL));
            s_now = (pointer->data)%2;
            reverse.push_back(s_now==1);
        }else{
            s_now = (pointer->data)%2; 
            if(s_bef == s_now)
            {
                Cadena.back() = createNewLink(pointer->data,Cadena.back());
            }else         
            {
                Cadena.push_back(createNewLink(pointer->data,NULL));
                reverse.push_back(s_now==1);
            }
        }
        s_bef = s_now;

        pointer = pointer->next;
        counter++;
    }
    s_now = (pointer->data)%2; 
    if(s_bef == s_now)
    {
        Cadena.back() = createNewLink(pointer->data,Cadena.back());
    }else         
    {
        Cadena.push_back(createNewLink(pointer->data,NULL));
        reverse.push_back(s_now==1);
    }

    //cout << "Size Cadena "<<Cadena.size()<<endl;

    for(unsigned int ii=0;ii<Cadena.size();ii++)
    {
        Link *ptr = Cadena[ii];

        if(reverse[ii]) ptr = reverseList(ptr);

        //cout << reverse[ii]<<" ";
        while(ptr->next!=NULL)
        {
            //cout << ptr->data<<" ";
            reversed = createNewLink(ptr->data,reversed);

            ptr = ptr->next;
        }
        //cout << ptr->data<<endl;
        reversed = createNewLink(ptr->data,reversed);
    }
/*
    cout << "Reversed"<<endl;
    Link *ptr2 = reversed;
    while(ptr2->next!=NULL)
    {
        cout << ptr2->data<<" ";
        ptr2 = ptr2->next;
    }
    cout << ptr2->data<<endl;
*/
    return reversed;
}

int main()
{
    unsigned int N;
    unsigned int Ai;

    Link * Head;
    Link * previousLink = NULL;

    cin >> N;

    for(unsigned int nn = 0; nn < N; nn++)
    {
        cin >> Ai;

        previousLink = createNewLink(Ai,previousLink);
        Head = previousLink;
    }

    //Head = reverseList(Head);
/*
    cout <<"Printing..."<<endl;
    Link *Trav = Head;
    while(Trav->next!=NULL)
    {
        cout << Trav->data<<" ";

        Trav = Trav->next;
    }
    cout << Trav->data<<endl;
*/
    Head = reverseEvenSegment(Head);

    //cout <<"returned reversed..."<<endl;
    Link *Trav = Head;
    while(Trav->next!=NULL)
    {
        cout << Trav->data<<" ";

        Trav = Trav->next;
    }
    cout << Trav->data<<endl;

    delete Head;
}
