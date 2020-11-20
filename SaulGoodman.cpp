#include <iostream>
#include <vector>
#include <stdlib.h>

#define SIZE_N 100000

using namespace std;

struct Coordinate
{
    long int x;
    long int y;
    Coordinate operator- (const Coordinate &);
};
Coordinate Coordinate::operator-(const Coordinate &param)
{
    Coordinate temp;
    temp.x = param.x - x;
    temp.y = param.y - y;

    return temp;
}

int main()
{
    int N = 0;
    int n = 0;
    long int count = 0;
    long int local_count = 0;
    Coordinate tempC;
    Coordinate diff;

    Coordinate positions[SIZE_N];
    bool res_positions[SIZE_N];

    cin >> N;

    for(int ii = 0;ii<N;ii++)
    {
        Coordinate coorBuffer;
        cin >> n;

        //vector<Coordinate> positions;
        //vector<bool> res_positions;


        for(long int jj = 0;jj<n;jj++)
        {
            cin >> coorBuffer.x >> coorBuffer.y;
            positions[jj] = coorBuffer;
            res_positions[jj] = false;
        }

        count = 0;
        for(long int kk = 0;kk<n;kk++)
        {
            if(res_positions[kk]==false)
            {
                res_positions[kk] = true;
                local_count = 0;
                for(long int ll = kk+1;ll<n;ll++)
                {
                    if(ll==kk) continue;
                    diff = positions[ll] - positions[kk];
                    if( abs(diff.x) == abs(diff.y) )
                    {
                        //local_count==0?local_count+=2:local_count++;
                        local_count++;
                        res_positions[ll] = true;
                        cout <<"Pair: "<<endl
                                       <<"("<<positions[ll].x<<","<<positions[ll].y
                                       <<") <-> ("<<positions[kk].x<<","<<positions[kk].y<<")"
                                       <<"\tlocal_count="<<local_count<<endl;
                    }                
                }
                count +=local_count;
            }
        }

        cout<<count<<endl;

    }
}
