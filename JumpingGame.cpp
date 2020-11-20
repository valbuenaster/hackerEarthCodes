#include <iostream>

using namespace std;

/*
long long int minimalCost(long long int N, long long int *A, long long int *B)
{
    long long int Cost = 0;

    if(N == 1)
    { 
        Cost += *A;
    }else
    {
        if(N % 2 !=0)
        {
            N = N -1;//and need to charge A
            Cost += *A;
        }

        if( (N/2)*(*A) > *B )
        {
            Cost += *B;
            Cost += minimalCost(N/2, A, B);
        }else
        {
            Cost += (N/2)*(*A);
            Cost += minimalCost(N/2, A, B); 
        }
    }

    return Cost;
}
*/
/*
long long int minimalCost(long long int *N, long long int *A, long long int *B)
{
    long long int Cost = 0;

    if(*N == 1)
    { 
        Cost += *A;
    }else
    {
        if(*N % 2 !=0)
        {
            *N = *N -1;//and need to charge A
            Cost += *A;
        }

        if( (*N/2)*(*A) > *B )
        {
            Cost += *B;
        }else
        {
            Cost += (*N/2)*(*A);
        }
        *N = *N/2;
        Cost += minimalCost(N, A, B); 
    }

    return Cost;
}
*/

void minimalCost(long long int *N, long long int *A, long long int *B,long long int *Cost)
{
    while(*N!=0)
    {
        if(*N == 1)
        { 
            *Cost += *A;
            *N = 0;
        }else
        {
            if(*N % 2 !=0)
            {
                *N = *N -1;//and need to charge A
                *Cost += *A;
            }

            if( (*N/2)*(*A) > *B )
            {
                *Cost += *B;
            }else
            {
                *Cost += (*N/2)*(*A);
            }
            *N = *N/2;
            //Cost += minimalCost(N, A, B); 
        }
    }
    //return Cost;
}


int main()
{
    int t=0;

    long long int n = 0;
    long long int a = 0;
    long long int b = 0;

    long long int Costo = 0;

    cin >>t;

    for(int ii = 0; ii < t ; ii++)
    {
        cin >> n >> a >> b;

        //cout << minimalCost(&n, &a, &b)<<endl;
        Costo = 0;
        minimalCost(&n, &a, &b,&Costo);
        cout<<Costo<<endl;
    }

}
