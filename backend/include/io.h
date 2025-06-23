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

/* Save computed trace results to a text file or JSON for front-end use. */
int save_results(const char *filename, const Ray *rays, unsigned int count);

#endif /* IO_H */
