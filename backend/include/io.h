#ifndef IO_H
#define IO_H

#include "types.h"

/* Load an optical system from a text file.
 * The file format is user defined. This function is a placeholder
 * for future implementation.
 */
OpticalSystem *load_system(const char *filename);

/* Free an optical system previously loaded. */
void free_system(OpticalSystem *system);

/*
 * Save computed trace results to a JSON file for consumption by the
 * front-end. Each ray is written as an object containing its L and U
 * values.
 */
int save_results(const char *filename, const Ray *rays, unsigned int count);

#endif /* IO_H */
