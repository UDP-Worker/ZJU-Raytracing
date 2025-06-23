.PHONY: all clean frontend start dist

all:
	$(MAKE) -C backend

# Install front-end dependencies
frontend:
	cd frontend && npm install

# Launch the Node.js server after building the backend
start: all frontend
	cd frontend && npm run build
	node frontend/server.js

# Build production front-end
dist: all
		cd frontend && npm install && npm run build

clean:
	$(MAKE) -C backend clean
