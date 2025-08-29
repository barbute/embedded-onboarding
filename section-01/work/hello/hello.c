#include <stdio.h>
#include <stdlib.h>

void FizzBuzz(int n); // <- Declaration (so compiler stops complaining)

// NOTE argv[0] contains the name of the program, first arg passed in on CLI 
// is argv[1]
int main(int argc, char *argv[]) {
  printf("Hello, world!\n");

  // Length of array must be declare explicitly, cannot use 
  // sizeof(arr)/sizeof(type) since sizeof() only knows compile-time sizes. 
  // TLDR sizeof() does not work for malloc'ed arrays. Thus the length must be 
  // tracked in a separate variable
  int n = 20;
  int* arr = (int*) malloc(n * sizeof(int));

  // Populate arr with numbers 1 - 20
  for (int i = 0; i < n; i++) {
    // PERSONAL NOTE: arr[i] = *(arr + i)

    arr[i] = i + 1; // Add one cause we start at index 0 but want first number 
                    // to start at 1
  }

  // Run FizzBuzz on whole array
  for (int i = 0; i < n; i++) {
    printf("ARRAY %i: ", arr[i]);
    FizzBuzz(arr[i]);
    printf("\n");
  };

  // Run FizzBuzz on 1 - 30
  for (int i = 1; i <= 30; i++) {
    printf("1-30 %i: ", i);
    FizzBuzz(i);
    printf("\n");
  }

  free(arr);

  return 0;
}

void FizzBuzz(int n) {
  if (n % 3 == 0) {
    printf("Fizz");
  }
  if (n % 5 == 0) {
    printf("Buzz");
  }
}