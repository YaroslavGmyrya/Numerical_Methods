MAKEFLAGS += --no-print-directory

GXX = g++

INPUT_FILES_CPP = *.cpp ../tests/*.cpp
OUTPUT_FILE_BIN = main_rect.out
OUTPUT_TEST_FILE = rect_test_result.txt

.PHONY: all run test clean

all:
	@$(GXX) $(INPUT_FILES_CPP) -o $(OUTPUT_FILE_BIN) && \
	printf "\n ===== Compilation completed successfully ===== \n\n"

run:
	./$(OUTPUT_FILE_BIN) ${EPS}

test:
	@cd tests && \
	./$(OUTPUT_FILE_BIN) ${EPS} > $(OUTPUT_TEST_FILE)

clean:
	@cd tests && \
	rm -rf *.out

graph:
	@cd tests && \
	python3 graph.py $(OUTPUT_TEST_FILE)