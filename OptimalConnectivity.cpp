#include <iostream>
#include <vector>
#include <limits.h>

#define N_SIZE 1001

using namespace std;

struct Nd
{
    unsigned long long int destComp;
    long long int w;

    struct Nd * Pointer = nullptr;
}typedef Node;

int main()
{
    unsigned long long int N = 0;
    unsigned long long int Q = 0;
    unsigned long long int u = 0;
    unsigned long long int v = 0;
    long long int w = 0;
    long long int SumVal = 0;

    cin >> N;

    vector<Node *> Adjacencies(N+1);

    for(unsigned long long int jj=0;jj<N-1;jj++)
    {
        cin >> u >> v >> w;

        Node * Temp1 = new Node;
        Temp1->destComp = v;
        Temp1->w = w;

        Node * Temp2 = new Node;
        Temp2->destComp = u;
        Temp2->w = w;

        if(Adjacencies[u] == nullptr)
        {
            Adjacencies[u] = Temp1;
            //cout <<"u = "<<u<< ", ("<<Adjacencies[u]->destComp <<","<< Adjacencies[u]->w <<")"<<endl;
        }else{
            Node * Temp = Adjacencies[u];
            Temp1->Pointer = Temp;

            Node * p = Temp1;
            
            Adjacencies[u] = Temp1;
        }

        if(Adjacencies[v] == nullptr)
        {
            Adjacencies[v] = Temp2;
            //cout <<"v = "<<v<< ", ("<<Adjacencies[v]->destComp <<","<< Adjacencies[v]->w <<")"<<endl;
        }else{
            Node * Temp = Adjacencies[v];
            Temp2->Pointer = Temp;

            Node * p = Temp2;
            
            Adjacencies[v] = Temp2;
        }
        SumVal += w;
    }

    cout << "SumVal = " << SumVal << endl;

    for(unsigned long long int cc=0;cc<N+1;cc++)
    {
        cout<<"cc = "<<cc<<endl; 
        if(Adjacencies[cc] != nullptr)
        {
            Node * p = Adjacencies[cc];  
            while(p->Pointer!=nullptr)
            {
                cout << "("<< cc <<", "<< p->destComp <<")->"<< p->w <<"\t";
                p = p->Pointer;
            }
            cout << "("<< cc <<", "<< p->destComp <<")->"<< p->w <<endl;
        }
    }

    cout<<endl;

    cin >> Q;
    for(unsigned long long int qq=0;qq<Q;qq++)
    {
        cin >> u >> v >> w;

        long long int opt1 = 0;
        long long int opt2 = 0;
        long long int w_t = 0;

        if(Adjacencies[u] != nullptr)
        {
            Node * p = Adjacencies[u];  
            while(p->Pointer!=nullptr)
            {
                if(w < p->w)
                {
                    cout << "u("<< u <<", "<< p->destComp <<")->"<< p->w <<endl;
                    w_t = p->w;
                    break;
                }
                p = p->Pointer;
            }
            
            if(w < p->w)
            {
                cout << "uu("<< u <<", "<< p->destComp <<")->"<< p->w <<endl;
                w_t = p->w;
            }

            cout<<"SumVal "<<SumVal <<endl;
            cout<<"w_t "<<w_t <<endl;
            cout<<"w "<<w <<endl;
            opt1 = SumVal - w_t + w;
        }

        w_t = 0;
        if(Adjacencies[v] != nullptr)
        {
            Node * p = Adjacencies[v];  
            while(p->Pointer!=nullptr)
            {
                if(w < p->w)
                {
                    cout << "v("<< v <<", "<< p->destComp <<")->"<< p->w <<endl;
                    w_t = p->w;
                    break;
                }
                p = p->Pointer;
            }
            
            if(w < p->w)
            {
                cout << "vv("<< v <<", "<< p->destComp <<")->"<< p->w <<endl;
                w_t = p->w;
            }
            cout<<"SumVal "<<SumVal <<endl;
            cout<<"w_t "<<w_t <<endl;
            cout<<"w "<<w <<endl;
            opt2 = SumVal - w_t + w;
        }

        cout<<"opt1 = "<<opt1 <<" , opt2 = "<<opt2 <<endl;

        if(SumVal > min(opt1,opt2))
        {
            cout<<"YES"<<endl;
        }else{
            cout<<"NO"<<endl;
        }
    }
}
