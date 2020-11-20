#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;

struct Nd
{
    unsigned long long int No;
    unsigned long long int Level;//use it on the breadth search
    bool marked = false;
    bool markedG = false;

    unsigned long long int f;

    //struct Nd* pointer = nullptr;
    vector<unsigned long long int> Connections;
}typedef Node;

class Graph
{
    public:
        vector<Node> Nodes;

        Graph(unsigned long long int N);
        void addEdge(unsigned long long int No, unsigned long long int Nf);
        void breadthSearch(unsigned long long int F);

        ~Graph();
};

Graph::Graph(unsigned long long int N)
{
    vector<Node> temp(N+1);
    this->Nodes = temp;
    this->Nodes[0].marked = true;
    this->Nodes[0].markedG = true;
}

void Graph::addEdge(unsigned long long int No, unsigned long long int Nf)
{
    this->Nodes[No].No = No;
    this->Nodes[No].Connections.push_back(Nf);

    this->Nodes[Nf].No = Nf;
    this->Nodes[Nf].Connections.push_back(No);
}

void Graph::breadthSearch(unsigned long long int F)
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
/*
        cout <<"Elem.No "<<Elem.No <<endl;
        cout <<"Elem.marked "<<Elem.marked <<endl;
        cout <<"this->Nodes[Elem.No].marked "<<this->Nodes[Elem.No].marked <<endl;
*/
        unsigned long long int lLevel = 0;      

        while(bufferC.size()>0)
        {
            if(lLevel < this->Nodes[bufferC.front()].Level) cout<<endl;
            lLevel = this->Nodes[bufferC.front()].Level;

            cout << this->Nodes[bufferC.front()].No << "("<<this->Nodes[bufferC.front()].Level<<") ";


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
    cout<<endl;
    if(F==1)
    {
        cout<<"operation = "<<maximumDepth+1<<endl;
    }else
    {
        cout<<endl<<"operation = "<<maximumDepth/F<<endl;
    }
    //cout<<endl<<"maximumDepth = "<<maximumDepth<<endl;
    //cout<<endl<<"operation = "<<maximumDepth/F)<<endl;
}

Graph::~Graph()
{
}
int main()
{
    unsigned long long int N = 0;
    unsigned long long int M = 0;
    unsigned long long int F = 0;

    unsigned long long int x = 0;
    unsigned long long int y = 0;
    
    cin >> N >> M >>F;
    Graph Grafo(N);

    for(unsigned long long int mm = 0; mm < M; mm++)
    {
        cin >> x >> y;
        Grafo.addEdge(x,y);
    }

/*
    cout<<"Grafo.Nodes.size() = "<<Grafo.Nodes.size()<<endl;
    for(auto Elem:Grafo.Nodes)
    {
        if(Elem.Connections.size()==0) continue;
        cout <<"Node = "<< Elem.No<<". Conn "<<endl;
        for(auto cc:Elem.Connections) cout<<cc<<" ";
        cout<<endl;
    }
*/
    cout<<endl<<"Breadth search";

    Grafo.breadthSearch(F);
    cout<<endl;
}
