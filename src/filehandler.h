/**
 * Created by Daniel Omiya on 27/08/21.
 */

#ifndef FILEHANDLER_H
#define FILEHANDLER_H

#include "person.h"

#if !defined(BUFFER_SIZE)
#define BUFFER_SIZE 512
#endif

#if !defined(INTERNAL_ERROR)
#define INTERNAL_ERROR 500
#endif

#ifndef TRUE
#define TRUE (1 == 1)
#endif

#ifndef FALSE
#define FALSE (!TRUE)
#endif

void readPeople(const char *path, int n, struct person *people[], int *out);
void writePeople(const char *path, int n, struct person *people[]);
int fileExists(const char *path);

#endif /* FILEHANDLER_H */
