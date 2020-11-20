#include <iostream>

using namespace std;


unsigned int Converting(unsigned int a, unsigned int *b,unsigned int *c)
{
    unsigned int ret = 0;

    if(a == *b) ret = 0;

    if(a >= *b + 2)
    {
        ret = 1 + Converting(a-2,b,c);
    }
    
    if(a == *b + 1)
    {
        ret = 1 + Converting(a-1,b,c);
    }

    if(a < *b)
    {
        ret = 1 + Converting(a*(*c),b,c);
    }

    return ret;
}

int main()
{
    unsigned int T;
    unsigned int A = 0;
    unsigned int B = 0;
    unsigned int C = 0;

    unsigned int N_Steps = 0;

    cin >> T;

    for(unsigned int tt = 0; tt < T; tt++)
    {
        cin >> A >> B >> C;

        if(((A < B)&&(C==0))||((A==0)&&(B>0)))
        {
            cout << 0 << endl;
        }else{
            cout << Converting(A, &B, &C) << endl;
        }
    }
}
