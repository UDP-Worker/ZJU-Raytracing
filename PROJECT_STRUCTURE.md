# Project Structure

This repository contains a teaching-oriented ray tracing framework for
spherical lenses.  The code is organised into two major parts:

- **backend** – C sources for calculating ray paths and optical aberrations.
- **frontend** – Node.js based server and static assets providing a simple
  browser UI to display ray tracing results.

```
.
├── backend
│   ├── include       # Public headers
│   ├── src           # Implementation files
│   └── Makefile      # Builds the `raytracer` executable
├── frontend          # Node.js web front-end
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

The backend now writes results in JSON format.  A small Node.js server in the
`frontend` directory runs the compiled `raytracer` on a sample optical system
and exposes the data via `/api/results`.  Static files under `frontend/public`
provide a very basic web interface that fetches and displays this data.
