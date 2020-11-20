#include <iostream>
#include <string>
#include <list>

using namespace std;

int palindrome(string * SStr)
{
    int NSize = SStr->length();
    int indR = 0;
    int indL = 0;
    int substrSize = 0;
    int flag = 0;

    int counter1 = 0;
    int counter2 = 0;

    list<char> l1;
    list<char> l2;

    list<char> l3;
    list<char> l4;

    list<char> bs;

    string subStr1;
    string subStr2;
    string dletter;

    if(NSize%2==0)
    {
        indR = int(NSize/2);
        indL = indR-1;
    }else{
        indL = int(NSize/2)-1;
        indR = int(NSize/2)+1;

        dletter = SStr->substr(int(NSize/2),1);
        bs.push_back(dletter[0]);

        cout<<"\ndispute letter "<< dletter <<endl;

        //l1.push_back(dletter[0]);
        //l2.push_back(dletter[0]); 
    }

    subStr1 = SStr->substr(0,indL+1);
    subStr2 = SStr->substr(indR);

    substrSize = subStr1.length();

    for(char ii=0;ii<substrSize;ii++)
    {
        l1.push_back(subStr1[ii]);
        l2.push_back(subStr2[ii]); 
    }

    l1.sort();
    l2.sort();

    l3 = l1;
    l4 = l2;

    



    cout <<endl<< subStr1 <<" "<< subStr2 <<" "<<substrSize<<" "<<l1.size() <<" " <<l2.size() << endl;

    cout<<"\nlistas ordenadas \n";

     while(l3.size()!=0)
    {
        cout<<l3.front();
        l3.pop_front();
    } 
    cout<<"\n";

     while(l4.size()!=0)
    {
        cout<<l4.front();
        l4.pop_front();
    }
    cout<<endl;

    while(l1.size()!=0)
    {
        if(l1.front()==l2.front())
        {
            l1.pop_front();
            l2.pop_front();
            counter1++;
            cout<<"0";
        }else
        {
            if( (flag==0) && ( (l1.front()==bs.front()) || (bs.front()==l2.front()) ) )
            {
            l1.pop_front();
            l2.pop_front();
            counter1++;
            cout<<"0";
            }else{
                break;
            }
        }
    }
    cout<<"\n";

    if((counter1 == substrSize)||(counter1 == substrSize-1))
    {
        cout <<"yes "<<counter1<<endl<<endl;
        return 1;
    }else
    {
        cout <<"no"<<counter1<<endl<<endl;
        return 0;
    }
}

int main()
{
    string Str;
    int N = 0;
    int L = 0;
    int NFriends = 0;

    cin >> N >> L;

    for(char ii=0;ii<N;ii++)
    {
        cin >> Str;
        NFriends += palindrome(&Str);
    }
    cout << NFriends<<endl;
}
