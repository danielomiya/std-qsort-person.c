/**
 * Created by Daniel Omiya on 27/08/21.
 */

#ifndef FILEREADER_H
#define FILEREADER_H

#include "person.h"

#if !defined(BUFFER_SIZE)
#define BUFFER_SIZE 512
#endif

#if !defined(INTERNAL_ERROR)
#define INTERNAL_ERROR 500
#endif

void readPeople(const char *path, int n, struct person *people[], int *out);

#endif /* FILEREADER_H */
