/**
 * Created by Daniel Omiya on 27/08/21.
 */

#ifndef PERSON_H
#define PERSON_H

struct person {
  char *name;
  int age;
  float height;
};

void makePerson(struct person *person, const char *name, int age, float height);
void destroyPerson(struct person *person);
int comparePerson(const struct person **a, const struct person **b);
void stringifyPerson(const struct person *person, char *out);

#endif /* PERSON_H */
