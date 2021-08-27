/*
 * Created by Daniel Omiya on 27/08/21.
 */

#include "filereader.h"
#include "filewriter.h"
#include "person.h"
#include <stdio.h>
#include <stdlib.h>

#define ARR_SIZE 1024

void freeResources(struct person *people[], int n) {
  int i;
  for (i = 0; i < n; i++)
    destroyPerson(people[i]);
}

int main() {
  struct person *people[ARR_SIZE];
  const char inputPath[] = "data/in.csv", outputPath[] = "data/out.csv";
  int countPeople;

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
