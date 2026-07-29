# 0x0F. C - Variadic Functions

## Description
This project covers **Variadic Functions** in C programming. It explores how to design and use functions that accept a variable number of arguments using the macros defined in the `<stdarg.h>` library (`va_start`, `va_arg`, and `va_end`). It also reinforces the usage of the `const` type qualifier and adherence to standard coding styles like the Betty style.

## Resources
* [stdarg.h](https://wikipedia.org)
* [Variadic Functions](https://gnu.org)
* [Const Keyword](https://geeksforgeeks.org)

## Requirements
* **Allowed Editors:** `vi`, `vim`, `emacs`
* **Operating System:** Ubuntu 20.04 LTS
* **Compiler:** `gcc` using options `-Wall -Werror -Wextra -pedantic -std=gnu89`
* **Style Guide:** [Betty Style](https://github.com) (checked via `betty-style.pl` and `betty-doc.pl`)
* **Global Variables:** Not allowed.
* **Max Functions per File:** 5 functions.
* **Allowed C Standard Library Functions:** `malloc`, `free`, and `exit`. (Functions like `printf`, `puts`, `calloc`, `realloc` are forbidden unless specified otherwise).
* **Allowed Macros:** `va_start`, `va_arg`, and `va_end`.

## Header File
* **[variadic_functions.h](./variadic_functions.h):** Contains all function prototypes, necessary standard macro libraries, and include guards.

## Tasks and Files Summary

| Task | File | Description |
| --- | --- | --- |
| **0. Beauty is variable, ugliness is constant** | `0-sum_them_all.c` | A function that returns the sum of all its parameters. Returns `0` if `n == 0`. |

## Compilation & Usage
To compile the files, use the following compilation flags:
```bash
gcc -Wall -pedantic -Werror -Wextra -std=gnu89 0-main.c 0-sum_them_all.c -o a
```

To run the compiled executable:
```bash
./a
```

