#include <iostream>
#include <cstdlib>
#include <ctime>

// This code will sort the numbers in the array.
//
// Task: Modify the algorithm to reverse the sort, then comment on its efficiency in the space 
// provided below:
//
//
//
//
//

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
    int hi = -1;
    int hiIndex = -1;
    for (int j = 0; j < 100; j++) {
      if (unsorted[j] > hi) {
        hi = unsorted[j];
        hiIndex = j;
      }
    }
    sorted[i] = hi;
    unsorted[hiIndex] = -1;
  }
  std::cout << "Here are the sorted numbers:" << std::endl;
  for (int i = 0; i < 100; i++) {
    std::cout << sorted[i] << " ";
  }
  std::cout << std::endl;
}

