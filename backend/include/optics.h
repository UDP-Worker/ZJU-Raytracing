#ifndef OPTICS_H
#define OPTICS_H

#include "types.h"

/* Compute aberrations and other metrics from traced rays.
 * The actual implementation will follow the formulas specified
 * in the teaching requirements.
 */
int compute_aberrations(const Ray *input_rays, const Ray *output_rays,
                        unsigned int ray_count, TraceResult *result);

#endif /* OPTICS_H */
