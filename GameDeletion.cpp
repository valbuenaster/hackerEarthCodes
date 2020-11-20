#include <iostream>
#include <vector>
#include <stdlib.h>

using namespace std;

int main()
{
    long int N;
    unsigned long long int p;

    unsigned long long int summ_p1 = 0;
    unsigned long long int summ_p2 = 0;
    unsigned long long int or_p1 = 0;
    unsigned long long int or_p2 = 0;

    long long int res1 = 0;
    long long int res2 = 0;

    vector<unsigned long long int> Player1;
    vector<unsigned long long int> Player2;

    cin >> N;

    for(long int ii=0;ii<N;ii++) 
    {
        cin >> p;
        summ_p1 += p;
        or_p1 |= p;
        Player1.push_back(p);
    }

    for(long int ii=0;ii<N;ii++) 
    {
        cin >> p;
        summ_p2 += p;
        or_p2 |= p;
        Player2.push_back(p);
    } 

    res1 = summ_p1 - or_p1; 
    res2 = summ_p2 - or_p2;

    (res1 > res2)? cout<<"1 ":cout<<"2 ";

    cout<<abs(res1-res2);
    
  
}
