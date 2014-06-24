# Top level makefile

COMMON_DIRS = utilities
COMMON_DIRS += initialization
COMMON_DIRS += roulette

SOURCE_DIRS = initialization

ARTIFACT_DIRS = logs
ARTIFACT_DIRS += docs


.PHONY: all docs test analysis clean

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

analysis: clean
	for dir in $(SOURCE_DIRS); do \
	(mkdir logs/$$dir; cppcheck --enable=warning,information --check-config --suppress=missingIncludeSystem -Iutilities -I$$dir $$dir > logs/$$dir/cppcheck_results.txt)||exit;\
	done
	
clean: 
	for dir in $(COMMON_DIRS); do \
	 (echo $$dir; cd $$dir; make clean)||exit;\
	done
	
	for dir in $(ARTIFACT_DIRS); do \
	 (echo $$dir; cd $$dir; make clean)||exit;\
	done
	
