#include <iostream>

#define LEN 10

using namespace std;

constexpr int fibonacci(const int n)
{
    return ( (n==1)||(n==2) )? 1: fibonacci(n-1) + fibonacci(n-2);
}

int main()
{
    char Array[LEN];
    int argument = 10;

    cout << "fibonacci(" <<argument<<") = "<< fibonacci(argument)<<endl;

    return 0; 
}
