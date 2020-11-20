#include <iostream>
#include <string>
#include <unordered_map>

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

    unordered_map<char,int> hashTable;
    unordered_map<char,int> hashSegment;

    cin >> T;
    
    for(unsigned int tt = 0; tt < T; tt++)
    {
        cin >> StrPattern;

        for(char letter:StrPattern) hashTable[letter] +=1;

        Reference = StrPattern.size();

        cin >> StrText;
        
        for(aa=0;aa<StrText.size()-Reference+1;aa++)
        {
            counter_segments = 0;
            //string tempStr = StrText.substr(aa,Reference); 
            //cout<<endl<<"Substring "<<tempStr<<endl;

            if(aa==0)
            {
                //for(char letter:tempStr) hashSegment[letter] +=1;
                for(unsigned int bb = 0;bb<Reference;bb++) hashSegment[StrText[bb]] +=1;

            }else{
                //cout<<"letra que sale, "<<StrText[aa-1] <<".letra que entra, "<<tempStr.back()<<"."<<endl;
                hashSegment[StrText[aa-1]] -= 1;
                if(hashSegment[StrText[aa-1]]==0)hashSegment.erase(StrText[aa-1]);
                hashSegment[StrText[aa+Reference-1]] +=1;
            }
            //cout<<"elements hashSegment "<<endl;
            //for(auto hElem:hashSegment) cout<<"hashSegment["<< hElem.first<<"] = "<< hElem.second<<endl;
            //cout<<endl;

            for(auto hElem:hashTable)
            {
                try
                {
                    if(hElem.second==hashSegment.at(hElem.first)) counter_segments++;
                }catch(const out_of_range& oor)
                {
                    break;
                }
            }

            flag = true;
            if(counter_segments==hashTable.size())
            {
                cout<<"YES"<<endl;
                flag = false;
                break;
            }

            //hashSegment.clear();
        }
        if((aa==StrText.size()-Reference+1)&&flag)cout<<"NO"<<endl;
        hashSegment.clear();
        hashTable.clear();
    }
}
