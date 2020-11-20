#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <math.h>
#include<bits/stdc++.h>

using namespace std;

char Mapa[4] = {'a','b','c','d'};

vector<int> returnQuaternary(long int value, long int n_pos)
{
    vector<int> retVect;
    int target = value;
    int module_r = 0;
    int counter = 0;
    int ii = 0;

    while(ii<n_pos)
    {
        while(target!=0)
        {
            module_r = target % 4;
            target = target / 4;

            retVect.push_back(module_r);
            ii++;
        }
        if(retVect.size()<n_pos)retVect.push_back(0);
        ii++;
    }
/*
    cout<<"n = "<<value<<", quad = ";
    while(counter < retVect.size() ) 
    {
        cout<<retVect[counter];
        counter++;
    }
    cout<<endl;
*/
    return retVect;
}

void returnManyPos(long int value,long int *offset,long int *n_pos)
{
    long int counter = 1;
    long int target = value;

    long int adv = pow(4,counter);
    long int prev_adv = 0;
    while(adv<target)
    {
        counter++;
        prev_adv = adv;
        adv += pow(4,counter);
    }

    *offset = prev_adv;
    *n_pos = counter++;
}

string Solve (long int k, long int np) 
{
   // Write your code here
    string s;
    int counter = 0;
    string Letter;
    vector<int> vect;
    vect = returnQuaternary(k, np);

    counter = vect.size()-1;
    while(counter >= 0)
    {
        Letter = Mapa[vect[counter]];
        s.append(Letter);
        counter--;       
    }

    counter = 0;
    while(counter < vect.size())
    {
        Letter = Mapa[vect[counter]];
        s.append(Letter);
        counter++;
    }

    return s;
}


int main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T; 

    long int n_offset = 0;
    long int n_position = 0;

    cin >> T;
    for(int t_i=0; t_i<T; t_i++)
    {
        int k;
        cin >> k;

        returnManyPos(k, &n_offset,&n_position);
        //cout<<"n_offset "<<n_offset<<", n_pos "<<n_position <<endl;

        string out_;

        out_ = Solve(k-n_offset-1,n_position);
        cout << out_;
        cout << "\n";
    }
}
