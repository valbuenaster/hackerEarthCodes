#include <iostream>
#include <memory>
#include <limits.h>
#include <algorithm>

#define MAX_SIZE 10000

using namespace std;

char Input[MAX_SIZE];
unsigned int IndicesK[MAX_SIZE];

constexpr unsigned int Nletters(char *pointer, unsigned int Size, unsigned int pos, unsigned int span,char letter)
{
    unsigned int Value = 0;

    for(unsigned int nn = 0;nn < span;nn++)
    {
        if(pointer[(pos+nn)%Size] == letter) Value++;
    }
    return Value;
}

constexpr unsigned int findingIndices(char * pointer,unsigned int Size,char letter)
{
    unsigned int Value = 0;

    for(unsigned int nn = 0;nn < Size;nn++)
    {
        if(pointer[nn] == letter)
        {
            IndicesK[Value] = nn;
            Value++;
        }
    }
    return Value;
}

int main()
{
    unsigned int T = 0;
    unsigned int N = 0;
    unsigned int nk = 0;
    

    cin >> T;

    for(unsigned int tt = 0;tt < T;tt++)
    {
        cin >> N;
        //Input = new char[N];

        unsigned int mR = UINT_MAX;
        unsigned int ValMinimum = UINT_MAX;

        cin >> Input;
        //nk = Nletters(Input, N, 0, N, 'K');

        nk = findingIndices(Input,N, 'K'); 

        for(unsigned int ss = 0;ss < nk;ss++)
        {
            mR = Nletters(Input,N, IndicesK[ss], nk, 'D');
            ValMinimum = min(ValMinimum, mR);
        }
        cout<<ValMinimum<<endl;

        //delete []Input;
    }

}
