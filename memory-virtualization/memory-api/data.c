#include <stdlib.h>

int main(int argc, char *argv[]) {
  int *data = (int *) malloc(100 * sizeof(int));

  data[20] = 25;

  free(data[50]);

  printf("This is the value of the 20th index: %d\n", data[20]);
}

