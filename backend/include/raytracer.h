#ifndef RAYTRACER_H
#define RAYTRACER_H

#include "types.h"

/*
 * Perform ray tracing through the given optical system.
 *
 * Parameters:
 *   system - the optical system to trace through
 *   input   - array of input rays
 *   ray_count - number of rays in the input array
 *   results - array to store resulting rays; must have ray_count elements
 *
 * Returns 0 on success, non-zero on failure.
 */
int trace_rays(const OpticalSystem *system, const Ray *input,
               unsigned int ray_count, Ray *results);

#endif /* RAYTRACER_H */
