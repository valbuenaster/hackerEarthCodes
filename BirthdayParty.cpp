#include <iostream>

using namespace std;

int main()
{
    int T;
    long int N = 0;
    long int M = 0;

    cin >> T;

    for(int tt = 0; tt < T; tt++)
    {
        cin >> N >> M;

        if( (M%N)==0)
        {
            cout <<"Yes"<<endl;
        }else{
            cout <<"No"<<endl;
        }
    }
}
