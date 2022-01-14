SRC_C = 01_hello.c 03_visibility.c 
SRC_CXX = 02_hello.cpp 04_extern.cpp
CC = cc
CXX = c++

OBJ = $(SRC_C:.c=.o) $(SRC_CXX:.cpp=.o)

all: $(OBJ)


format: $(SRC) 
	@clang-format -i $^ 2>/dev/null || echo "Please install clang-format to run this commands"

clean:
	@rm -f *~ *.x *.o *.s

.PHONY: clean all format
