

    #include <iostream>
    #include <vector>
    #include <map>
    #include <string>
    #include <climits>
     
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
        
        map<long long int,long long int> Y;
        map<long long int,long long int>::iterator it;
        
        cin >> S >> X >> N;
     
        for(long long int ii = 0;ii<N;ii++)
        {
            cin >> Ti >> Yi;
            if((Ti-1)<Tmin) Tmin = Ti-1;
            if((Ti-1)>Tmax) Tmax = Ti-1;
     
            //Y.insert(pair<long long int,long long int> (Ti-1,Yi));
            Y[Ti-1] = Yi;
     
        }
        //summation = Tmin*X;
        //n_days = Tmin;
        
        while(summation < S)
        {
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
            
            //summation += Y[n_days];
            n_days++;
        }
        
        cout << n_days<<endl;
    }


