SRC = 01_auto.cpp            \
      02_auto_functions.cpp  \
      03_overloading.cpp     \
      04_templates.cpp	     \
      05_static_arrays.cpp   \
      06_dynamic_arrays.cpp  \
      07_constexpr_functions.cpp

CXX = c++
CXXFLAGS = -Wall -Wextra -g -std=c++14

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

01_auto.x : CXXFLAGS+=-Wno-unused-variable
