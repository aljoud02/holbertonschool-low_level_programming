# Simple Calculator

A small, complete, menu-driven C program that performs basic arithmetic operations based on user input.

## Compile Command

```bash
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 calculator.c -o calculator
```

## Run Instructions

```bash
./calculator
```

## Supported Operations

* **1) Add**: Computes $A + B$.
* **2) Subtract**: Computes $A - B$.
* **3) Multiply**: Computes $A \times b$.
* **4) Divide**: Computes $A / b$. Includes validation to prevent division by zero.
* **0) Quit**: Exits the program.

## Numeric Behavior

* **Operands**: The program reads inputs `A` and `B` strictly as integers (`int`).
* **Results**: Addition, subtraction, and multiplication return integer values. Division returns a decimal value (`double`) to ensure precise calculation (e.g., $10 / 4 = 2.5$).

## Known Limitations

* **Non-Numeric Input**: Entering non-numeric data (like characters or words) will cause unexpected behavior or infinite loops as advanced input validation is out of scope.

