CC = g++
CFLAGS = -Wall -Wextra -Wpedantic -std=c++17

# Define the source files
SRCS_COMMON = src/graphs/BasicGraph.cpp \
	   		  src/graphs/AdjacencyMatrixGraph.cpp \
	   		  src/graphs/AdjacencyListGraph.cpp \
	   		  src/algorithms/EulerVisitor.cpp \
	   		  src/algorithms/HamiltonVisitor.cpp \
	   		  src/algorithms/IsomorphismVisitor.cpp

SRC_TESTS = src/tests.cpp

SRC_BENCHMARKS = src/benchmarks.cpp

OUTPUT_TESTS = tests

OUTPUT_BENCHMARKS = benchmarks

.PHONY: all clean tests benchmarks

all: tests benchmarks

tests: $(SRCS_COMMON) $(SRC_TESTS)
	$(CC) $(CFLAGS) -o $(OUTPUT_TESTS)  $(SRC_TESTS) $(SRCS_COMMON)
	@echo "Build complete. Run './$(OUTPUT_TESTS)' to execute."

benchmarks: $(SRCS_COMMON) $(SRC_BENCHMARKS)
	$(CC) $(CFLAGS) -o $(OUTPUT_BENCHMARKS) $(SRCS_COMMON) $(SRC_BENCHMARKS)
	@echo "Build complete. Run './$(OUTPUT_BENCHMARKS)' to execute." 

clean:
	rm -f $(OUTPUT_TESTS) $(OUTPUT_BENCHMARKS)
	@echo "Cleaned up the build files."
