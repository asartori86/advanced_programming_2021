CC = cc
CXX = c++

all: c-main cpp-main

cpp-main: cpp-main.cpp class.o
	$(CXX) $^ -o $@ -std=c++11

c-main: c-main.c class.o class_c_interface.o
	$(CC) $^ -lstdc++ -o $@

%.o: %.cpp
	$(CXX) -c $< -o $@ -std=c++11

clean:
	rm -f *~ *.o c-main cpp-main

.PHONY: all clean

class.o: class.hpp
class_c_interface.o: class.hpp class_c_interface.h


format: class.hpp class.cpp class_c_interface.h class_c_interface.cpp cpp-main.cpp c-main.c
	@clang-format -i $^ -verbose || echo "Please install clang-format to run this commands"
