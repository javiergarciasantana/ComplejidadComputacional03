#include <vector>
#include <string>
#include <iostream>

#include "library.h"

#ifndef TAPE_H
#define TAPE_H

// Tape class to simulate the Turing Machine's tape
class Tape {
 private:
  std::vector<Symbol> tape;
  int headPosition;
  Symbol blankSymbol;

public:
  explicit Tape(const std::vector<Symbol>& input, char blank) : blankSymbol(blank), headPosition(0) {
    tape = std::vector<Symbol>(input.begin(), input.end());
    tape.push_back(blank);  // Initialize with blank symbol at the end
  }

  Symbol read() const {
    return headPosition < tape.size() ? tape[headPosition] : blankSymbol;
  }

  void write(Symbol symbol) {
    if (headPosition >= tape.size()) {
      tape.push_back(blankSymbol);
    }
    tape[headPosition] = symbol;
  }

  void moveHead(char direction) {
    if (direction == 'L') {
      if (headPosition > 0) headPosition--;
    } else if (direction == 'R') {
      headPosition++;
      if (headPosition >= tape.size()) {
        tape.push_back(blankSymbol);
      }
    }
  }

  void printTape() const {
    for (Symbol cell : tape) {
      std::cout << cell;
    }
    std::cout << std::endl;
  }
};

#endif 