#include <iostream>

#include "simultaneous_turing_machine.h"

int main(int argc, char* argv[]) {
  std::string input;
  std::cout << "Enter input string: ";
  std::cin >> input;
  std::vector<Symbol> inputSymbols;
  for (char ch : input) {
    inputSymbols.push_back(Symbol(ch));
  }
  TuringMachine* tm = loadSimultaneousMachine(std::string(argv[1]), inputSymbols);
 
  if (tm->execute()) {
    std::cout << "Accepted." << std::endl;
  } else {
    std::cout << "Rejected." << std::endl;
  }

  tm->getTape().printTape();
  return 0;
}