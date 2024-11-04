// AUTOR: Javier Garcia Santana
// FECHA: 29/10/2024
// EMAIL: alu0101391663@ull.edu.es
// VERSION: 4.0
// ASIGNATURA: Complejidad Computacional
// PRÁCTICA Nº: 3
// COMENTARIOS: Fichero .h en el que se instancia la clase TuringMachine
//
// COMPILACIÓN: make || g++ -std=c++111 -o turnig turing_machine_main.cc

#include <fstream>
#include <sstream>

#include "library.h"
#include "tape.h"

#ifndef TURING_MACHINE_H
#define TURING_MACHINE_H

// TuringMachine class to simulate the machine's behavior
class TuringMachine {
 public:
  virtual Tape getTape() const = 0;
  virtual bool execute() = 0;
};

#endif