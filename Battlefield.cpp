#include <iostream>
#include <memory>
#include <limits.h>
#include <algorithm>

#define MAX_SIZE 100000

using namespace std;

constexpr unsigned int Nletters(char *pointer, unsigned int Size, unsigned int pos, unsigned int span,char letter)
{
    unsigned int Value = 0;

    for(unsigned int nn = 0;nn < span;nn++)
    {
        if(pointer[(pos+nn)%Size] == letter) Value++;
    }
    return Value;
}

constexpr unsigned int summation(char * pointer,unsigned int Size)
{
    unsigned int  suma = 0;
    for(unsigned int ss = 0;ss < Size;ss++) suma += pointer[ss];
    return suma;
}

int main()
{
    unsigned int T = 0;
    unsigned int N = 0;
    unsigned int nk = 0;
    char Input[MAX_SIZE];

    cin >> T;

    for(unsigned int tt = 0;tt < T;tt++)
    {
        cin >> N;
        //Input = new char[N];

        unsigned int mR = UINT_MAX;
        unsigned int ValMinimum = UINT_MAX;

        cin >> Input;
        nk = Nletters(Input, N, 0, N, 'K');

        nk = (unsigned int) ( ( summation(Input,N) - 'D'*N )/('K' - 'D')); 

        for(unsigned int ss = 0;ss < N;ss++)
        {
            if(Input[ss]=='D') continue;
            mR = Nletters(Input,N, ss, nk, 'D');
            ValMinimum = min(ValMinimum, mR);
        }
        cout<<ValMinimum<<endl;

        //delete []Input;
    }

}
