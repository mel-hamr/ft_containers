// #include "avl_tree.h"
#include <iostream>
#include <map>
int main()
{
  std::map<int,char> m;

  m[0] = 'i';
  m[5] = 'o';
  m[95] = 'y';
  m[3] = 's';
  m[1] = 'b';

  std::map<int,char>::iterator it = m.begin();
  std::map<int,char>::iterator it1 = m.end();

  std::cout << it->second << "\n";
  it++;
  std::cout << it->second << "\n";

  

}
