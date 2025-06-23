#include "optics.h"

int compute_aberrations(const Ray *input_rays, const Ray *output_rays,
                        unsigned int ray_count, TraceResult *result)
{
    (void)input_rays;
    (void)output_rays;
    (void)ray_count;
    if (!result)
        return -1;

    /* Placeholder: compute values according to course formulas. */
    result->placeholder = 0.0;
    return 0;
}
