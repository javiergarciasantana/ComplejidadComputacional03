#include <fstream>
#include <sstream>

#include "library.h"
#include "tape.h"

#ifndef TURING_MACHINE_H
#define TURING_MACHINE_H

// TuringMachine class to simulate the machine's behavior
class TuringMachine {
 private: 
  std::unordered_map<std::string, State> states;
  Alphabet alphabet;
  Tape tape;
  std::unordered_map<std::string, Transition> transitions;
  std::string currentState;

public:
  TuringMachine(const Alphabet& alpha, const Tape& initialTape, const std::unordered_map<std::string, Transition>& trans, const std::string& startState)
    : alphabet(alpha), tape(initialTape), transitions(trans), currentState(startState) {}

  bool execute() {
    while (true) {
      Symbol readSymbol = tape.read();
      std::string key = currentState + readSymbol.getValue();
      
      if (transitions.find(key) == transitions.end()) {
        // No transition found, halt
        return false;
      }

      Transition transition = transitions[key];
      tape.write(transition.getWriteSymbol());
      tape.moveHead(transition.getMovement());
      currentState = transition.getNextState();

      if (states[currentState].checkAcceptance()) {
        return true;
      }
    }
  }
};

// Function to load the Turing Machine from a configuration file
TuringMachine loadMachine(const std::string& filename) {
  std::ifstream file(filename);
  std::string line;
  std::unordered_set<Symbol> inputSymbols, tapeSymbols;
  std::unordered_map<std::string, Transition> transitions;
  std::unordered_map<std::string, State> states;
  std::string initialState;
  char blankSymbol;

  std::cout << "Loading Turing Machine from file: " << filename << std::endl;

  int section = 0;
  while (std::getline(file, line)) {
    // Skip empty lines and comments
    if (line.empty() || line[0] == '#') continue;
    std::istringstream iss(line);

    // Determine which section of the input we're in
    if (section == 0) { // Reading states
      std::cout << "Reading states..." << std::endl;
      std::string state;
      while (iss >> state) {
        states[state] = State(state);
        std::cout << "State added: " << state << std::endl;
      }
      section++;
    } else if (section == 1) { // Reading input alphabet
      std::cout << "Reading input alphabet..." << std::endl;
      char symbol;
      while (iss >> symbol) {
        inputSymbols.insert(Symbol(symbol));
        std::cout << "Input symbol added: " << symbol << std::endl;
      }
      section++;
    } else if (section == 2) { // Reading tape alphabet
      std::cout << "Reading tape alphabet..." << std::endl;
      char symbol;
      while (iss >> symbol) {
        tapeSymbols.insert(Symbol(symbol));
        std::cout << "Tape symbol added: " << symbol << std::endl;
      }
      section++;
    } else if (section == 3) { // Reading initial state
      std::string state;
      iss >> state;
      if (states.find(state) != states.end()) {
        initialState = state;
        std::cout << "Initial state set to: " << state << std::endl;
        section++;
      } else {
        std::cerr << "Error: Initial state not found in the list of states." << std::endl;
        exit(1);
      }
    } else if (section == 4) { // Reading blank symbol
      char symbol;
      iss >> symbol;
      blankSymbol = symbol;
      std::cout << "Blank symbol set to: " << symbol << std::endl;
      section++;
    } else if (section == 5) { // Reading transitions
      std::cout << "Reading transitions..." << std::endl;
      std::string currentState, nextState;
      char readSymbol, writeSymbol, movement;
      while (iss >> currentState >> readSymbol >> writeSymbol >> movement >> nextState) {
        if (states.find(currentState) == states.end() || states.find(nextState) == states.end()) {
          std::cerr << "Error: State not found in the list of states." << std::endl;
          exit(1);
        }
        if (tapeSymbols.find(Symbol(readSymbol)) == tapeSymbols.end() || tapeSymbols.find(Symbol(writeSymbol)) == tapeSymbols.end()) {
          std::cerr << "Error: Tape symbol not found in the list of tape symbols." << std::endl;
          exit(1);
        }
        transitions[currentState + readSymbol] = Transition(currentState, Symbol(readSymbol), nextState, writeSymbol, movement);
        std::cout << "Transition added: (" << currentState << ", " << readSymbol << ") -> ("
                  << nextState << ", " << writeSymbol << ", " << movement << ")" << std::endl;
      }
    }
  }

  Alphabet alphabet(inputSymbols, tapeSymbols, blankSymbol);
  Tape tape(inputSymbols, blankSymbol);
  TuringMachine machine(alphabet, tape, transitions, initialState);

  std::cout << "Turing Machine initialization completed." << std::endl;
  return machine;
}

#endif