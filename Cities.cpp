    #include <iostream>
    #include <vector>
    #include <map>
    #include <string>
    #include <climits>
    #include <list>

    struct Pareja
    {
        long long int Tii;
        long long int Yii;

        bool operator< (const Pareja &) const; 
        bool operator> (const Pareja &) const; 
        bool operator<= (const Pareja &) const; 
        bool operator>= (const Pareja &) const;
    };

    bool Pareja::operator< (const Pareja &f) const {return Tii < f.Tii;} 
    bool Pareja::operator> (const Pareja &f) const {return Tii > f.Tii;}
    bool Pareja::operator<= (const Pareja &f) const {return Tii <= f.Tii;} 
    bool Pareja::operator>= (const Pareja &f) const {return Tii >= f.Tii;} 
     
    using namespace std;
     
    int main()
    {
        long long int S=0;
        long long int X=0;
        long long int N=0;
        long long int n_days=0;
        
        long long int Yi=0;
        long long int Ti = 0;
        
        long long int Tmax = 0;
        long long int Tmin = LLONG_MAX;
        
        long long int summation = 0;
        
        //map<long long int,long long int> Y;
        list<Pareja> Y;
        //map<long long int,long long int>::iterator it;
        Pareja buffer;
        
        cin >> S >> X >> N;
     
        for(long long int ii = 0;ii<N;ii++)
        {
            cin >> Ti >> Yi;
            if((Ti-1)<Tmin) Tmin = Ti-1;
            if((Ti-1)>Tmax) Tmax = Ti-1;
     
            //Y[Ti-1] = Yi; //works

            //Y += pair<long long int ,long long int >(Ti-1,Yi);
            buffer.Tii = Ti-1;
            buffer.Yii = Yi;

            Y.push_back(buffer);
        }
        //summation = Tmin*X;
        //n_days = Tmin;

        Y.sort();
/*
        for(long long int pp = 0;pp<Y.size();pp++)
        {
            buffer = Y[pp];
            cout << buffer.Tii << " -> "<<buffer.Yii<<endl; 
        }
        cout << endl;
 */
/*
  while (!Y.empty())
  {
    buffer = Y.front();
    cout << buffer.Tii << " -> "<<buffer.Yii<<endl; 
    Y.pop_front();
  }
*/


        while(summation < S)
        {
            buffer = Y.front();
            if(buffer.Tii==n_days)
            {
                summation += buffer.Yii;
                Y.pop_front();
            }else
            {
                summation += X;
            }
            cout<<"summation "<<summation<<endl;
/*
            if((n_days>=Tmin)&&(n_days<=Tmax))
            {
     
                it = Y.find(n_days);
                if(it!=Y.end())
                {
                        summation += it->second;
                        Y.erase(it);
                }else
                {
                        summation += X;
                }
            }else
            {
                summation += X;
            }
            */
            //summation += Y[n_days];
            n_days++;
        }
        
        cout << n_days<<endl;
    }


