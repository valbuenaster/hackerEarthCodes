#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int N = 0;
    long int n = 0;
    long int li = 0;
    long long int summation = 0;
    long int max_Side = 0;

    cin >> N;

    for(int ii = 0;ii<N;ii++)
    {
        vector<long int> sides;
        summation = 0;
        max_Side = 0;

        cin >> n;
        for(long int jj = 0;jj<n;jj++)
        {
            cin >> li;
            if(max_Side < li) max_Side = li;
            summation += li;
        }

        ((summation - max_Side) > max_Side)? cout <<"Yes"<<endl: cout<<"No"<<endl;
    }
}
