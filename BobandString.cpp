#include <iostream>
#include <math.h>

#define N_SIZE 26
#define N_BUFFER 100000

constexpr unsigned int hashFunction(char l)
{
    return (l-'a');
}

using namespace std;

int main()
{
    unsigned int T = 0;
    int Letters[N_SIZE];
    unsigned int changes = 0;
    char Buffer[N_BUFFER];

    cin >> T;

    for(unsigned int tt=0;tt<T;tt++)
    {
        cin >> Buffer;

        unsigned int N = 0;
        while(Buffer[N]>='a'&&Buffer[N]<='z') N++;
        
        unsigned int n=0;
        while(n<N)
        {
            Letters[hashFunction(Buffer[n])]++;
            n++;
        }

        cin >> Buffer;
        N = 0;
        while(Buffer[N]>='a'&&Buffer[N]<='z') N++;
        
        n=0;
        while(n<N)
        {
            Letters[hashFunction(Buffer[n])]--;
            n++;
        }

        int temp = 0;
        for(unsigned int ii=0;ii<N_SIZE;ii++)
        {
            temp = Letters[ii];
            changes += abs(temp);
        }

        cout<<changes<<endl;

        for(unsigned int ii=0;ii<N_SIZE;ii++)Letters[ii]=0;
        changes = 0;
    }



}
