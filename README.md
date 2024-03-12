# LogicCraft Simulator: A Digital Logic Simulation Tool

## Overview

LogicCraft Simulator is a powerful digital logic simulation tool designed for educational and engineering purposes. It allows users to build and analyze the behavior of digital electronic components through a configurable graph. This simulator is capable of handling various digital components, including logic gates (AND, OR, XOR, etc.), special components like clocks, memory, and even supports undefined states beyond the basic boolean logic to more accurately mimic real digital electronics.

## Project Structure

```bash

NanoTekSpice/
|
├── build/                  # Compiled binaries and main executable
|
├── sources/                # Source files for the simulator
|   ├── components/         # Digital components (logic gates, memory, etc.)
|   ├── parser/             # Configuration file parser
|   ├── simulator/          # Simulation engine
|   └── main.cpp            # Main entry point
|
├── include/                # Header files
|   ├── components/         # Component headers
|   ├── parser/             # Parser headers
|   ├── simulator/          # Simulator headers
|   └── nanotekspice.hpp    # Main header
|
├── examples/               # Example configuration files and circuits
|
├── tests/                  # Inputs files for tests
|
├── Makefile                # Compilation script
|
└── README.md               # This file
```

## Usage

To use LogicCraft Simulator, first compile the source code using CMake and then run the simulator with a circuit configuration file as an argument.

```bash
./bin/nanotekspice examples/basic_and_gate.nts
```

### Compilation with CMake

```bash
mkdir build
cd build
cmake ..
make
```

## Example configuration for a basic AND gate circuit

.chipsets:
input a
input b
and_gate and0
output s

.links:
a:1 and0:1
b:1 and0:2
and0:3 s:1

### Output

``` bash
> a=1
> b=0
> simulate
> display
tick: 1
input(s):
a: 1
b: 0
output(s):
s: 0
```
