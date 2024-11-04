#include <iostream>
#include <vector>
#include <functional> 
#include <unordered_map>
#include <unordered_set>
#include <fstream>
#include <string>

#ifndef LIBRARY_H
#define LIBRARY_H


// Symbol class to represent individual symbols in the Turing Machine
class Symbol {
 private:
  char value;

 public:
  Symbol(char val) : value(val) {}

  char getValue() const { return value; }

  bool operator==(const Symbol& other) const {
    return value == other.value;
  }

  friend std::ostream& operator<<(std::ostream& os, const Symbol& symbol) {
    os << symbol.value;
    return os;
  }
};

// Hash specialization for the Symbol class
namespace std {
    template <>
    struct hash<Symbol> {
        std::size_t operator()(const Symbol& s) const noexcept {
            return std::hash<char>{}(s.getValue());
        }
    };
} 

// Alphabet class to handle input and tape symbols
class Alphabet {
 private:
  std::unordered_set<Symbol> inputSymbols;  // Σ
  std::unordered_set<Symbol> tapeSymbols;    // Γ
  Symbol blankSymbol;  // The blank symbol on the tape (b)

 public:

  Alphabet(const std::unordered_set<Symbol>& input, const std::unordered_set<Symbol>& tape, Symbol blank)
    : inputSymbols(input), tapeSymbols(tape), blankSymbol(blank) {}

  bool isInputSymbol(Symbol symbol) const {
    return inputSymbols.find(symbol.getValue()) != inputSymbols.end();
  }

  bool isTapeSymbol(Symbol symbol) const {
    return tapeSymbols.find(symbol.getValue()) != tapeSymbols.end();
  }
};


// State class to handle each state in the Turing Machine
class State {
 private:
  std::string name_;
  bool isAccepting;

 public:
 // Default constructor
  State() : name_(""), isAccepting(false) {}

  State(std::string name, bool accepting = false) : name_(name), isAccepting(accepting) {}
  bool checkAcceptance() const { return isAccepting; }
  void setAcceptance(bool accepting) { isAccepting = accepting; }
};

// Transition class to represent each transition (δ)
class Transition {
 private:
  std::string currentState;
  Symbol readSymbol;
  std::string nextState;
  Symbol writeSymbol;
  char movement; // 'L' for left, 'R' for right, 'S' for stationary

 public:

  Transition() : currentState(""), readSymbol(' '), nextState(""), writeSymbol(' '), movement(' ') {}

  Transition(std::string curr, Symbol read, std::string next, char write, char move)
  : currentState(curr), readSymbol(read), nextState(std::move(next)), writeSymbol(write), movement(move) {}

  std::string getCurrentState() const { return currentState; }
  Symbol getReadSymbol() const { return readSymbol; }
  std::string getNextState() const { return nextState; }
  Symbol getWriteSymbol() const { return writeSymbol; }
  char getMovement() const { return movement; }

};

#endif