# my_printf Documentation

## Supported Types

`my_printf` supports the following format specifiers:

- **`%d`**: Integers  
- **`%s`**: Strings  
- **`%c`**: Characters  
- **`%x`**: Hexadecimal (lowercase)  
- **`%X`**: Hexadecimal (uppercase)  

## Supported Modifiers

`my_printf` also supports the following modifiers:

- **Left Alignment (`-`)**: Prints `0`s or spaces **after** the value.  
- **Right Alignment**: Prints `0`s or spaces **before** the value.  
- **Width**: Determines the total width printed (including value length and modifiers).  
  - If the width is larger than the value's length, nothing is truncated.  
- **Space (` `)**: Prints a space before a positive integer.  
- **Precision (`.`)**:  
  - For strings: Trims the string to the specified length.  
  - For digits: Pads with `0`s to meet the precision length.  
- **Plus Sign (`+`)**: Adds a `+` before positive integers.  
- **Zero Padding (`0`)**: Pads with `0`s instead of spaces to match the width.  
- **Star (`*`)**: Uses the next argument as width or precision.  
- **Long (`l`)**: Supports long integers.  
- **Short (`h`)**: Supports short integers.  
- **Percent (`%%`)**: Prints a `%` character and continues normal formatting.  

## Creative Additions

`my_printf` includes three additional format specifiers:

- **`%b`**: Prints an integer as a binary number.  
  - Negative numbers are printed as unsigned integers.  
- **`%!`**: Converts an integer to its **two’s complement** value and prints it.  
- **`%f`**: Requires two arguments:  
  - **Integer `i`**  
  - **Integer `value`**  
  - Output format:  
    ```c
    "When i = %d, the int value is %d\n"
    ```
  - Useful for debugging loops by reducing repetitive print statements.  

## Return Value

`my_printf` returns the number of successfully printed characters.

---

## Repository Files

This repository contains the following files:

- **`my_printf.c`**: Implementation of `my_printf`.  
- **`my_printf.h`**: Header file needed for testing.  
- **`test_my_printf.c`**: Test cases for `my_printf`.  
- **`output.txt`**: Output from running tests on `my_printf.c`.  

## Running Tests

To compile and run the tests, use the following commands:

```sh
gcc -o test_runner my_printf.c test_my_printf.c
./test_runner
