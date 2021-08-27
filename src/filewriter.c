/**
 * Created by Daniel Omiya on 27/08/21.
 */

#include "filewriter.h"
#include <stdio.h>
#include <stdlib.h>

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
    sprintf(buffer, "%s,%d,%.2f", person->name, person->age, person->height);
    fputs(buffer, fp);
    fputc('\n', fp);
  }
  fclose(fp);
}
