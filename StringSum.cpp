#include <iostream>
#include <string>

#define KOFFSET 96

using namespace std;

int main()
{
    string Str;
    long int summation = 0;
    char Character = 0;
    int ii = 0;

    cin >> Str;
    
    while(ii<Str.length())
    {
        Character = Str[ii];
        summation += (long int)( Character );
        ii++;
    }
    cout <<summation-(KOFFSET*ii)<<endl;
}
