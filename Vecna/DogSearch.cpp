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
// New Description:
// Count the number of times the lowercase substring "dog" appears in some input text.
//
//
// 

int main() {
  std::string input = "The Dogman was no ordinary dog, nor man, but rather a peculiar dog-like man who barked like a dog, and panted like a dog, he even ate like a dog.  He owned a dog named Doglips, and interestingly enough, his favorite food was hotdogs.";
  int index = 0;
  int count = 0;
  std::cout << "Counting dogs:";
  do {
    index = input.find("dog",index );
    if (index != -1) {
      count++;
      std::cout << index << " ";
      index+=3;
    }
  } while (index != -1);
  std::cout << std::endl;  
  std::cout << "The lowercase substring \"dog\" appears " << count << " times." << std::endl;
}




