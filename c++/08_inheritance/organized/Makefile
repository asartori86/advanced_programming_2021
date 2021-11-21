EXE = exe.x
CXX = c++
CXXFLAGS = -I include -g -std=c++14 -Wall -Wextra -I ../../06_error_handling/

SRC= main.cpp src/dog.cpp src/animal.cpp src/snake.cpp src/helper_functions.cpp
OBJ=$(SRC:.cpp=.o)
INC = include/animal.hpp  include/dog.hpp  include/helper_functions.hpp  include/snake.hpp

VPATH = ../../06_error_handling include

# eliminate default suffixes
.SUFFIXES:
SUFFIXES =

# just consider our own suffixes
.SUFFIXES: .cpp .o

all: $(EXE)

.PHONY: all

clean:
	rm -rf $(OBJ) $(EXE) src/*~ include/*~ *~ html latex

.PHONY: clean

%.o: %.cpp ap_error.hpp
	$(CXX) -c $< -o $@ $(CXXFLAGS)

$(EXE): $(OBJ)
	$(CXX) $^ -o $(EXE)

documentation: Doxygen/doxy.in
	doxygen $^

.PHONY: documentation

main.o: dog.hpp animal.hpp snake.hpp helper_functions.hpp

src/animal.o: animal.hpp 

src/dog.o: animal.hpp dog.hpp
src/snake.o: animal.hpp snake.hpp
src/helper_functions.o: animal.hpp helper_functions.hpp

format: $(SRC) $(INC)
	@clang-format -i $^ -verbose || echo "Please install clang-format to run this commands"

.PHONY: format
