#include <vector>
#include <iostream>

int main()
{
    std::vector<int> v;

    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    std::vector<int>::iterator it;
    it = v.begin();
    std::cout <<  it->first  ;
}