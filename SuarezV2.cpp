#include <iostream>
#include <map>
#include <list>

using namespace std;

struct Nd
{
    unsigned long long int L;
    unsigned long long int R;
    unsigned long long int Distance;
}typedef Node;

constexpr unsigned long long int returnDistance( unsigned long long int &l,
                                            unsigned long long int &r)
{
    return r - l + 1;
}


int main()
{
    unsigned long long int N = 0;
    unsigned long long int Q = 0;
    unsigned long long int Li = 0;
    unsigned long long int Ri = 0;
    unsigned long long int K = 0;
    unsigned long long int X = 0;

    unsigned long long int dist = 0;
    Node Temp;

    cin >> N;

    multimap<unsigned long long int,Node> RedBlackTree1;
    multimap<unsigned long long int,Node> RedBlackTree2;

    for(unsigned long long int nn = 0;nn < N;nn++)
    {
        cin >> Li >> Ri;
        dist = returnDistance(Li,Ri);

        Temp.L = Li;
        Temp.R = Ri;
        Temp.Distance = dist;

        RedBlackTree2.insert(pair<unsigned long long int,Node>(Li,Temp));
    }

    cin >> Q;
    unsigned long long int counter_K = 0;
    unsigned long long int counter_Elem = 0; 

    for(unsigned long long int qq = 0;qq < Q;qq++)
    {
        cin >> K >> X;

        counter_K = 0;
        counter_Elem = 0;  
        RedBlackTree1.clear();

        for(auto Elem:RedBlackTree2)
        {
            if(Elem.second.L <= X)
            {
                if(Elem.second.L + Elem.second.Distance-1 >= X )
                {
                    RedBlackTree1.insert(pair<unsigned long long int,Node>(Elem.second.Distance,Elem.second));
                }
            }else{
                break;
            }
        }

        cout<<"RedBlackTree1"<<endl;
        for(auto Elem:RedBlackTree1) cout<<Elem.first<<" ";
        cout<<endl;

        for(auto Elem:RedBlackTree1)
        {
            counter_Elem++;
            if(Elem.second.L <= X && X <=Elem.second.R)
            {
                counter_K++;
                if(counter_K == K)
                {
                    cout<<Elem.first<<endl;
                    break;
                }
            }

            if((counter_Elem == RedBlackTree1.size())) cout<<"-1"<<endl;
        }


    }

}
