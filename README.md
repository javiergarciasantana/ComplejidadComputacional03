# Simultaneous Turing Machine Simulator

### Author Information
- **Author:** Javier Garcia Santana
- **Date:** 29/10/2024
- **Email:** alu0101391663@ull.edu.es
- **Version:** 4.0
- **Subject:** Computational Complexity
- **Practice No.:** 3

---

## Overview
This project is a C++ implementation of a **Simultaneous Turing Machine Simulator** that simulates a Turing Machine capable of recognizing a specific language. The simulator includes classes to represent the basic components of a Turing Machine: `Symbol`, `Alphabet`, `State`, `Transition`, `Tape`, and the main machine, `SimultaneousTuringMachine`. This simulator reads configuration data from an external file, executes based on transitions, and provides visual output.

## Project Structure
The simulator is organized into header files and source files as follows:

- **`library.h`**: Contains foundational classes including:
  - `Symbol`: Represents individual symbols used in transitions.
  - `Alphabet`: Manages the input and tape symbols, including the blank symbol.
  - `State`: Represents each Turing Machine state, with acceptance checks.
  - `Transition`: Describes individual machine transitions.
  
- **`tape.h`**: Defines the `Tape` class, which simulates the Turing Machine’s tape, allowing for reading, writing, and moving the tape head.

- **`turing_machine.h`**: Base class `TuringMachine` is defined here as an abstract interface, allowing for different Turing Machine types.

- **`simultaneous_turing_machine.h`**: Contains the `SimultaneousTuringMachine` class, which inherits from `TuringMachine` and implements the actual transition-based simulation. It includes methods to load machine configurations, execute operations, and interact with the tape.

- **`turing_machine_main.cc`**: The main program file that initializes the Turing Machine, loads configurations, processes input, and runs the simulation.

## Compilation Instructions
To compile the project, use the `make` command or the following `g++` command:
```bash
make
# OR
g++ -std=c++11 -o turing turing_machine_main.cc
```

## Usage

### Step 1: Prepare a Configuration File
Create a configuration file that defines:
- **States**: List of states.
- **Input Alphabet**: Symbols the machine can read.
- **Tape Alphabet**: Symbols the machine can write.
- **Initial State**: The starting state of the machine.
- **Blank Symbol**: The symbol representing blank spaces on the tape.
- **Final State**: The accepting state of the machine.
- **Transitions**: Each transition, defined as `(CurrentState, ReadSymbol, NextState, WriteSymbol, Movement)`.

Example configuration file format:
```bash
# Example Configuration
# States
q0 q1 q2
# Input Alphabet
0 1
# Tape Alphabet
0 1 .
# Initial State
q0
# Blank Symbol
.
# Final State
q2
# Transitions
q0 0 q1 0 R
q0 1 q0 1 R
q1 0 q0 0 R
q1 1 q1 1 R
q1 . q2 . R
```
## Step 2: Run the Simulator
Once your configuration file is ready, run the compiled binary and specify the path to your configuration file along with the input string:

```bash
./turing <text_file_with_the_machine>
```
