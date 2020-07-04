#include <stdlib.h>
#include <stdio.h>
#include <sys/time.h>

#define PAGE_SIZE 4096
#define SECONDS_TO_MICROSECONDS_RATIO 1000000
#define MICROSECONDS_TO_NANOSECONDS 1000

int main(int argc, char *argv[]) {
  if (argc < 3) {
    printf("Usage: ./tlb [NUMBER OF PAGES] [NUMBER OF TRIALS]\n");
    exit(1);
  }

  const int NUM_OF_PAGES = atoi(argv[1]);
  const long NUM_OF_TRIALS = atoi(argv[2]);

  int *arr = (int *) malloc(NUM_OF_PAGES * PAGE_SIZE);
  if (arr == NULL) {
    printf("Unable to allocate memory for process.\n");
    exit(1);
  }

  int page_integers = PAGE_SIZE / sizeof(int);

  struct timeval start, end;
  gettimeofday(&start, NULL);

  unsigned long trial, pg;
  for (trial=0; trial < NUM_OF_TRIALS; trial++) {
    for (pg = 0; pg < page_integers * NUM_OF_PAGES; pg += page_integers) {
      arr[pg] += 5;
    }
  }

  gettimeofday(&end, NULL);

  unsigned long start_microseconds, end_microseconds, average;
  start_microseconds = start.tv_usec + start.tv_sec * SECONDS_TO_MICROSECONDS_RATIO;
  end_microseconds = end.tv_usec + end.tv_sec * SECONDS_TO_MICROSECONDS_RATIO;

  average = (end_microseconds - start_microseconds) * \
            MICROSECONDS_TO_NANOSECONDS / (NUM_OF_TRIALS * NUM_OF_PAGES);

  printf("The average time per access is: %ld nanoseconds\n", average);

  return average;
}
