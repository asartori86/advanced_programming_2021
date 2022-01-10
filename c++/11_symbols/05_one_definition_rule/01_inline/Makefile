SRC = src1.cpp src2.cpp main.cpp
CXX = c++
CXXFLAGS = -Wall -Wextra -g -std=c++14
OBJ = $(SRC:.cpp=.o)
EXE = exe

all: $(EXE)

.PHONY: all

$(EXE): $(OBJ)
	$(CXX) $^ -o $@

%.o: %.cc 
	$(CXX) -c $< -o $@ $(CXXFLAGS)

format: $(SRC) func.hpp
	@clang-format -i $^ 2>/dev/null || echo "Please install clang-format to run this command"

.PHONY: format

clean:
	rm -f $(EXE) *~ $(OBJ)

.PHONY: clean

src1.o: func.hpp
src2.o: func.hpp
