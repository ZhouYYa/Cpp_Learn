#pragma once
#include <iostream>
using namespace std;
// ǰ��4
class VariadicTemplates
{
};

void print()
{

}
template<typename T, typename... Types>
void pring(const T& firstArg, const Types&... args)
{
    cout << firstArg << endl;
    print(args...);
}
// ...����һ��pack
// sizeof...(args)


// auto
auto ite = 12;

// ranged-base for
for(int i : {1, 2, 3})
{
    std::cout << i << std::end;
    //...
}