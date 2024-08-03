// The first two lines use the '#include' preprocessor directive, which behaves
// as if the lines were replaced with the contents of the specified files

// Including these 'headers' gives access to functions declared in those headers
// 'puts' is declared in '<stdio.h>' and the 'EXIT_SUCCESS' macro is defined in
// '<stdlib.h>'

#include <stdio.h>
#include <stdlib.h>

// 'void' within the parameters of 'main' indicates that the program does not
// take any arguments. 'main' is defined to return an 'int' value (signed
// integer type)
//
// This is the main entry point of the program, either in a freestanding or
// hosted environment

int main(void) {
  // The 'puts' function writes a string argument to the 'stdout' (standard
  // output)
  // Also appends a newline character '\n' at the end of the argument
  // The "Hello, World" argument is a string literal which behaves like a
  // read-only string
  // The return value from 'puts' is an int value. On failure,
  // it returns the macro 'EOF' (A negative integer value), or a nonnegative
  // integer

  if (puts("Hello, World") == EOF) {
    // Expands to a nonzero value
    return EXIT_FAILURE;
  }

  // Used to print formatted output. The format string '%s\n' instructs the
  // function to read the second argument as a string literal and print it to
  // stdout with a new line after the string
  //
  // "Take care not to pass user-supplied data as part of the first argument to
  // the printf function, because doing so can result in a formatted output
  // security vulnerability (Seacord 2013)"
  //
  // 'printf' will return the number of characters printed if successful or a
  // negative value if an error occurred
  if (printf("%s\n", "Hello World") < 0) {
    return EXIT_FAILURE;
  }

  // 'EXIT_SUCCESS' is an object-like macro that commonly expands to the value 0
  // Each occurrence of this macro is replaced by a 0
  return EXIT_SUCCESS;
}
