

COMMON_DIRS = utilities
COMMON_DIRS += initialization

.PHONY: all docs test

all:
	for dir in $(COMMON_DIRS); do \
	 (echo $$dir; cd $$dir; make)||exit;\
	done

test: all
	

docs:
	doxygen Doxyfile
	zip -r docs/GA_Documentation docs/latex/ docs/html/

