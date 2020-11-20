#include <iostream>
#include <vector>
#include <math.h>
#include <limits.h>

using namespace std;

constexpr int retSum2I(unsigned int ii)
{
    return (ii*(ii+1))/2;
}

constexpr int retIfromN(unsigned int n)
{
    return floor( (-1 + sqrt(1+(8*n)) )/2 );
}

long long int adding(const vector<long long int> &vectA, unsigned int ii, unsigned int n_elem)
{
    long long int result = 0;

    for(unsigned int jj = ii;jj<ii+n_elem;jj++)
    {
        result += vectA[jj];
    }

    return result;
}

long long int returnAdditions(vector<long long int> &vectA,unsigned int n)
{
    vector<long long int> summations(n,0);
    long long int Steps = retIfromN(n);
    long long int Maximum = LLONG_MIN;

    for(unsigned int ii = 1;ii<Steps;ii++)
    {
        unsigned int offset = retSum2I(ii);
        unsigned int offsetp1 = retSum2I(ii+1);

        summations[n-offset] = adding(vectA,n-offset,offset);

        if(Maximum < summations[n-offset]) Maximum = summations[n-offset];

        if(ii == 1)
        {
            summations[n-2] = vectA[n-2];
            if(Maximum < summations[n-2]) Maximum = summations[n-2];
        }else{
            for(unsigned int kk = offset+1;kk<offsetp1;kk++)
            {
                summations[n-kk] = summations[n-kk+1]+ vectA[n-kk] - vectA[n-(kk - (offset+1))-1];
                if(Maximum < summations[n-kk]) Maximum = summations[n-kk];
            }
            
        }
    }
    summations[n-retSum2I(Steps)] = adding(vectA,n-retSum2I(Steps),retSum2I(Steps));

    if(n-retSum2I(Steps)>0)
    {
        for(unsigned int kk = retSum2I(Steps)+1;kk<=n;kk++)
        {
            summations[n-kk] = summations[n-kk+1]+ vectA[n-kk] - vectA[n-(kk - (retSum2I(Steps)+1))-1];
            if(Maximum < summations[n-kk]) Maximum = summations[n-kk];
        }
    }

    return Maximum;
}

int main()
{
    unsigned int N;
    vector<long long int> A;
    long long int output;
    cin >> N;

    for(unsigned int ii = 0;ii<N;ii++)
    {
        long long int temp_i;
        cin >> temp_i;
        A.push_back(temp_i);
    }
    output = returnAdditions(A,N);

    cout << output;
}
