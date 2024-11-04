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