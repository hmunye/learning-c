#include <stdbool.h>
#include <stdio.h>

// Function declarations (not definitions)
void addition(int, int);
void boolean(void);
void chars(void);
void nums(void);
void swap(int *, int *);
void swap_v2(int *, int *);

enum days { sun, mon, tue, wed, thu, fri, sat };

int main(void) {
  // Objects are storage in which you can represent values
  // Variables are examples of objects

  // Variables have a declared types, values bound to them, and assigned names
  // or 'identifiers'
  int x = 5;
  int y = 10;

  printf("Before swap: x = %d, y = %d\n", x, y);
  swap_v2(&x, &y);
  printf("After swap: x = %d, y = %d\n", x, y);

  for (int i = 0; i < 5; i++) {
    addition(x, y);
  }
}

// Functions are not objects but do have types
// They are characterized by both the return type as well as the number and
// types of it's arguments
void addition(int x, int y) {
  // Static objects must be initialized with a constant value
  static unsigned int value = 4;

  value += 1;

  printf("%d\n", value + x + y);
}

void boolean(void) {
  _Bool flag1 = 0;    // Can be 1 or 0
  bool flag2 = false; // Can be true or false
}

void chars(void) {
  signed char letter = '1';
  unsigned char letter2 = '3';
  char letter3 = 'a';
}

void nums(void) {
  signed int num = -2;
  unsigned int num2 = 4;
  int num3 = 5;

  short int num4 = 7;
  long int num5 = 0;
  long long int num6 = 94;
  long num7 = 30;
}

void swap(int *px, int *py) {
  // Pointers hold addresses, a location in memory where an object or funtion is
  // stored
  int temp = *px;
  *px = *py;
  *py = temp;

  return;
}

// Could probably be better
void swap_v2(int *px, int *py) {
  *px = *px + *py;
  *py = *px - *py;
  *px = *px - *py;

  return;
}
