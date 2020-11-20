#include <iostream>

using namespace std;

bool determine(unsigned int n)
{
    bool val = false;
    bool val_10 = false;
    bool val_20 = false;

    //cout << "n " << n <<endl;

    if(n%10==0)
    {
        val_10 = determine(n/10);
    }else
    {
        val_10 = false;
    } 

    if(n%20==0){
        val_20 = determine(n/20);
    }else
    {
        val_20 = false;
    } 

    val = val_10 | val_20;

    if(n == 1) val = true;  

    return val;  
}

int main()
{
	unsigned int T;
	unsigned long int N;

	cin >> T;

	for(unsigned int tt=0;tt < T;tt++)
	{
		cin >> N;
		if(determine(N)==true)
		{
			cout <<"Yes"<<endl;
		}else{
			cout <<"No"<<endl;
		}
	}

}
