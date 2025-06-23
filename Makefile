.PHONY: all clean frontend start

all:
	$(MAKE) -C backend

# Install front-end dependencies
frontend:
	cd frontend && npm install

# Launch the Node.js server after building the backend
start: all frontend
	node frontend/server.js

clean:
	$(MAKE) -C backend clean
