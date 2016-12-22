-----------------------------------
Question 1:
-----------------------------------
#include <iostream>
#include <cstdlib>
#include <ctime>

// This code will sort the numbers in the array. 
// Task: Modify the algorithm to reverse the sort, then comment on its efficiency in the space 
// provided below:
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

------------------------------------------------
Question 2:
------------------------------------------------
#include <iostream>

// This code should print out the prime numbers.
//
// Task: Fix and improve the algorithm

int main() {
  std::cout << "Printing primes from 1 to 100" << std::endl;
  int i;
  int j;
  bool prime;
  for (i = 1; i <= 100; i++) {
    prime = true;
    for (j = 1; j < i; j++) {
      if (i % j == 0) {
        prime = false; 
      }
    }
    if (prime) {
      std::cout << i << " ";
    }
  }
  std::cout << std::endl;
}

-----------------------------------------------
Question 3
----------------------------------------------
#include <iostream>

// This code will not compile correctly until you fix it.
//
// We are trying to count the number of times the word
// dog appears in some input text, but we can't seem to
// remember the appropriate method call in the string class,
// and are not sure our approach will work.
//
// Task: Use the C++ documentation to help us finish the code,
// then discuss the ambiguity in the problem description, and
// reword it to remove the ambiguity in the space provided below.
//
// 

int main() {
  std::string input = "The Dogman was no ordinary dog, nor man, but rather a peculiar dog-like man who barked like a dog, and panted like a dog, he even ate like a dog.  He owned a dog named Doglips, and interestingly enough, his favorite food was hotdogs.";
  int index = -1;
  int count = 0;
  std::cout << "Counting dogs:";
  do {
    index = input.whereIs("dog");
    if (index != -1) {
      count++;
      std::cout << index << " ";
    }
  } while (index != -1);
  std::cout << "The word \"dog\" appears " << count << " times." << std::endl;
}




