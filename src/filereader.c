/*
 * Created by Daniel Omiya on 27/08/21.
 */

#include "filereader.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void readPeople(const char *path, int max, struct person *people[], int *out) {
  FILE *f;
  struct person *person;
  char lineBuffer[BUFFER_SIZE], nameBuffer[BUFFER_SIZE];
  int currentLine, age;
  float height;

  f = fopen(path, "r");

  if (f == NULL)
    exit(INTERNAL_ERROR);

  currentLine = 0;
  while (currentLine < max && fgets(lineBuffer, BUFFER_SIZE, f)) {
    person = malloc(sizeof(struct person));
    sscanf(lineBuffer, "%[^,],%d,%f", nameBuffer, &age, &height);
    makePerson(person, nameBuffer, age, height);

    people[currentLine] = person;
    ++currentLine;
  }
  fclose(f);

  *out = currentLine;
}
