#include <stdio.h>
#include <stdlib.h>
#include "io.h"

OpticalSystem *load_system(const char *filename)
{
    /* Placeholder implementation: real code should parse the file
     * and allocate surfaces accordingly. */
    FILE *f = fopen(filename, "r");
    if (!f) return NULL;
    fclose(f);

    OpticalSystem *sys = malloc(sizeof(*sys));
    if (!sys) return NULL;
    sys->surfaces = NULL;
    sys->count = 0;
    return sys;
}

void free_system(OpticalSystem *system)
{
    if (!system) return;
    free(system->surfaces);
    free(system);
}

int save_results(const char *filename, const Ray *rays, unsigned int count)
{
    FILE *f = fopen(filename, "w");
    if (!f) return -1;
    for (unsigned int i = 0; i < count; ++i) {
        fprintf(f, "%f %f\n", rays[i].L, rays[i].U);
    }
    fclose(f);
    return 0;
}
