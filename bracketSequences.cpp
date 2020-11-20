#include <iostream>

#define NPOS 500000

char Array[NPOS];

using namespace std;

bool studyArray(unsigned int index,unsigned int N)
{
    bool ret = false;
    long int counter = 0;
    unsigned int mmodu = 0;

    //if(Array[index]==')') ret = false;
    //cout<<"index "<<index <<", index+N "<<index+N <<endl;
    //cout<<endl;

    for(unsigned int ii = index;ii < index+N;ii++)
    {
        mmodu = ii % N;
        //cout<<mmodu<<" ";
        if(Array[mmodu]=='(')
        {
            counter += 1;
        }
        if(Array[mmodu]==')')
        {
            counter -= 1;
        }
        //cout<<"counter "<<counter<<endl;
        if(counter < 0)
        {
            ret = false;
            break;
        }
    }

    if(counter == 0) ret = true;

    return ret;
}

int main() 
{
    unsigned int n = 0;
    unsigned int count = 0;
	cin >> Array;

    for(n = 0;n<NPOS;n++)
    {
        if((Array[n]!= '(') && (Array[n]!= ')')) break;  
    }

    for(unsigned int ii=0;ii<n;ii++)
    {
        if(studyArray(ii,n)) count++;
    }
	cout << count <<endl;
}
