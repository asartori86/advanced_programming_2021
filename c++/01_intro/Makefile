CXX = c++
CXXFLAGS = -Wall -Wextra -g -std=c++14

SRC = 01_variables.cpp            \
      02_hello_name.cpp           \
      03_loops.cpp                \
      04_vars_pointers_refs.cpp   \
      05_functions.cpp            \
      06_watch_out.cpp 

EXE = $(SRC:.cpp=.x)

# eliminate default suffixes
.SUFFIXES:
SUFFIXES =

# just consider our own suffixes
.SUFFIXES: .cpp .x

all: $(EXE)

.PHONY: all

%.x: %.cpp 
	$(CXX) $< -o $@ $(CXXFLAGS)

format: $(SRC)
	@clang-format -i $^ -verbose || echo "Please install clang-format to run this command"

.PHONY: format

clean:
	rm -f $(EXE) *~

.PHONY: clean
