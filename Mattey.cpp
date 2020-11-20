#include <iostream>
#include <math.h>
#include <boost/multiprecision/cpp_int.hpp>

using namespace std;
using namespace boost::multiprecision;


void printString(cpp_int n,cpp_int m)
{
    /*
    long long int Mm = 0;
    long long int Res = (n*m);
    long long int new_m = m;
    */
    cpp_int Mm = 0;
    cpp_int Res = (n*m);
    cpp_int new_m = m;

    cpp_dec_float<100> temp = 0.0;

//cout<<"Res "<<Res<<endl;

    while(Res>=n)
    {
        temp = 1.0*new_m;
        Mm = floor(log10(temp )/log10(2));

        //Mm = floor(log10(1.0*new_m )/log10(2));

        Res -= (n<<Mm);
        new_m = Res/n;


        if(Res > 0) cout<<"("<<n<<"<<"<<Mm<<") + ";

        if(Res == 0) cout<<"("<<n<<"<<"<<Mm<<")\n";
    }
}


int main()
{
    long int T; 
    //long long int N;
    //long long int M;
    cpp_int N;
    cpp_int M;

    cin >> T;

    for(long int tt=0;tt<T;tt++)
    {
        cin >> N >> M;
        printString(N,M);
    }


    //cout<<"("<<N<<"<<|log("<<M<<")|) "<<(N<<Mm) <<endl<<endl;

    //cout<<"("<<N<<"*"<<M<<") "<< N*M <<endl;

}
