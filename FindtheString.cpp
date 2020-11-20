#include <iostream>
#include <string>
#include <list>

#define NM_SIZE 500

using namespace std;

struct mat_pos
{
    char Letter;
    bool available = true;
}typedef Cluster;


void findString(Cluster Pointer[][NM_SIZE],list<char> &Str,int N,int M)
{
    unsigned int row = 0;
    unsigned int column = 0;
    unsigned int count_column = 0; 
    bool flag = false;  
/*
    cout<<endl<<"Entra a funcion con N = "<<N<<", M = "<<M<<endl;
    for(unsigned int ii=0;ii<N;ii++)
    {
        for(unsigned int jj=0;jj<M;jj++) cout<< Pointer[ii][jj].Letter <<" ";  
        cout <<endl;        
    }
    cout<<"Str "<<endl;
    for(auto e:Str) cout<<e;
    cout<<endl;
*/


    while(Str.size()>0)
    {
        count_column = 0; 
        while(!((Pointer[row][column].available)&&(Pointer[row][column].Letter==Str.front())))
        {
            column = (column+1)%M;
            count_column++;
            if(count_column>=M)
            {
                cout<<"No"<<endl;
                flag = true;
                break;
            }
        }
        if(flag) break;
        if( Pointer[row][column].available && Pointer[row][column].Letter==Str.front() )
        {
            Str.pop_front();
            Pointer[row][column].available = false;
            row = (row+1)%N;
        }

////////////////////////////////////////////////////////
/*
    cout<<endl<<"Step,  Str.size()= "<<Str.size()<<endl;
    for(unsigned int ii=0;ii<N;ii++)
    {
        for(unsigned int jj=0;jj<M;jj++)
        {
            Pointer[ii][jj].available? cout<< Pointer[ii][jj].Letter <<" ": cout <<"* ";  
        }
        cout <<endl;        
    }
    cout<<"Str "<<endl;
    for(auto e:Str) cout<<e;
    cout<<endl<<endl;
*/
////////////////////////////////////////////////////////

    }
    if(Str.size()==0)cout<<"Yes"<<endl;
}

int main()
{
    unsigned int T=0;
    unsigned int N=0;
    unsigned int M=0;
    string Cadena;
    list<char> listStr;

    Cluster Matrix[NM_SIZE][NM_SIZE];

    cin >> T;

    for(unsigned int tt=0;tt<T;tt++)
    {
        cin >> N >> M;

        for(unsigned int nn=0;nn<N;nn++)
        {
            cin >> Cadena;
            unsigned int counter=0;
            for(auto letter:Cadena)
            {
                Matrix[nn][counter].Letter = letter;
                Matrix[nn][counter].available = true;   
                counter++;          
            }
        }

        cin >> Cadena;
        listStr.clear();
        for(auto letter:Cadena) listStr.push_back(letter);

        findString(Matrix,listStr,N,M);
    }
}
