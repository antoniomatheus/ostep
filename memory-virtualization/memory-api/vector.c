#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
  int *vec = (int *) malloc(100 * sizeof (int));

  vec[20] = 100;

  printf("This is the value at the 20th index: %d\n", vec[20]);

  vec = realloc(vec, 150 * sizeof (int));

  printf("This is the value at the 20th index: %d\n", vec[20]);

  free(vec);
}
