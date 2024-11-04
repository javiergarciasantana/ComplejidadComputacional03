// AUTOR: Javier Garcia Santana
// FECHA: 29/10/2024
// EMAIL: alu0101391663@ull.edu.es
// VERSION: 4.0
// ASIGNATURA: Complejidad Computacional
// PRÁCTICA Nº: 3
// COMENTARIOS: Fichero .cc en el que se inicializa la máquina de Turing simultánea
//
// COMPILACIÓN: make || g++ -std=c++111 -o turnig turing_machine_main.cc

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