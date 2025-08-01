.PHONY: all run

INPUT_FILES_CPP = ../general/sub_funcs.cpp ../euler_method/euler.cpp ../equation_system/equation_system.cpp
OUTPUT_FILE = SEIRD.out
GXX = g++
all:
	@$(GXX) SEIR-D.cpp $(INPUT_FILES_CPP) -g -o $(OUTPUT_FILE)

run:
	@./$(OUTPUT_FILE)