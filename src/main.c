/**
 * Created by Daniel Omiya on 27/08/21.
 */

#include "filehandler.h"
#include "person.h"
#include <stdio.h>
#include <stdlib.h>

#define ARR_SIZE 1024

#define CLIENT_ERROR 400

void freeResources(struct person *people[], int n);

int main() {
  struct person *people[ARR_SIZE];
  char inputPath[BUFFER_SIZE], outputPath[BUFFER_SIZE];
  int countPeople;

  printf("Type the path to the input file: ");
  scanf("%s", inputPath);

  printf("Type the path to the output file: ");
  scanf("%s", outputPath);

  if (!fileExists(inputPath)) {
    printf("Input file could not be found\n");
    exit(CLIENT_ERROR);
  }

  printf("Reading file at %s\n", inputPath);
  readPeople(inputPath, ARR_SIZE, people, &countPeople);

  printf("Applying quicksort to %d person records\n", countPeople);
  qsort(people, countPeople, sizeof(struct person *),
        (int(*)(const void *, const void *))comparePerson);

  printf("Writing sorted output to %s\n", outputPath);
  writePeople(outputPath, countPeople, people);

  printf("Freeing used resources\n");
  freeResources(people, countPeople);

  printf("Done!\n");
  return 0;
}

void freeResources(struct person *people[], int n) {
  int i;
  for (i = 0; i < n; i++)
    destroyPerson(people[i]);
}
