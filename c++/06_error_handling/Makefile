SRC = 00_errno.cpp            \
      01_exceptions.cpp       \
      02_exceptions.cpp       \
      03_error.cpp            \
      04_assert.cpp           \
      05_stack_unwinding.cpp  \
      06_smart_pointers.cpp   

CXX = c++
CXXFLAGS = -Wall -Wextra -g -std=c++11

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

03_error.x: ap_error.hpp
04_assert.x: ap_error.hpp
05_stack_unwinding.x: ap_error.hpp
06_smart_pointers.x: ap_error.hpp

format: ap_error.hpp
