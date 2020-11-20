/*
// Sample code to perform I/O:

#include <iostream>

using namespace std;

int main() {
	int num;
	cin >> num;										// Reading input from STDIN
	cout << "Input number is " << num << endl;		// Writing output to STDOUT
}

// Warning: Printing unwanted or ill-formatted data to output will cause the test cases to fail
*/

// Write your code here
#include <iostream>
#include <vector>
#include <limits.h>
//#include <boost/multiprecision/long long int.hpp>

using namespace std;
//using namespace boost::multiprecision;

struct Coordinate
{
    long long int x;
    long long int y;

};

class Rectangle
{
    long long int px;
    long long int py;
    long long int width;
    long long int height;
    long long int limXinf;
    long long int limXsup;
    long long int limYinf;
    long long int limYsup;
   
    
    public:
    vector<Coordinate> pointsSet;

    Rectangle(long long int,long long int,long long int,long long int);    
    vector<Coordinate> returnInternalRectangle(const Rectangle&);
};



Rectangle::Rectangle(long long int cx,long long int cy,long long int w,long long int h)
{
    this->px = cx;
    this->py = cy;
    this->width = w;
    this->height = h;
    
    this->limXinf = cx;
    this->limXsup = cx + w;
    this->limYinf = cy;
    this->limYsup = cy + h;
    
    Coordinate bc;
    
    bc.x = cx;
    bc.y = cy;
    pointsSet.push_back(bc);
    
    bc.x = cx + w;
    bc.y = cy;
    pointsSet.push_back(bc);
    
    bc.x = cx + w;
    bc.y = cy + h;
    pointsSet.push_back(bc);
    
    bc.x = cx;
    bc.y = cy + h;
    pointsSet.push_back(bc);    
}

vector<Coordinate> Rectangle::returnInternalRectangle(const Rectangle& param)
{
    vector<Coordinate> vectorP;
    Coordinate point;
    Coordinate fabricated_point;

    for(long long int ii = 0;ii<4;ii++)
    {
        point = param.pointsSet[ii];
        //cout<<"px = "<< point.x<<", py = "<<point.y<<endl;
        if( ( point.x >= (this->limXinf) ) && ( point.x  <= (this->limXsup) ) && 
            ( point.y >= (this->limYinf) ) && ( point.y  <= (this->limYsup) ))
        {//point is inside the rectangle which made the call.
            //cout<<"px = "<< point.x<<", py = "<<point.y<<endl;
            vectorP.push_back(point);
        }else{
            if( ( point.x >= (this->limXinf) ) && ( point.x  <= (this->limXsup) ))
            {
                if( point.y  > (this->limYsup) )
                {
                    fabricated_point.x = point.x;
                    fabricated_point.y = this->limYsup;
                }
                if( point.y  < (this->limYinf) )
                {
                    fabricated_point.x = point.x;
                    fabricated_point.y = this->limYinf;
                }  
                vectorP.push_back(fabricated_point);           
            }

            if(( point.y >= (this->limYinf) ) && ( point.y  <= (this->limYsup) ))
            {
                if( point.x > (this->limXsup))
                {
                    fabricated_point.x = limXsup;
                    fabricated_point.y = point.y;
                }
                if( point.x < (this->limXinf))
                {
                    fabricated_point.x = limXinf;
                    fabricated_point.y = point.y;
                }
                vectorP.push_back(fabricated_point); 
            } 

        }
    }
    return vectorP;
}



int main() 
{
	long long int cx = 0;
	long long int cy = 0;
	long long int w = 0;
	long long int h = 0;

    long long int maxX = LLONG_MIN;
    long long int minX = LLONG_MAX;
    long long int maxY = LLONG_MIN;
    long long int minY = LLONG_MAX;

    vector<Coordinate> vectt1;
    vector<Coordinate> vectt2;


    vector<Coordinate> vecttpointsInter;
	
	cin >> cx >> cy >>  w >>  h;
    Rectangle rect1(cx,cy,w,h);

	cin >> cx >> cy >>  w >>  h;
    Rectangle rect2(cx,cy,w,h);

    vectt2 = rect2.returnInternalRectangle(rect1);
    vectt1 = rect1.returnInternalRectangle(rect2);
/*
    cout<<"POints...\n";

    for(int aa = 0;aa<vectt1.size();aa++)
    {
        Coordinate pp;
        pp = vectt1[aa];
        cout<<"pp = "<< pp.x<<", pp = "<<pp.y<<endl;
    }
    cout<<endl;

    for(int aa = 0;aa<vectt2.size();aa++)
    {
        Coordinate pp;
        pp = vectt2[aa];
        cout<<"pp = "<< pp.x<<", pp = "<<pp.y<<endl;
    }
    cout<<endl;

    cout<<"confrontation...\n";
*/
    (vectt1.size()>vectt2.size())? vecttpointsInter = vectt1: vecttpointsInter = vectt2;

    if(vectt1.size()==4) vecttpointsInter = vectt1;
    if(vectt2.size()==4) vecttpointsInter = vectt2;


    for(int aa = 0;aa<vecttpointsInter.size();aa++)
    {
        Coordinate pp;
        pp = vecttpointsInter[aa];
        //cout<<"pp = "<< pp.x<<", pp = "<<pp.y<<endl;
        if(pp.x<minX) minX = pp.x;
        if(pp.y<minY) minY = pp.y;
        if(pp.x>maxX) maxX = pp.x;
        if(pp.y>maxY) maxY = pp.y;
    }
    cout<<(maxX-minX)*(maxY-minY) <<endl;
}
