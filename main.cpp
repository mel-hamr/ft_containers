// #include <vector>
#include "vector.hpp"
#include <iostream>

int main()
{
    std::vector<int> v;

    //v.reserve(5);
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.push_back(5);

    
    ft::vector<int>::iterator it;
    it = v.begin();
    // v.push_back(1);
    // v.push_back(2);
    // v.push_back(3);
    // v.push_back(4);
    // std::vector<int>::iterator it;
    // it = v.begin();
    ++it;
    // --it;
    it +=  2;
    std::cout <<  *it  ;
}