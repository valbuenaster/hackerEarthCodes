#include <iostream>
#include <math.h>
#include <iomanip>

using namespace std;

unsigned int n_mult(double Value,unsigned int base)
{
    //cout <<"Value "<<Value<< ", log(Value) "<< log(Value)<<", log(base) "<<log(base)<<endl;
    double temp1 = (log(Value)/log(base));
    //cout << "temp1 = "<<temp1<<", ceil temp1= "<<ceil(temp1)<<endl;
    return ceil(temp1);
}

/*
unsigned int Converting(unsigned int a, unsigned int *b,unsigned int *c)
{
    unsigned int ret = 0;
    unsigned int temp = 0;

    if(a == *b) ret = 0;

    if(a > *b)
    {
        temp = (a - *b);
        ret = int(temp/2) + (temp%2);
    }

    if(a < *b)
    {
        temp = n_mult(ceil(*b/a),*c);
        ret = temp + Converting(a*(pow(*c,temp)),b,c);
    }
    return ret;
}
*/

unsigned int ConvertingS1(unsigned int a, unsigned int *b,unsigned int *c)
{
    unsigned int ret = 0;
    unsigned int temp = 0;

    //cout <<endl<<"a "<< a <<", *b "<< *b <<", *c "<< *c <<endl;

    if(a == *b) ret = 0;

    if(a > *b)
    {
        //cout << "(a > *b)"<<endl;
        temp = (a - *b);
        ret = (unsigned int)(temp/2) + (temp%2);
    }

    if(a < *b)
    {
        //cout << "(a < *b)"<<endl;

        if(ceil(*b/a) == 1)
        {
            temp = 1;
        }else{
            temp = n_mult(ceil(*b/a),*c);
        }
        //cout << "temp "<< temp<<endl;
        ret = temp;
        temp = (a*(pow(*c,temp))) - *b;
        //cout << "temp "<< temp<<endl;
        ret += (unsigned int)(temp/2) + (temp%2);
        //cout << "ret "<< ret<<endl;
    }
    return ret;
}
/*
unsigned int ConvertingS2(unsigned int a, unsigned int *b,unsigned int *c)
{
cout <<endl<<"a "<< a <<", *b "<< *b <<", *c "<< *c <<endl;
    long double ratio = (1.0*(*b))/(*c);
cout << "ratio "<<setprecision(6) << ratio<<endl;
    unsigned int temp = a - ceil(ratio);
cout << "ceil(double(*b/(*c))) "<<ceil(ratio) <<endl;
cout << "temp "<< temp<<endl;
    unsigned int ret = (1 + (unsigned int)(temp/2) + (temp%2));
    temp = (*c)*ceil(ratio) - (*b);
cout << "temp "<< temp<<endl;
    ret += ((unsigned int)(temp/2) + (temp%2));
    return ret;
}
*/

unsigned int ConvertingS2(unsigned int a, unsigned int *b,unsigned int *c)
{
    unsigned int n = ceil(n_mult((*b/a),*c));
    long int cifra = ceil(1.0*((*b)/pow(*c,n)));
    unsigned int temp = a - cifra;
    unsigned int ret = ((unsigned int)(temp/2) + (temp%2)) + 2;
//cout << "retfirst "<< ret<<endl;
    temp = (pow(*c,n)*cifra) - *b;
    ret += ((unsigned int)(temp/2) + (temp%2));

    return ret;
}

int main()
{
    unsigned int T;
    unsigned int A = 0;
    unsigned int B = 0;
    unsigned int C = 0;

    unsigned int N_Steps = 0;

    unsigned int ST1 = 0;
    unsigned int ST2 = 0;

    cin >> T;

    for(unsigned int tt = 0; tt < T; tt++)
    {
        cin >> A >> B >> C;

        if(((A < B)&&(C==0))||((A==0)&&(B>0)))
        {
            cout << 0 << endl;
        }else{
            ST1 = ConvertingS1(A, &B, &C);
            ST2 = ConvertingS2(A, &B, &C);
            //cout <<"ST1 "<<ST1  <<", ST2 "<<ST2  << endl;
            if(ST1 < ST2)
            {
                cout << ST1<<endl;
            }else{
                cout << ST2<<endl;
            }
        }
    }
}
