#include <iostream>
#include <vector>
#define DEPTH 4

using namespace std;

unsigned long long int maximizeSequence( vector<unsigned long long int> &strFactors, int level, int depth,
                                         unsigned long long int argVal, unsigned long long int maxVal, 
                                         vector<unsigned long long int> &seq)
{
    unsigned long long int sumseq = 0;
    unsigned long long int temp = 0;
    unsigned long long int relative_max = 0;
    
    cout<<"\nlevel "<<level<<endl;
    cout<<"\tseq.size() = "<<seq.size()<<", seq = ";

    for(int pp=0;pp<seq.size();pp++) cout<< seq[pp]<<" ";
    cout<<endl;

    if(level==DEPTH) return maxVal;

    for(long int cc=strFactors.size()-1;cc>=0;cc--)
    {

        unsigned long long int ii = 0;
        while(ii<seq.size())
        {
            sumseq += seq[ii];
            ii++;
        }
        cout<<"sumseq "<< sumseq <<", argVal "<<argVal<<endl;

        if((sumseq > argVal)&&(level < DEPTH-1))
        {
            cout<<"entra a condicion...\n";
            return 0;
            continue;
        }else{
            cout<<"strFactors["<<cc<<"] = "<< strFactors[cc] <<endl;
            seq.push_back(strFactors[cc]);
            temp = maximizeSequence( strFactors,level+1,DEPTH,argVal,strFactors[cc]*maxVal,seq);

            if(relative_max < temp)
            {
                relative_max = temp;
                if(seq.size()>0)
                {
                    seq.pop_back();
                    seq.pop_back();
                    seq.push_back(strFactors[cc]);
                }
            }else{
                seq.pop_back();
            }
        }
    }

    cout<<"level "<<level<<endl;
    cout<<"\tseq.size() = "<<seq.size()<<", seq = ";

    for(int pp=0;pp<seq.size();pp++) cout<< seq[pp]<<" ";
    cout<<endl;

    return relative_max;
}

unsigned long long int calculateMax(unsigned long long int arg)
{
    vector<unsigned long long int> factor;
    vector<unsigned long long int> maximization;
    factor.push_back(1);

    for(unsigned long long int cc=2;cc<=arg/2;cc++) if((arg%cc)==0) factor.push_back(cc);

    cout<<endl;
    for(unsigned long long int cc=0;cc<factor.size();cc++) cout<<factor[cc]<<" ";
    cout<<endl;

    return maximizeSequence(factor,0,DEPTH,arg,1,maximization);
    
}

int main()
{
    long int T;
    unsigned long long int res = 0;
    unsigned long long int input = 0;

    cin >> T;

    for(long int ii=0;ii<T;ii++)
    {
        cin >> input;

        res = calculateMax(input);
        cout<<res<<endl;
    }
}
