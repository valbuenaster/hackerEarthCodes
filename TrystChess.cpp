#include <iostream>
#include <list>

#define SIZE_BOARD 10

using namespace std;

struct Coordinate
{
    int x;
    int y;

    bool operator== (const Coordinate &) const;
    bool operator< (const Coordinate &) const;
};

bool Coordinate::operator== (const Coordinate &f) const{return ((x==f.x)&&(y==f.y));}
bool Coordinate::operator< (const Coordinate &f) const{return x<f.x;}


list<Coordinate> returnFinalPositions(int ii, int jj)
{
    list<Coordinate> listPositions;
    int new_i = 0;
    int new_j = 0;
    Coordinate tempCoord;

    new_i = ii+1;
    new_j = jj+2;
    if( (new_i>=1)&&(new_i<=SIZE_BOARD)&&(new_j>=1)&&(new_j<=SIZE_BOARD))
    {
        tempCoord.x = new_i;
        tempCoord.y = new_j;
        listPositions.push_back(tempCoord);
    }

    new_i = ii-1;
    new_j = jj+2;
    if( (new_i>=1)&&(new_i<=SIZE_BOARD)&&(new_j>=1)&&(new_j<=SIZE_BOARD))
    {
        tempCoord.x = new_i;
        tempCoord.y = new_j;
        listPositions.push_back(tempCoord);
    } 

    new_i = ii+2;
    new_j = jj+1;
    if( (new_i>=1)&&(new_i<=SIZE_BOARD)&&(new_j>=1)&&(new_j<=SIZE_BOARD))
    {
        tempCoord.x = new_i;
        tempCoord.y = new_j;
        listPositions.push_back(tempCoord);
    }

    new_i = ii-2;
    new_j = jj+1;
    if( (new_i>=1)&&(new_i<=SIZE_BOARD)&&(new_j>=1)&&(new_j<=SIZE_BOARD))
    {
        tempCoord.x = new_i;
        tempCoord.y = new_j;
        listPositions.push_back(tempCoord);
    }

    new_i = ii+1;
    new_j = jj-2;
    if( (new_i>=1)&&(new_i<=SIZE_BOARD)&&(new_j>=1)&&(new_j<=SIZE_BOARD))
    {
        tempCoord.x = new_i;
        tempCoord.y = new_j;
        listPositions.push_back(tempCoord);
    }

    new_i = ii-1;
    new_j = jj-2;
    if( (new_i>=1)&&(new_i<=SIZE_BOARD)&&(new_j>=1)&&(new_j<=SIZE_BOARD))
    {
        tempCoord.x = new_i;
        tempCoord.y = new_j;
        listPositions.push_back(tempCoord);
    } 

    new_i = ii+2;
    new_j = jj-1;
    if( (new_i>=1)&&(new_i<=SIZE_BOARD)&&(new_j>=1)&&(new_j<=SIZE_BOARD))
    {
        tempCoord.x = new_i;
        tempCoord.y = new_j;
        listPositions.push_back(tempCoord);
    }

    new_i = ii-2;
    new_j = jj-1;
    if( (new_i>=1)&&(new_i<=SIZE_BOARD)&&(new_j>=1)&&(new_j<=SIZE_BOARD))
    {
        tempCoord.x = new_i;
        tempCoord.y = new_j;
        listPositions.push_back(tempCoord);
    }
    return listPositions;
}

int main()
{
    int i=0;
    int j=0;
    int N=0;
    int counter = 0;
    list<Coordinate> lp;
    list<Coordinate> rp;
    list<Coordinate> mp;

    bool flag = false;

    Coordinate testCoor;
    Coordinate tC;

    cin >> i >> j >> N;

    lp = returnFinalPositions(i,j);

    while(counter<N-1)
    {
        while(lp.size()!=0)
        {
            testCoor = lp.front();
            rp = returnFinalPositions(testCoor.x,testCoor.y);
            lp.pop_front();
            mp.merge(rp);
        }
        while(mp.size()!=0)
        {
            testCoor = mp.front();
            mp.pop_front();
            flag = false;
            for(list<Coordinate>::iterator it=lp.begin() ; it != lp.end(); ++it)
            {
                Coordinate pp = *it;
                if(pp==testCoor) flag = true;
            }
            if(!flag) lp.push_back(testCoor);   
        }
        counter++;
    }

    cout << lp.size()<<endl;

/*
    for(list<Coordinate>::iterator it=lp.begin() ; it != lp.end(); ++it)
    {
        Coordinate pp = *it;
        if(pp==testCoor)
        {
            cout <<"x =  "<< pp.x<<", y = "<<pp.y<<" is repeated"<<endl;
        }else{
            cout <<"x =  "<< pp.x<<", y = "<<pp.y<<endl;
        }
    }
*/
}
