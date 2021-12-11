#include <iostream>
#include "vector/vector.hpp"
#include "map/map.hpp"
#include <map>
// #include <vector>
// #include <utility>
// using namespace std

int main()
{

	ft::map<int, int> ma;

	ft::map<int, int>::iterator it;
	ft::map<int, int>::iterator it_e;
	ma.insert(ft::pair<int, int>(20, 6));
	ma.insert(ft::pair<int, int>(15, 7));
	ma.insert(ft::pair<int, int>(30, 8));
	ma.insert(ft::pair<int, int>(10, 9));
	ma.insert(ft::pair<int, int>(17, 10));
	ma.insert(ft::pair<int, int>(8, 11));
	it = ma.end();
	it--;
	std::cout << " key :" << it->first << " seconde : " << it->second << "\n";
	ma.erase(20);
	ma.printf_map();

	// ma.insert(it,ft::pair<int, int>(13, 11));
	// it = ma.begin();
	// it++;
	// it++;
	// it = ma.begin();

	return 0;
}