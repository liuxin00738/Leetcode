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
//
//
//
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




