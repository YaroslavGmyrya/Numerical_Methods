MAKEFLAGS += --no-print-directory

GXX = g++
PATHS_TO_METHOD = ../chords_method/chords_method.cpp ../dichotomy_method/dichotomy_method.cpp ../newton_method/newton_method.cpp
INPUT_FILES_CPP = main.cpp sub_funcs.cpp $(PATHS_TO_METHOD)
OUTPUT_FILE_BIN = main.out

.PHONY: all run test clean

all:
	@cd tests && \
	$(GXX) $(INPUT_FILES_CPP) -o $(OUTPUT_FILE_BIN) && \
	printf "\n ===== Compilation completed successfully ===== \n\n"

run:
	@cd tests && \
	./$(OUTPUT_FILE_BIN) ${EPS}

test:
	@cd tests && \
	./$(OUTPUT_FILE_BIN) ${EPS} > test_result.txt

clean:
	@cd tests && \
	rm -rf *.out
