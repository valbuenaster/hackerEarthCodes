#include <iostream>
#include <unordered_map>

using namespace std;

int main()
{
    unsigned long int T = 0;
    unsigned long int N = 0;
    unsigned long int X = 0;
    unsigned long int Ai = 0;

    unordered_map<unsigned long int,unsigned long int> classifier;

    cin >> T;

    for(unsigned long int tt = 0;tt < T;tt++)
    {
        cin >> N >> X;

        for(unsigned long int nn = 0;nn < N;nn++)
        {
            cin >> Ai;

            classifier[Ai] +=1;
        }

        //for(auto Elem:classifier) cout<<"classifier["<<Elem.first<<"] = "<<Elem.second<<endl; 
    
        if(classifier.size()==X)
        {
            cout <<"Good"<<endl;
        }else if(classifier.size()<X){
            cout <<"Bad"<<endl;
        }else{
            cout <<"Average"<<endl;
        }

        classifier.clear();
    }
}
