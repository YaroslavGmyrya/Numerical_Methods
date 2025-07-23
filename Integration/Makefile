MAKEFLAGS += --no-print-directory

GXX = g++

PATHS_TO_METHOD = rect_metho
INPUT_FILES_CPP = main.cpp sub_funcs.cpp $(PATHS_TO_METHOD)
OUTPUT_FILE_BIN = main.out
OUTPUT_TEST_FILE = test_result.txt

.PHONY: all run test clean

all:
	@ $(MAKE) -C rect_methods
	
run rect:
	@cd rect_methods && \
	./main_rect.out ${EPS}

test:
	@cd tests && \
	./$(OUTPUT_FILE_BIN) ${EPS} > $(OUTPUT_TEST_FILE)

clean:
	@cd tests && \
	rm -rf *.out

graph:
	@cd tests && \
	python3 graph.py $(OUTPUT_TEST_FILE)