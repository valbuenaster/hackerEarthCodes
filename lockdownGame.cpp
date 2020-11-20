#include <iostream>
#include <string>
#include <vector>
#include <iterator>

using namespace std;

unsigned int winner(const string &s, 
                    vector<unsigned int> &v, 
                    unsigned int ii, 
                    unsigned int jj)
{
    unsigned int ret = 0;

    if(v.size()==1)
    {
        ret = v[0];
    }else{
        while(true)
        {
            if(s[ii]=='x')
            {
                ii = (ii+1)%s.size();
                jj = (jj+1)%v.size();
                cout<<"ii "<<ii<<", jj "<<jj<<endl;
            }
            if(s[ii]=='y')
            {
                ii = (ii+1)%s.size();

for (vector<unsigned int>::iterator it = v.begin() ; it != v.end(); ++it)
    cout << ' ' << *it;
  cout << "\n\n";


                vector<unsigned int> temp1;
                vector<unsigned int>::iterator ptr = v.begin();

                for(unsigned int kk = jj+1;kk<v.size();kk++) temp1.push_back(v[kk]);
                v.resize(jj+1);
                v.insert(ptr+jj,temp1.begin(),temp1.end());
                v.pop_back();
                
                //cout<<"v.size() "<<v.size()<<endl;

                ret = winner(s,v,ii,jj); 
                break;
            }
        }
    }
    return ret;
}

int main()
{
    unsigned int N;
    vector<unsigned int> Members;
    string S;

    cin >> N;
    cin >> S;

    //cout<<"S.size() "<<S.size()<<endl;

    for(unsigned int ii = 1;ii <= N;ii++) Members.push_back(ii);
    
    cout << winner(S,Members,0,0)<<endl;
}
