#include <iostream>
#include <vector>
#include <climits>
#include <cmath>

#define C_MAX 0.9*LONG_MAX

using namespace std;

struct Point
{
    long int x;
    long int y;

    Point operator+ (const Point &);
    Point operator- (const Point &);
};

Point Point::operator+ (const Point &param)
{
    Point temp;
    temp.x = x + param.x;
    temp.y = y + param.y;

    return temp;
}

Point Point::operator- (const Point &param)
{
    Point temp;
    temp.x = x - param.x;
    temp.y = y - param.y;

    return temp;
}

int main()
{
    long int N;
    long int Minimization = 0;
    long int av_x;
    long int av_y;
    long int sum_x;
    long int sum_y;

    double min_x = C_MAX;
    double min_y = C_MAX;

    Point point;
    Point temp;

    vector<Point> setPoints;
    vector<long long int> accountDx;
    vector<long long int> accountDy;

    cin >> N;

    for(long int ii = 0; ii < N ; ii++)
    {
        cin >> point.x >> point.y;

        av_x += point.x;
        av_y += point.y;

        setPoints.push_back(point);

        accountDx.push_back(0);
        accountDy.push_back(0);
    }

    av_x /= N;
    av_y /= N;

    for(long int ii = 0; ii < N ; ii++)
    {
        point = setPoints[ii];
        sum_x = 0;
        sum_y = 0;
        for(long int jj = ii+1;jj < N; jj++)
        {
            temp = point - setPoints[jj];

            temp.x = abs(temp.x);
            temp.y = abs(temp.y);

            sum_x += temp.x;
            sum_y += temp.y;
  
            accountDx[jj] += temp.x;
            accountDy[jj] += temp.y;         
        }
        accountDx[ii] = sum_x + accountDx[ii];
        accountDy[ii] = sum_y + accountDy[ii];

        if(accountDx[ii]<min_x) min_x = accountDx[ii];
        if(accountDy[ii]<min_y) min_y = accountDy[ii];
    }

    (min_x > min_y)? Minimization = min_y:Minimization = min_x;
    cout << Minimization<<endl;

}
