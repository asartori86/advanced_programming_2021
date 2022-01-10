SRC = 01_functions.cpp 02_members.cpp
CXXFLAGS = -std=c++14 -Wall -Wextra
EXE = $(SRC:.cpp=.x)

.SUFFIXES:
.SUFFIXES: .cpp .x

all: $(EXE)

%.x: %.cpp
	$(CXX) $< -o $@ $(CXXFLAGS)

format: $(SRC)
	@clang-format -i $^ 2>/dev/null || echo "Please install clang-format to run this commands"

clean:
	rm -f $(EXE) *~

.PHONY: clean all format


