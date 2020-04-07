#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
  int memory_size = atoi(argv[1]);
  char *arr = malloc(memory_size);  
  printf("Argument given: %d\n", memory_size);
  if (memory_size <= 0) {
    return 0;
  }

  if (arr == NULL) {
    return -1;
  }

  int i = 0;
  printf("Start of loop.\n");
  while (1) {
    printf("[%d] value at %p: %c.\n", i, &arr[i], arr[i]);
    i++;
    if (i >= memory_size) {
      printf("RESETTING");
      i = 0;
    }
  }
  printf("End of loop.\n");
  free(arr);

  return 0;
}
