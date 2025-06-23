#include <stdio.h>
#include <stdlib.h>
#include "io.h"

OpticalSystem *load_system(const char *filename)
{
    FILE *f = fopen(filename, "r");
    if (!f)
        return NULL;

    unsigned int count;
    if (fscanf(f, "%u", &count) != 1) {
        fclose(f);
        return NULL;
    }

    OpticalSystem *sys = malloc(sizeof(*sys));
    if (!sys) {
        fclose(f);
        return NULL;
    }

    sys->surfaces = malloc(sizeof(Surface) * count);
    if (!sys->surfaces) {
        free(sys);
        fclose(f);
        return NULL;
    }
    sys->count = count;

    for (unsigned int i = 0; i < count; ++i) {
        Surface *s = &sys->surfaces[i];
        if (fscanf(f, "%lf %lf %lf %lf", &s->r, &s->n1, &s->n2, &s->d) != 4) {
            free_system(sys);
            fclose(f);
            return NULL;
        }
    }

    fclose(f);
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
    if (!f)
        return -1;

    fprintf(f, "[\n");
    for (unsigned int i = 0; i < count; ++i) {
        fprintf(f, "  {\"L\": %.6f, \"U\": %.6f}%s\n",
                rays[i].L, rays[i].U,
                (i + 1 < count) ? "," : "");
    }
    fprintf(f, "]\n");
    fclose(f);
    return 0;
}
