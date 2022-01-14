CC = cc
CXX = c++
EXE = exe

all: $(EXE)

$(EXE): cpp2c.o main.o
	$(CC) $^ -lstdc++ -o $@

main.o: main.c

cpp2c.o: cpp2c.cpp
	$(CXX) -std=c++14 -c $< -o $@

clean:
	rm -f *~ *.o $(EXE)

.PHONY: all clean format


format: cpp2c.cpp main.c
	@clang-format -i $^ 2>/dev/null || echo "Please install clang-format to run this commands"
