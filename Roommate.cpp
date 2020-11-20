#include <iostream>

using namespace std;

unsigned long minimumOnes(unsigned long int n)
{
    unsigned long sum = 0;
    if(n==1)
    {
        sum = 1;
    }else{
        if(n%2==0)
        {
            sum += minimumOnes(n/2);
        }else{
            sum += (1 + minimumOnes(n-1));
        }
    }
    return sum;
}

int main()
{
    int T;
    unsigned long int N;

    cin >> T;

    for(int ii = 0; ii < T ; ii++)
    {
        cin >> N;
        cout << minimumOnes(N)<<endl;
    }
}
