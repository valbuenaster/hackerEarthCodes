#include <iostream>
#include <string>
#include <unordered_map>

#define N_SIZE 26

int hashFunct(char index)
{
    int retVal(index - 'a');
    return retVal;
}

void cleanHash(int * P)
{
    for(unsigned int aa = 0; aa < N_SIZE;aa++) P[aa] = 0;
}

using namespace std;

int main()
{
    unsigned int T = 0;
    int counter = 0;
    int Reference = 0;
    int counter_segments = 0;
    int counter_cont = 0;
    unsigned int aa =0;
    bool flag = true;
    string StrPattern;
    string StrText;

    //unordered_map<char,int> hashTable;
    //unordered_map<char,int> hashSegment;

    int hashTable[N_SIZE];
    int hashSegment[N_SIZE];

    cleanHash(hashTable);
    cleanHash(hashSegment);

    cin >> T;
    
    for(unsigned int tt = 0; tt < T; tt++)
    {
        cin >> StrPattern;

        for(char letter:StrPattern) hashTable[hashFunct(letter)] +=1;

        Reference = StrPattern.size();

        cin >> StrText;
        
        for(aa=0;aa<StrText.size()-Reference+1;aa++)
        {
            counter_segments = 0;
            //string tempStr = StrText.substr(aa,Reference); 
            //cout<<endl<<"Substring "<<endl<<tempStr<<endl;

            if(aa==0)
            {
                for(unsigned int bb = 0;bb<Reference;bb++) hashSegment[hashFunct(StrText[bb])] +=1;
            }else{
                hashSegment[hashFunct(StrText[aa-1])] -= 1;
                hashSegment[hashFunct(StrText[aa+Reference-1])] +=1;
            }
/*
            cout<<"Tables"<<endl;
            for(unsigned int aa = 0; aa < N_SIZE;aa++)
            {
                cout<<"letter = "<<char(aa+'a')<<", hashTable = "<<hashTable[aa]<<", hashSegment ="<<hashSegment[aa]<<"."<<endl;
            }
*/
            for(unsigned int aa = 0; aa < N_SIZE;aa++)
            {
                if(hashTable[aa]==hashSegment[aa]) counter_segments++;
            }
            //cout<<"counter_segments = "<<counter_segments<<", Reference = "<<Reference<<endl;

            flag = true;
            if(counter_segments==N_SIZE)
            {
                cout<<"YES"<<endl;
                flag = false;
                break;
            }

            //hashSegment.clear();
        }
        if((aa==StrText.size()-Reference+1)&&flag)cout<<"NO"<<endl;
        cleanHash(hashTable);
        cleanHash(hashSegment);
        //hashSegment.clear();
        //hashTable.clear();
    }
}
