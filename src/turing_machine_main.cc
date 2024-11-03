#include <iostream>

#include "turing_machine.h"

int main(int argc, char* argv[]) {
  std::string input;
  std::cout << "Enter input string: ";
  std::cin >> input;
  std::vector<Symbol> inputSymbols;
  for (char ch : input) {
    inputSymbols.push_back(Symbol(ch));
  }
  TuringMachine tm = loadMachine(std::string(argv[1]), inputSymbols);
 
  if (tm.execute()) {
    std::cout << "\nAccepted." << std::endl;
  } else {
    std::cout << "\nRejected." << std::endl;
  }
  
  tm.getTape().printTape();
  return 0;
}