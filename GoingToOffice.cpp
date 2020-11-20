#include <iostream>

using namespace std;

long long int calculateCostOnline(long long int *D,long long int *Oc,long long int *Of,long long int *Od)
{
    long long int value;
    value = (*D < *Of)? *Oc: *Oc + (*Od)*(*D - *Of);
    return value;
}

long long int calculateCostRoad(long long int *D,long long int *Cs,long long int *Cb,long long int *Cm,long long int *Cd)
{
    return ( (*D)*(*Cd) ) + ( ((long long int)(*D)/(*Cs))*(*Cm) ) + *Cb;
}

int main()
{
    long long int D;
    long long int Oc,Of,Od;
    long long int Cs,Cb,Cm,Cd;

    long long int CostOnline=0;
    long long int CostRoad=0;

    cin >> D;
    cin >>Oc>>Of>>Od;
    cin >>Cs>>Cb>>Cm>>Cd;
    
    CostOnline = calculateCostOnline(&D,&Oc,&Of,&Od);
    CostRoad = calculateCostRoad(&D,&Cs,&Cb,&Cm,&Cd);

    (CostOnline <= CostRoad)? cout<<"Online Taxi\n":cout<<"Classic Taxi\n";

}
