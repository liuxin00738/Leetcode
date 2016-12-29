// unordered_multimap::insert
#include <iostream>
#include <string>
#include <unordered_map>

int main ()
{
  std::unordered_multimap<std::string,int> first;


  first.insert (std::pair<std::string,int>("GOOG",50)); // move insertion
  first.insert ( {{"ORCL",100},{"GOOG",100}} );    // initializer list insertion
  first.insert (std::pair<std::string,int>("GOOG",100)); // move insertion

  std::cout << "first contains:" << std::endl;
  for (auto& x: first)
    std::cout << x.first << ": " << x.second << std::endl;

  std::cout << std::endl;
  return 0;
}
