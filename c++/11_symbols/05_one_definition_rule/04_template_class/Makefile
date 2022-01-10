SRC = src1.cpp src2.cpp main.cpp
CXX = c++
CXXFLAGS = -Wall -Wextra -g -std=c++14
OBJ = $(SRC:.cpp=.o)
EXE = exe

all: $(EXE)

.PHONY: all

$(EXE): $(OBJ)
	$(CXX) $^ -o $@

%.o: %.cpp 
	$(CXX) -c $< -o $@ $(CXXFLAGS)

format: $(SRC) class.hpp
	@clang-format -i $^ 2>/dev/null || echo "Please install clang-format to run this command"

.PHONY: format

clean:
	rm -f $(EXE) *~ $(OBJ)

.PHONY: clean

src1.o: class.hpp
src2.o: class.hpp
