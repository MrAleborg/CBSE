# If the CECILIA_ROOT variable is defined, look for 'ceciliac' in this directory
# otherwise, expect that 'ceciliac' is in the PATH.
ifdef CECILIA_ROOT
  # If CECILIA_ROOT contains '\', replace them by '/' (for Windows)
  CECILIAC = $(subst \,/, $(CECILIA_ROOT)/bin/ceciliac)
else 
  CECILIAC = ceciliac
endif

all: foodsterilizer

# START SNIPPET: foodsterilizer-rule
foodsterilizer: build/foodsterilizer
	$(CECILIAC) -src-path=src -o=build/foodsterilizer -t=unix \
	  foodsterilizer.FoodSterilizer:foodsterilizer
# END SNIPPET: foodsterilizer-rule

build/foodsterilizer:
	mkdir -p build/foodsterilizer

clean:
	rm -Rf build

.PHONY: all foodsterilizer clean
