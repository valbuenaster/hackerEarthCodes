#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool removing(vector<int> &V)
{
    bool ret = false;
    if(V.size()==0)
    {
        ret = true;
    }
/*
    for(vector<int>::iterator it = V.begin() ; it != V.end(); ++it)
    {
        cout << *it;
    }
    cout << endl;
*/
    for(vector<int>::iterator it = V.begin() ; it != V.end(); ++it)
    {
        if(*it==*(it+1))
        {
            /*
            cout <<"Entra a if(it==it+1)"<< endl;
            cout <<"(it+1)-V.begin() = "<< (it+1)-V.begin()<< endl;
            cout <<"V.end()-V.begin() = "<< V.end()-V.begin()<< endl;
            cout <<"V.size() = "<< V.size()<< endl;
            */
            if( (it+1) == V.end()-1)
            {
                //cout <<"Entra aqui..."<< endl;
                V.resize(V.size()-2);
            }else{
                //cout <<"Entra al else."<< endl;
                vector<int> temp;
                temp.assign(it+2,V.end());
                V.assign(V.begin(),it);
                V.insert(V.end(),temp.begin(),temp.end());

            }
            ret = removing(V);
            break;
        }


    }
    return ret;
}


int main()
{
    int T=0;
    string str;
    vector<int> v;

    cin >> T;

    for(unsigned int tt= 0;tt<T;tt++)
    {
        cin >> str;
        for(unsigned int ss = 0;ss<str.size();ss++)
        {
            v.push_back(str[ss]-48);
        }

        if(removing(v))
        {
            cout<<"KHALI"<<endl;
        }else{
            for (vector<int>::iterator it = v.begin() ; it != v.end(); ++it) cout << *it;
            cout << endl;
        }
        v.clear();
    }
}
