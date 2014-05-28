# Top level makefile

COMMON_DIRS = utilities
COMMON_DIRS += initialization

.PHONY: all docs test

all:
	for dir in $(COMMON_DIRS); do \
	 (echo $$dir; cd $$dir; make)||exit;\
	done

test:
	for dir in $(COMMON_DIRS); do \
	 (echo $$dir; cd $$dir; make test)||exit;\
	done
	

docs:
	doxygen Doxyfile
	zip -r docs/GA_Documentation docs/latex/ docs/html/

clean: 
	for dir in $(COMMON_DIRS); do \
	 (echo $$dir; cd $$dir; make clean)||exit;\
	done
