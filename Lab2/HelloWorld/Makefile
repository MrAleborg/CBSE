# START SNIPPET: Content
# If the CECILIA_ROOT variable is defined, look for 'ceciliac' in this directory
# otherwise, expect that 'ceciliac' is in the PATH.
ifdef CECILIA_ROOT
  # If CECILIA_ROOT contains '\', replace them by '/' (for Windows)
  CECILIAC = $(subst \,/, $(CECILIA_ROOT)/bin/ceciliac)
else 
  CECILIAC = ceciliac
endif

all: helloworld helloworld-with-counter

# START SNIPPET: helloworld-rule
helloworld: build/helloworld
	$(CECILIAC) -src-path=src -o=build/helloworld -t=unix \
	  helloworld.Helloworld:helloworld
# END SNIPPET: helloworld-rule

helloworld-with-counter: build/helloworld-with-counter
	$(CECILIAC) -src-path=src -o=build/helloworld-with-counter -t=unix \
	  helloworld.HelloworldWithCounter:helloworld-with-counter

build/helloworld:
	mkdir -p build/helloworld

build/helloworld-with-counter:
	mkdir -p build/helloworld-with-counter

clean:
	rm -Rf build

.PHONY: all helloworld helloworld-with-counter clean
