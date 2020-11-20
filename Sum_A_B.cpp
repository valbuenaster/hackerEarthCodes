#include <iostream>
#include <stdio.h>

using namespace std;

struct pair
{
        long long int A;
        long long int B;
}

int main()
{
    char A[100];
    char B[100];

    int P = 0;
    long long int arrayNumbers[12][2];

    for(char aa=0;aa<12;aa++)
    {
        arrayNumbers[aa][0] = 0;
        arrayNumbers[aa][1] = 0;
    }
    
    for(char ii = 0;ii < 12;ii++)
    {
        try
        {
                cin >> A >> B;
                pair Data;
                Data.A = A;
                Data.B = B;
                throw Data;
        }
        catch(pair param)
        {
                arrayNumbers[P][0] = param.A;
                arrayNumbers[P][1] = param.B;
                P++; 
        }
        
    }


}

/*
#include <iostream>
using namespace std;

int main()
{
    long long int A, B;
    int P;
    long long int **pointer;
    
    cin >> P;
    cout << P << " "<< char(P)<<endl;

    if(char(P)== 97) cout <<"yes\n";

    pointer = new long long *[P];
    
    for(char ii = 0;ii < P;ii++)
    {
        pointer[ii] = new long long [2];
        cin >> A >> B;
        cout << A <<" "<<B<<endl;

        pointer[ii][0] = A;
        pointer[ii][1] = B;
    }

    //for(char ii = 0;ii < P;ii++) cout << pointer[ii][0] <<" "<< pointer[ii][1] << endl;
    for(char ii = 0;ii < P;ii++) cout << pointer[ii][0] + pointer[ii][1] << endl;

    delete[] pointer;
}
*/
