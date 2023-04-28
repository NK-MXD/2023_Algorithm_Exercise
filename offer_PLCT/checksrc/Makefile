SHELL:=/bin/bash
CC=g++
CFLAGS=-c -Wall
LFLAGS=-Wall
SOURCES=check.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=check
CASE1_FILE=case

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS) 
	@$(CC) $(LFLAGS) $(OBJECTS) -o $@

.cpp.o:
	@$(CC) $(CFLAGS) $< -o $@

app: all

clean:
	@rm -rf $(OBJECTS) $(EXECUTABLE)

.ONESHELL: test
test: $(EXECUTABLE)
	@args=($(shell cat $(CASE1_FILE))); \
	casenum=0; \
	success=0; \
	for i in $${!args[@]}; do \
		if ((i % 8 == 0)); then \
			casenum=$$((casenum+1)); \
			arg1="$${args[$$i]}"; \
			arg2="$${args[$$((i+1))]}"; \
			arg3="$${args[$$((i+2))]}"; \
			arg4="$${args[$$((i+3))]}"; \
			arg5="$${args[$$((i+4))]}"; \
			arg6="$${args[$$((i+5))]}"; \
			arg7="$${args[$$((i+6))]}"; \
			arg8="$${args[$$((i+7))]}"; \
			output=$$(ulimit -t 100 -m 100000000; ./$(EXECUTABLE) "$$arg1" "$$arg2" "$$arg3" "$$arg4" "$$arg5" "$$arg6" "$$arg7" "$$arg8" 2>&1); \
			ret=$$?; \
			if [ "$$ret" -eq 139 ] ; then \
				echo -e "\033[0mTest case $$(($$i/8+1)): \033[1;31mSegmentation fault (core dumped)\033[0m"; \
				continue; \
			fi; \
			success=$$((success + 1)); \
			echo -e "\033[0mTest case $$(($$i/8+1)): \033[1;32mPASS"; \
		fi; \
	done
	echo -e "\033[1;33mTotal: $${casenum}\t\033[1;32mAccept: $${success}\t\033[1;31mFail: $$(($${casenum}-$${success}))\033[0m"; \
	if [ $$casenum = $$success ]; then \
		echo -e "\033[5;32mAll Accepted. Congratulations!\033[0m"; \
	fi
