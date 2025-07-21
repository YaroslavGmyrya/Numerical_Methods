MAKEFLAGS += --no-print-directory

GXX = g++
PATHS_TO_METHOD = Newton_interpolation/newton_interpolation.cpp
PATHS_TO_TESTS = tests/chebyshev_coefficient.cpp tests/uniform_step.cpp
INPUT_FILES_CPP = main.cpp sub_funcs.cpp $(PATHS_TO_METHOD) $(PATHS_TO_TESTS)
OUTPUT_FILE_BIN = main.out
OUTPUT_TEST_FILE = test_result.txt

.PHONY: all run test clean graph

all:
	@$(GXX) $(INPUT_FILES_CPP) -o $(OUTPUT_FILE_BIN) && \
	printf "\n ===== Compilation completed successfully ===== \n\n"

run:
	@./$(OUTPUT_FILE_BIN)

test:
	@./$(OUTPUT_FILE_BIN) > tests/$(OUTPUT_TEST_FILE)

clean:
	@rm -rf *.out && \
	cd tests && \
	rm -rf *.png

graph:
	@cd tests && \
 	python3 graph.py $(OUTPUT_TEST_FILE)