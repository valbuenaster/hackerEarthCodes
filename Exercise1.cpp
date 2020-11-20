#include <iostream>
#include <string>
#include <map>
#include <utility>

//using namespace std;
/*
template<typename Key, typename Value, typename F>
void update(map<Key,Value> & m, F foo)
{

}
*/
int main()
{
    std::map<std::string, long long int> m = {{"a",1},{"b",2},{"c",3}};
/*
    update(m, [](string key){
        return hash<string>{} (key); 
    });
*/ 

    for(const auto& element:m)
    {
        std::cout<<element.first<<" , "<<element.second<<std::endl;
    }

     for (auto&& [key, value] : m)
        std::cout << key << ":" << value << std::endl; 
}

