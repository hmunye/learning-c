#include <stdio.h>

// Function declarations (not definitions)
int addition(int, int);
void swap(int *, int *);

int main(void) {
  // Objects are storage in which you can represent values
  // Variables are examples of objects

  // Variables have a declared types, values bound to them, and assigned names
  // or 'identifiers'
  int x = 5;
  int y = 10;

  printf("%d\n", addition(x, y));

  printf("Before swap: x = %d, y = %d\n", x, y);
  swap(&x, &y);
  printf("After swap: x = %d, y = %d\n", x, y);
}

// Functions are not objects but do have types
// They are characterized by both the return type as well as the number and
// types of it's arguments
int addition(int x, int y) {
  static unsigned int value = 4;

  return value + x + y;
}

void swap(int *px, int *py) {
  // Pointers hold addresses, a location in memory where an object or funtion is
  // stored
  int temp = *px;
  *px = *py;
  *py = temp;

  return;
}
