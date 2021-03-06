#include <iostream>
#include <cstdlib>
#include <ctime>

// This code will sort the numbers in the array.
//
// Task: Modify the algorithm to reverse the sort, then comment on its efficiency in the space 
// provided below:
// I Modified line 27, 30, 36
// Time complexity is O(n^2) 
// because n+n+...+n=n*n
// Space complexity is O(n)

int main() {
  int unsorted[100] = {};
  srand (time(NULL));
  for (int i = 0; i < 100; i++) {
    unsorted[i] = rand() % 100;
  }
  std::cout << "Here are the unsorted numbers:" << std::endl;
  for (int i = 0; i < 100; i++) {
    std::cout << unsorted[i] << " ";
  }
  std::cout << std::endl;
  int sorted[100] = {};
  for (int i = 0; i < 100; i++) {
    int hi = 101; // initialized hi to a number bigger than all the numbers
    int hiIndex = -1;
    for (int j = 0; j < 100; j++) {
      if (unsorted[j] <hi) { // keep record the smallest of the unsorted
        hi = unsorted[j];
        hiIndex = j;
      }
    }
    sorted[i] = hi;
    unsorted[hiIndex] = 101; // mark the smallest in unsorted as sorted by set it to 101
  }
  std::cout << "Here are the sorted numbers:" << std::endl;
  for (int i = 0; i < 100; i++) {
    std::cout << sorted[i] << " ";
  }
  std::cout << std::endl;
}

