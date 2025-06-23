#include <stdio.h>
#include "io.h"
#include "raytracer.h"
#include "optics.h"

/*
 * Entry point for the command line interface.
 * The program expects an input file describing the optical system
 * and an output file to store traced results for further processing
 * or visualization by the front end.
 */
int main(int argc, char **argv)
{
    if (argc < 3) {
        fprintf(stderr, "Usage: %s <system_file> <output_file>\n", argv[0]);
        return 1;
    }

    OpticalSystem *system = load_system(argv[1]);
    if (!system) {
        fprintf(stderr, "Failed to load optical system\n");
        return 1;
    }

    /* Placeholder for creating input rays; will be replaced by actual code. */
    Ray input_rays[1];
    input_rays[0].L = 0.0;
    input_rays[0].U = 0.0;

    Ray output_rays[1];
    if (trace_rays(system, input_rays, 1, output_rays) != 0) {
        fprintf(stderr, "Ray tracing failed\n");
        free_system(system);
        return 1;
    }

    if (save_results(argv[2], output_rays, 1) != 0) {
        fprintf(stderr, "Failed to save results\n");
    }

    free_system(system);
    return 0;
}
