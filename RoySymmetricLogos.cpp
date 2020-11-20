#include <iostream>
#include <string>

#define NSIZE 32

int Matrix[NSIZE][NSIZE];

using namespace std;

bool Sym(unsigned int N,bool direction)
{
    bool ret = true;

    int N_iter = N/2;

    for(unsigned int yy = 0; yy < N; yy++)
    {
        for(unsigned int xx = 0;xx<N_iter;xx++)
        {
            if(direction==false)
            {
                if(Matrix[yy][xx]!=Matrix[yy][N-1-xx])
                {
                    ret = false;
                    break;
                }
            }else{
                if(Matrix[xx][yy]!=Matrix[N-1-xx][yy])
                {
                    ret = false;
                    break;
                }
            }
        }
    }

    return ret;
}

int main()
{
    unsigned int T = 0;
    unsigned int N = 0;
    string str;
    cin >> T;

    for(unsigned int tt = 0; tt < T; tt++)
    {
        cin >> N;
        for(unsigned int ss = 0;ss < N; ss++)
        {
            cin >> str;
            for(unsigned int rr = 0; rr < N; rr++)  Matrix[ss][rr] = (str[rr]-48);

        }

        if(Sym(N,true)&&Sym(N,false))
        {
            cout<<"YES"<<endl;
        }else{
            cout<<"NO"<<endl;
        }
/*
        cout <<"PRINTING BACK..."<<endl;

        for(unsigned int ss = 0;ss < N; ss++)
        {
            for(unsigned int rr = 0; rr < N; rr++)  cout << Matrix[ss][rr] <<" ";
            cout <<endl;
        }
*/
    }

}
