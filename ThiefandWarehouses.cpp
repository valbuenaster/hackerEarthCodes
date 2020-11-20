#include <iostream>
#include <limits>
#include <vector>

#define N_SIZE 1000000

using namespace std;

unsigned long long int rectLeft(unsigned long long int *W,
                                unsigned long long int index,
                                unsigned long long int indlb)
{
    unsigned long long int Value = 0;
    
    for(long long int counter = index - 1;counter>=0;counter--)
    {
        if(W[counter]<W[index]) break;
        Value += W[index];
    }
    return Value;
}

unsigned long long int rectRigth(unsigned long long int *W,
                                unsigned long long int index,
                                unsigned long long int indub)
{
    unsigned long long int Value = 0;

    for(long long int counter = index + 1;counter<indub;counter++)
    {

        if(W[counter]<W[index])break;
        Value += W[index];
    }
    return Value;
}

unsigned long long int calculateMaxBounty(unsigned long long int *W,
                                          unsigned long long int indlb,
                                          unsigned long long int indub)
{
    unsigned long long int localMax = 0;
    unsigned long long int MaxValue = 0;

    for(unsigned long long int aa = indlb; aa < indub;aa++)
    {
        localMax = 0;

        if(aa == indlb)
        {
            localMax += rectRigth(W,aa,indub);
        }else if(aa == indub)
        {
            localMax += rectLeft(W,aa,indlb);
        }else{
            localMax += rectRigth(W,aa,indub);
            localMax += rectLeft(W,aa,indlb);
        }
        localMax += W[aa];

        if(MaxValue < localMax) MaxValue = localMax;
    }
    return MaxValue;
}

int main()
{
    unsigned long long int T = 0;
    unsigned long long int N = 0;
    unsigned long long int Ai = 0;
    unsigned long long int countZeros = 0;
    unsigned long long int Warehouses[N_SIZE];
    unsigned long long int ZeroIndices[N_SIZE];
    unsigned long long int maximumBounty= 0;

    unsigned long long int indlb= 0;
    unsigned long long int indub= 0;

    cin >> T;

    for(unsigned long long int tt = 0; tt < T;tt++)
    {
        countZeros = 0;

        cin >> N;
        for(unsigned long long int nn = 0; nn < N;nn++)
        {
            cin >> Ai;
            Warehouses[nn] = Ai;
            if(Ai == 0)
            {
                ZeroIndices[countZeros] = nn;
                countZeros++;
            }
        }
        ZeroIndices[countZeros] = N;
        countZeros++;

        maximumBounty = 0;
        indlb = 0;
        indub= 0;
        for(unsigned long long int zz = 0; zz < countZeros;zz++)
        {
            indub = ZeroIndices[zz];

            unsigned long long int bounty = calculateMaxBounty(Warehouses,indlb,indub);

            if(maximumBounty < bounty) maximumBounty = bounty;

            indlb = indub+1;
        }       
        cout << maximumBounty << endl;
    }
}
