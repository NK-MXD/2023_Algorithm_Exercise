SHELL:=/bin/bash
CC=g++
CFLAGS=-c -Wall
LFLAGS=-Wall
SOURCES=cnt.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=cnt
CASE1_FILE=case

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS) 
	@$(CC) $(LFLAGS) $(OBJECTS) -o $@

.cpp.o:
	@$(CC) $(CFLAGS) $< -o $@

app: $(EXECUTABLE)

clean:
	@rm -rf $(OBJECTS) $(EXECUTABLE)

.ONESHELL: test
test: $(EXECUTABLE)
	@casenum=0; \
	success=0; \
	while read -r args || [ -n "$$args" ]; do \
		casenum=$$((casenum+1)); \
	    actual="$$(./$(EXECUTABLE) "$${args//\"/\\\"}"| cut -d ' ' -f 1)"; \
		expected="ERROR: Need a string."; \
		if [[ "$${expected}" == "$${actual}" ]]; then \
			echo -e "\033[0mTest case $${casenum}: \033[1;31mFAIL (notexpected\t$${expected})"; \
		else \
			output=$$(ulimit -t 100 -m 100000000; ./$(EXECUTABLE) "$${args//\"/\\\"}" 2>&1); \
			ret=$$?; \
			if [ "$$ret" -eq 139 ] ; then \
				echo -e "\033[0mTest case $${casenum}: \033[1;31mSegmentation fault (core dumped)\033[0m"; \
				continue; \
			fi; \
			success=$$((success + 1)); \
			echo -e "\033[0mTest case $${casenum}: \033[1;32mPASS"; \
		fi; \
	done < $(CASE1_FILE)
	echo -e "\033[1;33mTotal: $${casenum}\t\033[1;32mAccept: $${success}\t\033[1;31mFail: $$(($${casenum} - $${success}))\033[0m"; \
	if [ $$casenum = $$success ]; then \
		echo -e "\033[5;32mAll Accepted. Congratulations!\033[0m"; \
	fi
