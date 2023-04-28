SHELL:=/bin/bash
CC=g++
CFLAGS=-c -Wall
LFLAGS=-Wall
SOURCES=mixplus.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=mixplus
CASE1_FILE=case1
CASE2_FILE=case2

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS) 
	@$(CC) $(LFLAGS) $(OBJECTS) -o $@

.cpp.o:
	@$(CC) $(CFLAGS) $< -o $@

app: $(EXECUTABLE)

.ONESHELL: test
test: $(EXECUTABLE)
	@success=0; \
	casenum=0; \
	args=($(shell cat $(CASE1_FILE))); \
	for i in $${!args[@]}; do \
		if ((i % 2 == 0)); then \
			casenum=$$((casenum + 1)); \
			arg1="$${args[$$i]}"; \
			arg2="$${args[$$((i+1))]}"; \
			if [[ "$${arg1}" == "0x"* ]]; then \
				arg1="$$(printf '%ld' "$${arg1}" 2>/dev/null || echo 0)"; \
			fi; \
			if [[ "$${arg2}" == "0x"* ]]; then \
				arg2="$$(printf '%ld' "$${arg2}" 2>/dev/null || echo 0)"; \
			fi; \
			expected="$$(printf '%ld\n' "$$((arg1 + arg2))")"; \
			actual="$$(./$(EXECUTABLE) "$${args[$$i]}" "$${args[$$((i+1))]}" | cut -d ' ' -f 2)"; \
			if [[ "$${expected}" == "$${actual}" ]]; then \
				success=$$((success + 1)); \
				echo -e "\033[0mTest case $$(($$i/2+1)): \033[1;32mPASS"; \
			else \
				echo -e "\033[0mTest case $$(($$i/2+1)): \033[1;31mFAIL arg1\t$${args[$$i]}\targ2\t$${args[$$((i+1))]}\t(expected\t$${expected}\tactual\t$${actual})"; \
			fi; \
		fi; \
	done
	@args=($$(cat $(CASE2_FILE))); \
	for i in $${!args[@]}; do \
		if ((i % 2 == 0)); then \
			casenum=$$((casenum + 1)); \
			expected="ERROR"; \
			actual="$$(./$(EXECUTABLE) "$${args[$$i]}" "$${args[$$((i+1))]}" | cut -d ' ' -f 2)"; \
			if [[ "$${expected}" == "$${actual}" ]]; then \
				success=$$((success + 1)); \
				echo -e "\033[0mTest case $$(($$i/2+501)): \033[1;32mPASS"; \
			else \
				echo -e "\033[0mTest case $$(($$i/2+501)): \033[1;31mFAIL (expected\t$${expected}\tactual\t$${actual})"; \
			fi; \
		fi; \
	done
	echo -e "\033[1;33mTotal: $${casenum}\t\033[1;32mAccept: $${success}\t\033[1;31mFail: $$(($${casenum} - $${success}))\033[0m"; \
	if [ $$casenum = $$success ]; then \
		echo -e "\033[5;32mAll Accepted. Congratulations!\033[0m"; \
	fi

clean:
	@rm -rf $(OBJECTS) $(EXECUTABLE)
