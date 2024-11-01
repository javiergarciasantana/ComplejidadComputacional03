#include <iostream>
#include "turing_machine.h"

int main() {
  TuringMachine tm = loadMachine("machine_config.txt");
  std::string input;
  std::cout << "Enter input string: ";
  std::cin >> input;
  Tape tape(input, tm.getBlankSymbol());
  if (tm.execute()) {
    std::cout << "Accepted." << std::endl;
  } else {
    std::cout << "Rejected." << std::endl;
  }
  tape.printTape();
  return 0;
}