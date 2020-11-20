/*
#include <iostream>

using namespace std;

template<typename ... T>
auto mean(T ... t)
{
    auto Size = sizeof...(t);
    return (t + ...)/Size;
}

int main(int argc,char** argv)
{
    cout << "You have entered " << argc << " arguments:" << endl; 
  
    for (int i = 0; i < argc; ++i) 
        cout << argv[i] << endl;

    cout << mean(1, 2, 3, 4, 5, 6, 7, 8, 9, 10) <<endl;

    return 0; 
    
}
*/
#include <iostream>
template<typename ... T>
auto average(T ... t) {
    return (t + ... ) / sizeof...(t);
}
int main() {
    std::cout << average(1, 2, 3, 4, 5, 6, 7, 8, 9, 10) << std::endl;
}
