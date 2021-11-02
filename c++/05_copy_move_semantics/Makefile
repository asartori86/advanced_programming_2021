SRC = 01_surprise.cpp      \
      02_default.cpp       \
      03_default.cpp       \
      04_buggy_vector.cpp  \
      05_buggy_vector.cpp  \
      06_copy_move.cpp     \
      07_explicit.cpp

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

01_surprise.x: CXXFLAGS += -Wno-uninitialized
07_explicit.x: CXXFLAGS += -Wno-unused-parameter

