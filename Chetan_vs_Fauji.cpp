#include <iostream>
#include <unordered_map>
#include <stdexcept> 

using namespace std;

int main()
{
    unsigned int N = 0;
    unsigned int Contador = 0;
    unsigned int S = 0;
    long long int x = 0;
    long long int y = 0;


    unordered_map<long long int,long long int> my_hashtable;

    cin >>N;

    for(unsigned int nn=0;nn<N;nn++)
    {
        cin >> x >> y;
        my_hashtable[x+y] += 1;       
    }

    cin >> S;
/*
    cout <<"The HashTable, S = "<<S<<endl;
    for(auto element:my_hashtable) cout<<"my_hashtable["<<element.first<<"] = "<<element.second<<endl;
*/

    //cout <<"\nmy_hashtable.size = "<<my_hashtable.size()<<endl<<endl;

    for(auto element:my_hashtable)
    {
        //cout<<"my_hashtable["<<element.first<<"] = "<<element.second<<endl;

        try
        {
            //cout<<"element.first-S "<<element.first-S <<", Complement hash "
            //    << my_hashtable.at(element.first-S)<<endl;

            Contador += element.second * my_hashtable.at(element.first-S);
        }catch (const std::out_of_range& oor) 
        {
            //std::cerr << "PAILA, NO ESTA: " << oor.what() << '\n';
        }

    }
    cout <<Contador<<endl;
}


/*
#include <iostream>

#define N_SIZE 100000

using namespace std;

struct Coordinate
{
    long long int x;
    long long int y;
};

constexpr unsigned int calculation(Coordinate *P,unsigned int ii,unsigned int jj, unsigned int SS)
{
    unsigned int Value = 0;
    if(ii==jj)
    {
        ( (P[ii].x - P[jj].x) + (P[ii].y - P[jj].y) - SS == 0)? Value = 1: Value = 0;
    }else{
        ( (P[ii].x - P[jj].x) + (P[ii].y - P[jj].y) - SS == 0)? Value = 2: Value = 0;
    }
    return Value;
}

int main()
{
    unsigned int N = 0;
    unsigned int Contador = 0;
    unsigned int S = 0;

    Coordinate Cadena[N_SIZE];

    cin >>N;

    for(unsigned int nn=0;nn<N;nn++)
    {
        cin >> Cadena[nn].x >> Cadena[nn].y;
    }

    cin >> S;

    for(unsigned int ii=0;ii<N;ii++)
    {
        for(unsigned int jj=ii;jj<N;jj++)
        {
            Contador += calculation(Cadena, ii, jj, S);
        }
    }
    cout<<Contador<<endl;
}
*/
