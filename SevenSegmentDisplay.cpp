#include <iostream>
#include <math.h>
#include <vector>

#define NLIM 10000
#define BLANKCHAR '@'

int N_matches[] = {6,2,5,5,4,5,6,3,7,6};

using namespace std;


void printString(char * p)
{
    for(int ii = 0; ii<NLIM; ii++)
    {
        //if(p[ii]!=BLANKCHAR) 
        cout << p[ii];
    }
    cout <<endl;
}

void cleanArray(char * p)
{
    for(int ii = 0; ii<NLIM; ii++) p[ii] = BLANKCHAR;
}

int returnNmatches(char * p)
{
    int returnValue = 0;
    int jj = 0;
    //printString(p);

    while((p[jj]>='0')&&(p[jj]<='9'))//(p[jj] != BLANKCHAR)&&
    {
        //cout << "p["<<jj<<"] " << p[jj] <<endl; 
        returnValue += N_matches[p[jj]-48];
        
        jj++;     
    }

    return returnValue;
}

vector<int> returnMaxNumberGenerated(int nM)
{
    vector<int> returnResult;
    int modifed_nM = 0;
    int n_ones = 0;
    int sevenNumber = 0;

    if( (nM % 2) == 0 ) //Even
    {
        modifed_nM = nM;
        sevenNumber = 0;
    }else //Odd
    {
        modifed_nM = nM - 3;
        returnResult.push_back(7);
    }
    //cout <<endl<<"nM "<< nM<<", modifed_nM "<< modifed_nM<<", sevenNumber "<< sevenNumber<<endl;

    n_ones = int(modifed_nM / 2);
    //cout <<endl<<"n_ones "<< n_ones<<endl;

    while(n_ones>0)
    {
        returnResult.push_back(1);       
        n_ones--;
    }  
    return returnResult;
}

int main()
{
	int T;
    int numberMatches = 0;
	char N[NLIM];
    vector<int> output;

    cleanArray(N);

	cin >> T;

	for(int ii=0;ii<T;ii++)
	{
		cin >> N;
        //cout <<"out\n";

        numberMatches = returnNmatches(N);

        output = returnMaxNumberGenerated(numberMatches);

        //cout << output <<endl;

        for (vector<int>::iterator it = output.begin(); it != output.end(); ++it) cout << *it;
        cout << '\n';

        cleanArray(N);
	}
}
