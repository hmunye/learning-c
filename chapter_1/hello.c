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

int main(void) {
  // The 'puts' function writes a string argument to the 'stdout' (standard
  // output)
  // Also appends a newline character '\n' at the end of the argument
  // The return value from 'puts' is an int value. On failure, it returns
  // the macro 'EOF' (A negative int value)

  if (puts("Hello, World") == EOF) {
    // Evaluates to a nonzero value
    return EXIT_FAILURE;
  }

  // Used to print formatted output. The format string '%s\n' instructs the
  // function to read the second argument as a string literal and print it to
  // stdout with a new line after the string
  //
  // 'printf' will return the number of charaters printed if successful or a
  // negative value if an error occured
  (void) printf("%s\n", "Hello World");

  // 'EXIT_SUCCESS' commonly expands to the value 0
  return EXIT_SUCCESS;
}
