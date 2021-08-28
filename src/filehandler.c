/**
 * Created by Daniel Omiya on 27/08/21.
 */

#include "filehandler.h"
#include "person.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct person *readPersonRecord(FILE *fp) {
  char lineBuffer[BUFFER_SIZE], nameBuffer[BUFFER_SIZE];
  struct person *person = NULL;
  int age;
  float height;

  if (fgets(lineBuffer, BUFFER_SIZE, fp)) {
    sscanf(lineBuffer, "%[^\n]", nameBuffer);

    fgets(lineBuffer, BUFFER_SIZE, fp);
    sscanf(lineBuffer, "%d", &age);

    fgets(lineBuffer, BUFFER_SIZE, fp);
    sscanf(lineBuffer, "%f", &height);

    person = malloc(sizeof(struct person));
    makePerson(person, nameBuffer, age, height);
  }

  return person;
}

void readPeople(const char *path, int max, struct person *people[], int *out) {
  FILE *fp;
  struct person *person;
  int currentRecord;

  fp = fopen(path, "r");

  if (fp == NULL)
    exit(INTERNAL_ERROR);

  currentRecord = 0;
  while (currentRecord < max) {
    person = readPersonRecord(fp);

    if (person == NULL)
      break;

    people[currentRecord++] = person;
  }
  fclose(fp);

  *out = currentRecord;
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

int fileExists(const char *path) {
  FILE *fp;
  fp = fopen(path, "r");
  if (fp == NULL)
    return FALSE;
  fclose(fp);
  return TRUE;
}
