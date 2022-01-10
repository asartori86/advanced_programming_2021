SRC = $(wildcard *.cpp)
CXXFLAGS = -g -std=c++14 -Wall -Wextra
EXE = exe
OBJ = $(SRC:.cpp=.o)
INC = $(wildcard *.hpp)

all: $(EXE)

$(EXE): $(OBJ)
	g++ -o $@ $^

%.o: %.cpp constants.hpp
	$(CXX) -c $< -o $@ $(CXXFLAGS)

format: $(SRC) $(INC)
	@clang-format -i $^ 2>/dev/null || echo "Please install clang-format to run this commands"

clean:
	rm -f $(EXE) *~ $(OBJ)

.PHONY: clean all format


