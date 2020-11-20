#include <iostream>
#include <list>
#include <vector>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>

using namespace std;

unsigned long int  biggestValueIn_N_bits(unsigned long int bv)
{
    unsigned long int a = bv;
    unsigned long int rem;    
    unsigned long int n = 1;
    unsigned long int valor = 0;
    unsigned long int iter = 0;

    while(a>1)
    {
        a = a / 2; 
        n++;
    }

    while(iter<n)
    {
        valor += pow(2,iter);
        iter++;
    }

    return valor;
}

void createSubstrings(vector<long int> &Numbers,unsigned long int maxVal_Nbits)
{
    long int half_bound = maxVal_Nbits/2;  
    unsigned long int ii = Numbers.size() - 1;

    while(Numbers[ii]>=half_bound)
    {

        if(Numbers[ii] == maxVal_Nbits)
        {
            cout <<"Numbers["<<ii<<"] = "<< Numbers[ii]<<endl;
            Numbers[ii] = -1;
        }else{
            long int otherValue = maxVal_Nbits - Numbers[ii];

            for(unsigned long int jj = 0;jj < half_bound;jj++)
            {
                if(otherValue == Numbers[jj])
                {
                    cout <<"[ "<< Numbers[ii]<<", "<< Numbers[jj]<<"]"<<endl;
                    Numbers[ii] = -1;
                    Numbers[jj] = -1;
                }
            }
        }
        ii--;
    }

    cout <<"---"<<endl;

    for(unsigned long int pp= 0 ; pp<Numbers.size();pp++) if(Numbers[pp]!=-1) cout<< Numbers[pp]<<endl;
}

int main()
{
    int T;
    unsigned long int N;
    unsigned long int a;

    unsigned long int maxVal_Nbits = 0;

    unsigned long int  pp = 0;
    unsigned long int  jj = 0;

    long int  kk = 0;
    long int  ll = 0;


    cin >> T;

    while(jj<T)
    {

        list<unsigned long int> arrayNumbers;
        vector<long int> vectorNumbers;
        vector<long int> vtNumb;
        vector<long int> vt_XOR_Max;
        long int maxmax = 0;

        unsigned long int summationLowerValues = ULONG_MAX;

        cin >> N;
        pp = 0;

        while((pp<N))
        {
            (cin >>a);
            arrayNumbers.push_back(a);
            pp++;
        }
        jj++;

        arrayNumbers.sort();
        maxVal_Nbits = biggestValueIn_N_bits(arrayNumbers.back());

        if(arrayNumbers.back()==maxVal_Nbits) arrayNumbers.pop_back();

        //cout<<"list size "<<arrayNumbers.size() <<", biggest "<<maxVal_Nbits<<endl;

        for(list<unsigned long int>::iterator it=arrayNumbers.begin(); it!=arrayNumbers.end(); ++it)
        {
            vectorNumbers.push_back(*it);      
        }

        //cout<<"vectorNumbers size "<<vectorNumbers.size()<<endl;

        while((vectorNumbers.back() > (unsigned long int)(maxVal_Nbits/2))&&(vectorNumbers.size()>0))
        {
            vtNumb.push_back(vectorNumbers.back());
            //cout<<vectorNumbers.back()<<endl;
            vectorNumbers.pop_back();
        //cout<<"vectorNumbers size "<<vectorNumbers.size()<<endl;
        }
        //cout<<"vtNumb size "<<vtNumb.size()<<endl;

        while(kk<vtNumb.size())
        {
            ll=0;
            while(ll<vectorNumbers.size())
            { 
                if(vectorNumbers[ll]+vtNumb[kk]==maxVal_Nbits)
                {
                    vectorNumbers[ll] = -1;
                    ll++;
                    while(maxVal_Nbits - vectorNumbers[ll]==vtNumb[kk])ll++;
                    vtNumb[kk] = -1;
                }else{
                    ll++;
                }
            }
            kk++;
        }
        //UP TO THIS POINT, WE HAVE THE MAXIMUM

        cout<<"\n";
        for(vector<long int>::iterator it=vectorNumbers.begin(); it!=vectorNumbers.end(); ++it)cout << *it<<" ";  
        cout<<"\n";
      
        for(vector<long int>::iterator it=vtNumb.begin(); it!=vtNumb.end(); ++it)cout << *it<<" ";  
        cout<<"\n\n"; 

        //for(ll = 0;ll<vectorNumbers.size();ll++)
        for(ll = vectorNumbers.size()-1;ll>=0;ll--)
        {         
            if(vectorNumbers[ll]==-1)continue;

            for(kk = 0;kk<vtNumb.size();kk++)
            {
                //cout<<"ll = "<<ll<<", kk = "<<kk<<endl;

                if(vtNumb[kk]==-1)continue;

                cout<<vectorNumbers[ll]<<"^"<<vtNumb[kk]<<" = "<< (vectorNumbers[ll]^vtNumb[kk]) << endl;

                if((vectorNumbers[ll]^vtNumb[kk])<maxVal_Nbits)
                {
                    vtNumb[kk] ^= vectorNumbers[ll];
                }
                if((vectorNumbers[ll]^vtNumb[kk])==maxVal_Nbits)
                {
                    vtNumb[kk] = -1;
                }
            }
            vt_XOR_Max.push_back(maxmax);
        }

        cout<<"\n";
        for(vector<long int>::iterator it=vectorNumbers.begin(); it!=vectorNumbers.end(); ++it)cout << *it<<" ";  
        cout<<"\n";

        for(vector<long int>::iterator it=vtNumb.begin(); it!=vtNumb.end(); ++it)cout << *it<<" ";  
        cout<<"\n\n"; 
     
        for(vector<long int>::iterator it=vt_XOR_Max.begin(); it!=vt_XOR_Max.end(); ++it)cout << *it<<" ";  
        cout<<"\n"; 

        summationLowerValues = maxVal_Nbits;
            cout<<"summationLowerValues "<<summationLowerValues<<endl;
        //for(vector<long int>::iterator it=vtNumb.begin(); it!=vtNumb.end(); ++it)
        for(unsigned long int qq=0;qq<vtNumb.size();qq++)
        {
            if(vtNumb[qq]==-1)continue;
            cout<<"v "<<vtNumb[qq]<<endl;
            summationLowerValues ^= vtNumb[qq];
            cout<<summationLowerValues<<"\n";  
        }
        cout<<summationLowerValues<<"\n";         

    }
 
}
