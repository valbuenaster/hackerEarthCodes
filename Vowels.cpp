#include <iostream>
#include <string>

using namespace std;

int main()
{
        int N;
        int nVowels = 0;
        int found = 0;
        int SSize = 0;
        string InputString;

        cin >> N;

        for(char ii=0;ii<N;ii++)
        {  
                cin >> InputString;
                SSize = InputString.length();
                found = InputString.find_first_of("aeiouAEIOU");
                cout <<"found "<<found<<endl;
                while(found!=-1)
                {
                    nVowels += (SSize-found)*(found+1);
                    found = InputString.find_first_of("aeiouAEIOU",found+1);
                }
                cout << nVowels <<endl;
        }
        
}
