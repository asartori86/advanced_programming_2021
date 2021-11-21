SRC = op_overloading.cpp         \
      find_if.cpp                

CXX = c++
CXXFLAGS = -W -Wall -Wextra -g -std=c++14

CXXFLAGS += -I ../06_error_handling  # needed by the compiler to find the header

VPATH = ../06_error_handling # needed by makefile to look for files

EXE = $(SRC:.cpp=.x)

# eliminate default suffixes
.SUFFIXES:
SUFFIXES =

# just consider our own suffixes
.SUFFIXES: .cpp .x

all: $(EXE)

.PHONY: all

%.x: %.cpp ap_error.hpp
	$(CXX) $< -o $@ $(CXXFLAGS)

format: $(SRC)
	@clang-format -i $^ -verbose || echo "Please install clang-format to run this command"

.PHONY: format

clean:
	rm -f $(EXE) *~

.PHONY: clean

