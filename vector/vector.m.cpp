#include "vector.h"
#include<iostream>

using namespace std;

int main()
{
    Vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(20);

    std::cout << v[v.size()-1] << std::endl;

    for(auto& i : v)
    {
        std::cout << i << std::endl;
    }

    return 0;
}