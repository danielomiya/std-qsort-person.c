/**
 * Created by Daniel Omiya on 27/08/21.
 */

#include "person.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void makePerson(struct person *person, const char *name, int age, float height) {
  int nameLength = strlen(name) + 1;

  person->name = malloc(nameLength * sizeof(char));
  strcpy(person->name, name);

  person->age = age;
  person->height = height;
}

void destroyPerson(struct person *person) {
  free(person->name);
  free(person);
}

int comparePerson(const struct person **a, const struct person **b) {
  int aHeight = (*a)->height * 100;
  int bHeight = (*b)->height * 100;
  return aHeight - bHeight;
}

void stringifyPerson(const struct person *person, char *out) {
  sprintf(out, "%s\n%d\n%.2f", person->name, person->age, person->height);
}
