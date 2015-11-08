# If the CECILIA_ROOT variable is defined, look for 'ceciliac' in this directory
# otherwise, expect that 'ceciliac' is in the PATH.
ifdef CECILIA_ROOT
  # If CECILIA_ROOT contains '\', replace them by '/' (for Windows)
  CECILIAC = $(subst \,/, $(CECILIA_ROOT)/bin/ceciliac)
else 
  CECILIAC = ceciliac
endif

all: kettle

# START SNIPPET: kettle-rule
kettle: build/kettle
	$(CECILIAC) -src-path=src -o=build/kettle -t=unix \
	  kettle.Kettle:kettle
# END SNIPPET: kettle-rule

build/kettle:
	mkdir -p build/kettle

clean:
	rm -Rf build

.PHONY: all kettle clean
