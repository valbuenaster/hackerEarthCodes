#include <iostream>
#include <math.h>

using namespace std;


long int returnCost(long int *a,long int *b,long int *c)
{
    long int B_A = (*b) - (*a);
    long int C_B = (*c) - (*b);
    long int Cost = ceil(abs(B_A - C_B)/2.0);

    //cout << *a << *b << *c <<endl;
    //Cost = (*a)+(*b)+(*c);
    return Cost;
}

int main()
{
    long int A,B,C;
    unsigned int T;

    cin >> T;

    for(unsigned int tt;tt<T;tt++)
    {
        cin >>A>>B>>C;
        cout << returnCost(&A,&B,&C)<<endl;
    }   
}
