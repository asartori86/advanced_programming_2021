SRC = 00_first_trial.cpp         \
      01_inheritance.cpp         \
      02_virtual.cpp             \
      03_virtual_destructor.cpp  \
      04_private.cpp             \
      05_dynamic_cast.cpp        \
      06_template.cpp            \
      07_using.cpp


CXX = c++
CXXFLAGS = -W -Wall -Wextra -g -std=c++11

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
	+$(MAKE) $@ -C organized

.PHONY: format

clean:
	rm -f $(EXE) *~
	+$(MAKE) $@ -C organized

.PHONY: clean

