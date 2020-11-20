#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct NdG{
	long long int px=0;
	long long int py=0;

	//Vector pointing to start point;
	double vx = 0.0;
	double vy = 0.0;

	bool visited = false;

	bool flagA = false;
	bool flagB = false;
	bool flagC = false;

	double cummulativeDistance = 0.0;

	long long int Level = 0;
	struct NdG * Parent = nullptr;
	std::vector<struct NdG *>Connections;
}typedef NodeG;

int main ()
{

    vector<NodeG*> ConnectionsA(9,nullptr);
    vector<NodeG*> ConnectionsB(9,nullptr);

    ConnectionsB[6] = ConnectionsA[1];
    ConnectionsB[7] = ConnectionsA[3];
    ConnectionsB[8] = ConnectionsA[5];

    NodeG* N1 = new NodeG;
    NodeG* N3 = new NodeG;
    NodeG* N5 = new NodeG;

    N1->px = 1;
    N3->px = 3;
    N5->px = 5;

    ConnectionsA[1] = N1;
    ConnectionsA[3] = N3;
    ConnectionsA[5] = N5;

    cout<<"ConnectionsA"<<endl;

    for(auto el:ConnectionsA) 
    {
        el==nullptr? cout<<"null ": cout<<el->px<<" ";
    }
    cout<<endl;

    cout<<"ConnectionsB"<<endl;

    for(auto el:ConnectionsB) 
    {
        el==nullptr? cout<<"null ": cout<<el->px<<" ";
    }
    cout<<endl;

}
