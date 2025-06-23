# Project Structure

This repository contains a teaching-oriented ray tracing framework for
spherical lenses.  The code is organised into two major parts:

- **backend** – C sources for calculating ray paths and optical aberrations.
- **frontend** – placeholder directory for future visualisation code.

```
.
├── backend
│   ├── include       # Public headers
│   ├── src           # Implementation files
│   └── Makefile      # Builds the `raytracer` executable
├── frontend          # Future UI implementation
├── docs              # Additional documentation
└── Makefile          # Top-level build entry
```

## Backend Overview

The backend exposes a simple command line interface:

```
./raytracer <system_file> <output_file>
```

`<system_file>` describes the optical system, while `<output_file>` will
receive the traced rays.  The format of these files is to be defined.

### Key Source Files

- `src/main.c` – program entry point and example of how modules interact.
- `src/io.c` – loading/saving of optical systems and trace results.
- `src/raytracer.c` – performs ray tracing through a system.
- `src/optics.c` – placeholder for aberration calculations.

Header files under `include/` declare the data structures and functions
used across modules.  The real ray tracing and aberration calculations
remain to be implemented.

## Building

Run `make` in the repository root to compile the backend.  The resulting
binary `raytracer` will be placed in the `backend` directory.

## Notes for Frontend Integration

The backend saves results to a text file, which can be read by a UI
application for visualisation.  The exact data exchange format can be
extended (e.g. JSON) when the frontend is developed.
