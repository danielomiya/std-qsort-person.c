/**
 * Created by Daniel Omiya on 27/08/21.
 */

#include "filehandler.h"
#include "person.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void readPeople(const char *path, int max, struct person *people[], int *out) {
  FILE *fp;
  struct person *person;
  char lineBuffer[BUFFER_SIZE], nameBuffer[BUFFER_SIZE];
  int currentLine, age;
  float height;

  fp = fopen(path, "r");

  if (fp == NULL)
    exit(INTERNAL_ERROR);

  currentLine = 0;
  while (currentLine < max && fgets(lineBuffer, BUFFER_SIZE, fp)) {
    person = malloc(sizeof(struct person));
    sscanf(lineBuffer, "%[^,],%d,%f", nameBuffer, &age, &height);
    makePerson(person, nameBuffer, age, height);

    people[currentLine] = person;
    ++currentLine;
  }
  fclose(fp);

  *out = currentLine;
}

void writePeople(const char *path, int n, struct person *people[]) {
  FILE *fp;
  struct person *person;
  char buffer[BUFFER_SIZE];
  int i;

  fp = fopen(path, "w");

  if (fp == NULL)
    exit(INTERNAL_ERROR);

  for (i = 0; i < n; ++i) {
    person = people[i];
    stringifyPerson(person, buffer);
    fputs(buffer, fp);
    fputc('\n', fp);
  }
  fclose(fp);
}
