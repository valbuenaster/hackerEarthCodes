#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;

struct Nd
{
    unsigned long long int No;
    unsigned long long int Level =0;//use it on the breadth search
    unsigned long long int Parent;
    bool marked = false;
    bool markedG = false;

    unsigned long long int CountVisits = 0;

    vector<unsigned long long int> Connections;
}typedef Node;

class Graph
{
    public:
        vector<Node> Nodes;
        unsigned long long int N_Nodes;        

        Graph(unsigned long long int N);
        void addEdge(unsigned long long int No, unsigned long long int Nf);
        void breadthSearch();
        bool findManyRoads(Node * pointer,unsigned long long int &N); 

        ~Graph();
};

Graph::Graph(unsigned long long int N)
{
    vector<Node> temp(N+1);
    this->N_Nodes = N; 
    this->Nodes = temp;
    this->Nodes[0].marked = true;
    this->Nodes[0].markedG = true;
}

void Graph::addEdge(unsigned long long int No, unsigned long long int Nf)
{
    this->Nodes[No].No = No;
    this->Nodes[No].Connections.push_back(Nf);
    this->Nodes[Nf].No = Nf;
    this->Nodes[Nf].Parent = No;
}

void Graph::breadthSearch()
{
    list<unsigned long long int> bufferC;
    unsigned long long int maximumDepth = 0;  

    for(auto &Elem: this->Nodes)
    {
        if(Elem.marked) continue;
        cout<<endl<<endl;

        Elem.Level = 0;
        Elem.marked = true;
        Elem.markedG = true;
        bufferC.push_back(Elem.No);

        unsigned long long int lLevel = 0;      

        while(bufferC.size()>0)
        {
            if(lLevel < this->Nodes[bufferC.front()].Level) cout<<endl;
            lLevel = this->Nodes[bufferC.front()].Level;

            cout << this->Nodes[bufferC.front()].No << "("<<this->Nodes[bufferC.front()].Parent<<", "<<this->Nodes[bufferC.front()].Level<<") ";


            for(auto cc: this->Nodes[bufferC.front()].Connections)
            {
                if(!this->Nodes[cc].marked)
                {
                     if(!this->Nodes[cc].markedG)
                    {                                       
                        this->Nodes[cc].markedG = true;
                        bufferC.push_back(cc);
                        this->Nodes[cc].Level = this->Nodes[bufferC.front()].Level + 1;

                        maximumDepth = max(maximumDepth,this->Nodes[cc].Level);
                    }
                }
            }

            this->Nodes[bufferC.front()].marked = true;
            bufferC.pop_front();

        }

    }
}

bool Graph::findManyRoads(Node * pointer,unsigned long long int &N)
{
    unsigned long long int retVal = false;

    //cout<<"Visited Node "<<pointer->No<<endl;
    //cout<<"N Connections "<<pointer->Connections.size()<<endl;

    if(pointer->No==N)
    {
        pointer->CountVisits += 1;
        retVal = true;       
    }else{
        if(pointer->Connections.size()==0)
        {
            retVal = false;
        }else{
            for(auto elem:pointer->Connections)
            {
                retVal |= findManyRoads(&this->Nodes[elem],N);
            }
        }
    }

    return retVal;
}

Graph::~Graph()
{
}


int main()
{
    unsigned long long int N = 0;

    unsigned long long int x = 0;
    unsigned long long int y = 0;
    
    cin >> N;
    Graph Grafo(N);

    while(true)
    {
        cin >> x >> y;
        if((x==0)&&(y==0)) break;
        Grafo.addEdge(x,y);
    }

    cout<<"Grafo.Nodes.size() = "<<Grafo.Nodes.size()<<endl;
    for(auto Elem:Grafo.Nodes)
    {
        //if(Elem.Connections.size()==0) continue;
        cout <<"Node = "<< Elem.No<<". Conn "<<endl;
        for(auto cc:Elem.Connections) cout<<cc<<" ";
        cout<<endl;
    }

    cout<<endl<<"Breadth search";

    Grafo.breadthSearch();
    cout<<endl;
/*
    cout<<endl<<"Counting roads...";
*/
    Grafo.findManyRoads(&Grafo.Nodes[1],Grafo.N_Nodes);

    cout<<"Count = "<< Grafo.Nodes[Grafo.N_Nodes].CountVisits <<endl;

}
