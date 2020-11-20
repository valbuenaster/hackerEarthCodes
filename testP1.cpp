#include <iostream>
#include <list>
#define N_NUMBERS 3

using namespace std;

int main() 
{
	long long int N = 0;
	long long int iter = 0;
	long long int number = 0;
	long long int result = 1;
	list<long long int > listBuffer;

	list<long long int > listBufferCOPY;
	
	cin >> N;
	
	if(N < N_NUMBERS)
	{
	    cout <<"Too few numbers"<<endl;
	}else
	{
    	for(long long int nn=0;nn<N;nn++)
    	{
    	    cin >> number;
    	    listBuffer.push_back(number);
    	}
    	
    	listBuffer.sort();
        listBufferCOPY = listBuffer;

        while(listBufferCOPY.size()!=0)
        {
            cout<<listBufferCOPY.front()<<" ";
            listBufferCOPY.pop_front();
        }
        cout<<endl;
    	
    	while(iter<N_NUMBERS)
    	{
    	    result *= listBuffer.back();
    	    listBuffer.pop_back();
    	    iter++;
    	}
    	cout << result<<endl;
	}
}
