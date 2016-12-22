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

