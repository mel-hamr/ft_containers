#include "vector.hpp"
#include "map.hpp"
#include <iostream>
#include <vector>

int main()
{
    ft::vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);

    v.resize(0);
    std::cout << " capacity : " << v.capacity() << std::endl;
    ft::vector<int>::iterator it = v.begin();
    ft::vector<int>::iterator it1 = v.end();

    for (; it != it1; it++)
    {
        std::cout << *it <<" ";
    }   
    // std::cout << std::endl << v.capacity() << "\n";
    // v.push_back(2);
    // v.push_back(3);
    // v.push_back(4);
    // std::vector<int>::iterator it;
    // it = v.begin();
    // std::cout <<  it->first  ;
}