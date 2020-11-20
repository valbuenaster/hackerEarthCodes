#include <iostream>
#include <vector>
#include <limits>

using namespace std;

void isPolygon(vector<unsigned int> &Lenght)
{
    unsigned int Maximum = 0;
    unsigned int Summation = 0;

    for(auto u: Lenght)
    {
        Summation += u;
        if(Maximum < u) Maximum = u;
    }

    Summation -= Maximum;

    Summation > Maximum ? cout <<"Yes"<<endl : cout <<"No"<<endl;
}

int main()
{
    unsigned int T = 0;
    unsigned int N = 0;


    cin >> T;

    for(unsigned int tt = 0; tt < T;tt++)
    {
        cin >> N;
        vector<unsigned int> L;

        for(unsigned int nn = 0; nn < N;nn++)
        {
            unsigned int Temp;
            cin >> Temp;
            L.push_back(Temp);
        }
        isPolygon(L);    
    }
}
