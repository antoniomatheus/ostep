#include <stdlib.h>

int main(int argc, char *argv[]) {
  int *x = (int *) malloc(sizeof (int));

  printf("This is the variable: %d", x);
}
