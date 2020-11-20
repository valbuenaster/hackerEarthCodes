#include <iostream>
#include <algorithm>
#include <list>

#define N_SIZE 1000

using namespace std;

void printMatrix(bool P[][N_SIZE],unsigned int N,unsigned int M)
{
        for(unsigned int nn=0;nn<N;nn++)
        {
            for(unsigned int mm=0;mm<M;mm++)
            {
                cout<<P[nn][mm]<<" ";
            }
            cout<<endl;
        }
}

int findSquare(bool P[][N_SIZE],unsigned int ii,unsigned int jj,unsigned int Size)
{
    int retValue = 0;
    bool flag = false;

    cout <<endl<<"Matrix to study"<<endl;
    for(unsigned int nn=ii;nn<ii+Size;nn++)
    {
        for(unsigned int mm=jj;mm<jj+Size;mm++)
        {
            cout << P[nn][mm] << " ";
        }
        cout << endl;
    }

    for(unsigned int nn=ii;nn<ii+Size;nn++)
    {
        for(unsigned int mm=jj;mm<jj+Size;mm++)
        {
            if(P[nn][mm])
            {
                retValue++;
            }else{
                retValue = -1;
                flag = true;
                break;
            }
        }
        if(flag) break;
    }
    return retValue;
}

bool checkOnSides(bool P[][N_SIZE],unsigned int ii,
                                  unsigned int jj,
                                  unsigned int N,
                                  unsigned int M,
                                  unsigned int Size)
{
    bool retValue = true;
/*
    cout <<endl<<"Matrix to study, ii "<<ii
                               <<",jj "<<jj
                               <<",N "<<N
                               <<",M "<<M
                               <<",Size "<<Size<<endl;
*/
/*
    for(unsigned int nn=ii;nn<min(ii+Size,N);nn++)
    {
        for(unsigned int mm=jj;mm<min(jj+Size,M);mm++)
        {
            cout << P[nn][mm] << " ";
        }
        cout << endl;
    }
*/
    for(unsigned int mm=0;mm<Size;mm++)
    {
        //if(!(P[ii+Size][jj+mm]&&P[ii+mm][jj+Size]&&(ii+mm<N)&&(jj+mm<M)))

        if(!(P[ii+Size][jj+mm]&&P[ii+mm][jj+Size]))
        {
            retValue = false;
            //cout<<"Entra al break"<<endl;
            break;
        }
    }
    if(!P[ii+Size][jj+Size])retValue = false;  

    //cout<<"retValue " <<retValue<<endl;

    return retValue;
}

unsigned int findMaxSquared(bool P[][N_SIZE],unsigned int N,unsigned int M)
{
    list<int>N_ones;
    
    for(unsigned int nn=0;nn<N;nn++)
    {
        for(unsigned int mm=0;mm<M;mm++)
        {
            if(P[nn][mm])
            {
                unsigned int side = 1;
                /*
                unsigned int side1 = 0;
                unsigned int side2 = 0;
                while(P[nn+side][mm+side]&&((mm+side)<M)&&((nn+side)<N))side++;
                while(P[nn][mm+side1]&&((mm+side1)<M))side1++;
                while(P[nn+side2][mm]&&((nn+side2)<N))side2++;

                N_ones.push_back(findSquare(P,nn,mm,min(side,min(side1,side2))));
                */

                //while(checkOnSides(P,nn,mm,N,M,side)&&((nn+side < N)||(mm+side<M))) side = side + 1;
                for(side = 1;side<N+M;side++)
                {
                    if(!checkOnSides(P,nn,mm,N,M,side)) break;
                }

                //cout<<"Side "<<side;

                N_ones.push_back(side*side);
            }
        }
    }
    N_ones.sort();
/*
    cout<<"Inside the list"<<endl;
    for(auto u:N_ones)cout <<u<<" ";
    cout<<endl;
*/
    return N_ones.back();
}


int main()
{
    unsigned int T=0;
    unsigned int N=0;
    unsigned int M=0;

//cout << "Beginning"<<endl;

    bool Matrix[N_SIZE][N_SIZE];

    cin >> T;
    
    for(unsigned int tt=0;tt<T;tt++)
    {
        cin >>N>>M;
        for(unsigned int nn=0;nn<N;nn++)
        {
            for(unsigned int mm=0;mm<M;mm++)
            {
                cin >> Matrix[nn][mm];
            }
        }
/*
        cout << "Printed matrix"<<endl;
        printMatrix(Matrix,N,M);
        cout<<endl;
*/
        cout<<findMaxSquared(Matrix, N, M)<<endl;

        for(unsigned int nn=0;nn<N;nn++)
        {
            for(unsigned int mm=0;mm<M;mm++)
            {
                Matrix[nn][mm]=false;
            }
        }

    }
}
