#include <iostream>
#include <vector>
#include <limits>

using namespace std;

void isPolygon(vector<unsigned int> &Lenght)
{
    unsigned int Maximum = 0;
    unsigned int Summation = 0;

    for(vector<unsigned int>::iterator it=Lenght.begin();it!=Lenght.end();++it)
    {
        Summation += *it;
        if(Maximum < *it) Maximum = *it;
    }
    //cout <<"Summation "<<Summation <<", Maximum "<<Maximum <<endl;
    Summation -= Maximum;

    if(Summation > Maximum)
    {
        cout <<"Yes"<<endl;
    }else{
        cout <<"No"<<endl;
    }
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
