#include <stddef.h>
#include "raytracer.h"

/*
 * Placeholder ray tracing routine. A real implementation would
 * apply Snell's law and paraxial approximations as required
 * by the teaching specification.
 */
int trace_rays(const OpticalSystem *system, const Ray *input,
               unsigned int ray_count, Ray *results)
{
    if (!system || !results || !input)
        return -1;

    for (unsigned int i = 0; i < ray_count; ++i) {
        /* Simple copy for now; replace with actual tracing algorithm. */
        results[i] = input[i];
    }

    return 0;
}
