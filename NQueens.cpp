#include <iostream>

using namespace std;

bool isattacked(int **board,int x,int y, int N)
{
    for(int ii=0;ii<N;ii++)
    {
        if((board[x][ii]==1)||(board[ii][y]==1))
        {
            return true;            
        }

        if((ii+(y-x)>0)||(ii+(y-x)<N))
        {
            if(board[ii][ii+(y-x)]==1)
            {
                return true;
            }
        }

        if((-ii+(y+x))>0||(-ii+(y+x)<N))
        {
            if(board[ii][-ii+(y+x)]==1)
            {
                return true;
            }
        }


    }
    return false;
}

bool N_Queens(int **Board,int level,int Nf)
{
    if(Nf==level) return true;

    for(int jj=0;jj<Nf;jj++)
    {
        if(isattacked(Board,level,jj,Nf)==true)
        {
            continue;
        }else{
            Board[level][jj] = 1;
            if(N_Queens(Board,level+1,Nf))
            {
                return true;
            }else{
                Board[level][jj] = 0;
            }
        }
    }

    return false;
}


int main()
{
    int N;
    int counter=0;
    int x = 0;
    int y = 1;

    int **pointer; 

    cin >> N;

    pointer = new int*[N];

    for(int ii = 0;ii<N;ii++)
    {
        pointer[ii] = new int[N];
        for(int jj=0;jj<N;jj++)
        {
            pointer[ii][jj] = 0;
        }
    }


    //TESTING
    /*
    pointer[4][2]= 1;

    cout<<endl;
    for(int ii = 0;ii<N;ii++)
    {
        for(int jj=0;jj<N;jj++)
        {
            if(isattacked(pointer,ii,jj,N))
            {
                cout<<"y ";
            }else{
                cout<<"n ";
            }
        }
        cout<<endl;
    }
    cout<<endl;
    */
    //TESTING


    if(N_Queens(pointer,0,N))
    {
        cout<<"YES"<<endl;
        for(int ii = 0;ii<N;ii++)
        {
            for(int jj=0;jj<N;jj++)
            {
                cout<<pointer[ii][jj]<<" ";
            }
            cout<<endl;
        }
        cout<<endl;
    }else{
        cout<<"NO"<<endl;
    }

    delete[] pointer;   
}
