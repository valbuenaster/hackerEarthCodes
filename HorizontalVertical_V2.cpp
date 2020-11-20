#include <iostream>
#include <list>
#include <vector>
#include <climits>
#include <cmath>

#define C_MAX LONG_MAX

using namespace std;


int main()
{
    long int N;
    long int Minimization = 0;

    long int x = 0;
    long int y = 0;

    long int min_x = C_MAX;
    long int min_y = C_MAX;

    long int dist_x = 0;
    long int dist_y = 0;
    long int temp_x = 0;
    long int temp_y = 0;

    list<long int> X;
    list<long int> Y;

    vector<long int> vect_X;
    vector<long int> vect_Y;

    cin >> N;
    if(N>1)
    {
        for(long int ii = 0; ii < N ; ii++)
        {
            cin >> x >> y;

            X.push_back(x);
            Y.push_back(y);
        }

        X.sort();
        Y.sort();

        while(X.size()!=0)
        {
            vect_X.push_back(X.front());
            X.pop_front();
        }

        while(Y.size()!=0)
        {
            vect_Y.push_back(Y.front());
            Y.pop_front();
        }   

        for(long int ii = 0;ii<N;ii++)
        {
            dist_x += abs(vect_X[ii]-vect_X[0]);
            dist_y += abs(vect_Y[ii]-vect_Y[0]);
        }
     
        for(long int jj=1;jj<N;jj++)
        {
            //cout<<endl<<"dist_x "<<dist_x <<", dist_y"<<dist_y;
            temp_x = vect_X[jj] - vect_X[jj-1];
            temp_y = vect_Y[jj] - vect_Y[jj-1];

            dist_x = dist_x -((N-jj)*temp_x) + (jj*temp_x);
            dist_y = dist_y -((N-jj)*temp_y) + (jj*temp_y);

            if(dist_x<min_x) min_x = dist_x;
            if(dist_y<min_y) min_y = dist_y;
        }
        //cout<<endl;

        (min_x > min_y)? Minimization = min_y:Minimization = min_x;

        cout << Minimization<<endl;
    }else{
        cout <<"0"<<endl;
    }
}
