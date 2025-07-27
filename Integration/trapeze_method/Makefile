MAKEFLAGS += --no-print-directory

GXX = g++

INPUT_FILES_CPP = *.cpp ../tests/trapeze_test.cpp ../general_funcs/*.cpp
OUTPUT_FILE_BIN = main_trapeze.out
OUTPUT_TEST_FILE = trapeze_test_result.txt

.PHONY: all run test clean

all:
	@$(GXX) $(INPUT_FILES_CPP) -o $(OUTPUT_FILE_BIN) && \
	printf "\n ===== Compilation completed successfully ===== \n\n"

run:
	@./$(OUTPUT_FILE_BIN) ${EPS}

test:
	@./$(OUTPUT_FILE_BIN) ${EPS} > ../tests/$(OUTPUT_TEST_FILE)

clean:
	@rm -rf *.out