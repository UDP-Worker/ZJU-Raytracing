#ifndef TYPES_H
#define TYPES_H

/*
 * Data structures used in the ray tracing backend.
 * All units are assumed to be consistent (e.g. millimeters).
 */

/* Representation of a light ray in (L, U) form.
 * L - height or position; U - slope or angle.
 */
typedef struct {
    double L;
    double U;
} Ray;

/* Refractive surface parameters for a spherical lens.
 * r - radius of curvature.
 * n1, n2 - refractive indices before and after the surface.
 * d - distance to next surface (thickness). 0 for last surface.
 */
typedef struct {
    double r;
    double n1;
    double n2;
    double d;
} Surface;

/* Optical system consisting of multiple spherical surfaces. */
typedef struct {
    Surface *surfaces;
    unsigned int count; /* number of surfaces */
} OpticalSystem;

/* Container for computed results. Actual fields to be filled by algorithms. */
typedef struct {
    /* Placeholder for various computed aberrations and coordinates. */
    double placeholder;
} TraceResult;

#endif /* TYPES_H */
