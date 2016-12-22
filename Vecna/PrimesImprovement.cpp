#include <iostream>
#include <math.h>  
#include <vector>
// This code should print out the prime numbers.
// Task: Fix and improve the algorithm
// Fix:
// Notice that 1 is not a prime number, and a prime number can be divided by 1 and itself
// So modify line 20 and line 22
//
// Improve: see the second part of the code
// 1, only check odd numbers for numbers bigger than 2
// 2, check until sqrt(i) because if not prime (i.e., i=a*b), one of a&b will be smaller or equal to sqrt(i)
// 3, record the prime numbers and only check prime numbers 
//     because other factors can be write as a composition of prime factors

int main() {
  std::cout << "Printing primes from 1 to 100" << std::endl;
  int i, j;
  bool prime;
  for (i = 2; i <= 100; i++) { // should begin from 2
    prime = true;
    for (j = 2; j < i; j++) {  // also should begin from 2
      if (i % j == 0) {
        prime = false; 
      }
    }
    if (prime) {
      std::cout << i << " ";
    }
  }
  std::cout << std::endl;  
  
  // a faster algorithm  
  std::cout << 2 << " ";          // output 2 which is a prime number
  std::vector<int>  primeVec={2}; // record find primes in a vector
  for (i = 3; i <= 100 ; i=i+2) { // begin from 3 and only check odd numbers
    prime = true;
    for (j = 1; j< primeVec.size() && primeVec[j]<= static_cast<int>(sqrt(i)); j++) {  
    // check only prime factors which <= the square root of i
      if (i % primeVec[j] == 0) {
        prime = false; 
      }
    }
    if (prime) {
      primeVec.push_back(i);  
      std::cout << i << " ";
    }
  }
  std::cout << std::endl;

}

