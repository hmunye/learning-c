#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef unsigned int u_int;

// Function declarations (not definitions)
void increment(void);
u_int retrieve(void);
void boolean(void);
void chars(void);
void nums(void);
void swap(int *px, int *py);
void swap_v2(int *px, int *py);
void choose_func(void);

struct sigrecord {
  int signum;
  char signame[20];
  char sigdesc[100];
} sigline, *sigline_p;

union {
  struct {
    int type;
  } node;
  struct {
    int type;
    int num;
  } node_i;
  struct {
    int type;
    float num;
  } node_f;
} node_union;

// Used to create symbolic names for integer values
// Here, since we don't specify a value to the first enumerator with '=',
// the value of it's enumeration constant is 0 and each subsequent enumerator
// without adds 1 to the previous value
// sun = 0, mon = 1, etc.
enum days { sun, mon, tue, wed, thu, fri, sat };

// Objects declared with 'const' are not modifiable
const int i = 0;

// Using 'volatile' tells the compiler that the value may change, and that every
// access to the volatile object occurs
volatile int port = 3030;

// This function copies n bytes from storage referenced by q to storage
// referenced by p
// Both p and q are 'restrict' pointers, meaning the compiler
// can assume that an object accessed through one of the pointer parameters is
// not also accessed through the other.
void f(u_int n, int *restrict p, int *restrict q) {
  while (n-- > 0) {
    *p++ = *q++;
  }
}

int main(void) {
  // Objects are storage in which you can represent values
  // Variables are examples of objects

  // Variables have a declared types, values bound to them, and assigned names
  // or 'identifiers'
  int x = 5;
  int y = 10;
  char a = 'a';

  void *vp;

  sigline.signum = 5;
  strcpy(sigline.signame, "SIGINT");
  strcpy(sigline.sigdesc, "Interrupt from keyboard");

  sigline_p = &sigline;

  //  sigline_p->signum = 6;
  //  strcpy(sigline_p->signame, "SIGINT");
  //  strcpy(sigline_p->sigdesc, "Interrupt from keyboard");

  printf("Sigline 1: %d, %s, %s\n", sigline.signum, sigline.signame,
         sigline.sigdesc);

  printf("Sigline pointer: %d, %s, %s\n", sigline_p->signum, sigline_p->signame,
         sigline_p->sigdesc);

  int array[11] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  int size = sizeof(array) / sizeof(*array);

  printf("Array: [");

  for (u_int i = 0; i <= size - 1; i++) {
    if (i == size - 1) {
      printf("%d", array[i]);
      break;
    }
    printf("%d, ", array[i]);
  }

  printf("]\n");

  printf("Before swap: x = %d, y = %d\n", x, y);
  swap_v2(&x, &y);
  printf("After swap: x = %d, y = %d\n", x, y);

  enum days today;
  today = wed;

  switch (today) {
  case wed:
    printf("Today is wednesday\n");
    break;
  default:
    printf("Today is not wednesday\n");
    break;
  }

  increment();
  increment();
  increment();

  printf("Value of counter: %d\n", retrieve());

  choose_func();
}

static u_int global_counter = 0;

// Functions are not objects but do have types
// They are characterized by both the return type as well as the number and
// types of it's arguments
void increment(void) {
  // Static objects must be initialized with a constant value
  static u_int counter = 0;

  counter++;
  global_counter = counter;

  printf("%d ", counter);
}

u_int retrieve(void) { return global_counter; }

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
  u_int num2 = 4;
  int num3 = 5;

  short int num4 = 7;
  long int num5 = 0;
  long long int num6 = 94;
  long num7 = 30;

  float num8 = 8.8;
  double num9 = 102.34;
  long double num10 = 129233.133;
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

typedef union {
  void (*increment)(void);
  u_int (*retrieve)(void);
  int (*main)(void);
} func_union;

typedef enum { INCREMENT, RETRIEVE, MAIN } func_type;

typedef struct {
  func_union func_ptr;
  func_type type;
} func_pointer;

void choose_func(void) {
  func_pointer functions[3];

  functions[INCREMENT].func_ptr.increment = increment;
  functions[RETRIEVE].func_ptr.retrieve = retrieve;
  functions[MAIN].func_ptr.main = main;

  while (true) {
    puts("\nWhich function would you like to run:\n[1] - increment\n[2] - "
         "retrieve\n[3] - main\n[4] - exit");

    int func_choice;

    scanf("%d", &func_choice);

    switch (func_choice) {
    case 1:
      printf("Function result: ");
      functions[INCREMENT].func_ptr.increment();
      printf("\n");
      break;
    case 2:
      printf("Function Result: %d\n", functions[RETRIEVE].func_ptr.retrieve());
      printf("\n");
      break;
    case 3:
      printf("\n");
      functions[MAIN].func_ptr.main();
      break;
    case 4:
      puts("Program exited successfully");
      exit(0);
    default:
      printf("Invalid function choice");
      break;
    }
  }
}
