#include <iostream>
#include <string>

using namespace std;

bool isthereNeighbourRight(int **Matrix,int N, int x, int y)
{
    int checky = y+1;

    if( checky >= N ) return false;

    if( Matrix[x][checky] == 'T' )
    {
        return true;
    }else{
        return false;
    }
}

bool isthereNeighbourLeft(int **Matrix,int N, int x, int y)
{
    int checky = y-1;

    if( checky < 0 ) return false;

    if( Matrix[x][checky] == 'T' )
    {
        return true;
    }else{
        return false;
    }
}

bool isthereNeighbourBottom(int **Matrix,int N, int x, int y)
{
    int checkx = x+1;

    if( checkx >= N ) return false;

    if( Matrix[checkx][y] == 'T' )
    {
        return true;
    }else{
        return false;
    }
}

bool isthereNeighbourTop(int **Matrix,int N, int x, int y)
{
    int checkx = x-1;

    if( checkx < 0 ) return false;

    if( Matrix[checkx][y] == 'T' )
    {
        return true;
    }else{
        return false;
    }
}



bool biggestForest(int **pointer,int xx,int yy,int value, int Nf, int *n_trees)
{
    if( pointer[xx][yy] !=  'T' )
    {
        return false;
    }else{
        pointer[xx][yy] = value;
        *n_trees +=1;

        if(isthereNeighbourTop(pointer,Nf,xx,yy)) 
            biggestForest(pointer,xx-1,yy,value,Nf,n_trees);

        if(isthereNeighbourBottom(pointer,Nf,xx,yy))
            biggestForest(pointer,xx+1,yy,value,Nf,n_trees);
        
        if(isthereNeighbourLeft(pointer,Nf,xx,yy))
            biggestForest(pointer,xx,yy-1,value,Nf,n_trees);

        if(isthereNeighbourRight(pointer,Nf,xx,yy))
            biggestForest(pointer,xx,yy+1,value,Nf,n_trees);

        return true;
    }
}




int main()
{
    int N;
    int counter = 0;
    int maxVal = 0;
    string inputLine;
    int **pointer;
    cin >> N;

    pointer = new int*[N];
    for(int ii=0;ii<N;ii++)
    {
        cin >> inputLine;

        pointer[ii] = new int[N];
        
        for(int jj=0;jj<N;jj++)
        {
            pointer[ii][jj] = inputLine[jj];
        }
    }
/*
    cout<<endl<<endl<<"Printing..."<<endl<<endl;

    for(int ii=0;ii<N;ii++)
    {
        for(int jj=0;jj<N;jj++)
        {
            cout << pointer[ii][jj];
        }
        cout<<endl;
    }

    cout<<endl<<"Testing..."<<endl<<endl;

    biggestForest(pointer,0,4,'a',N,&counter);
    //biggestForest(pointer,0,0,'a',N,&counter);
    //biggestForest(pointer,1,3,'b',N,&counter);
    cout<<endl<<"counter "<<counter<<endl<<endl;
*/
    for(int ii=0;ii<N;ii++)
    {
        for(int jj=0;jj<N;jj++)
        {
            if(pointer[ii][jj]!='T') continue;

            counter = 0;
            biggestForest(pointer,ii,jj,-1,N,&counter);

            if(maxVal < counter) maxVal = counter;
        }
    }

    cout <<maxVal<<endl;

    delete[] pointer;
}
