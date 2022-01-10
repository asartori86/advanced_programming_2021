CXX = c++
LANG = ENGLISH

SRC = src/greetings.cpp src/conclusion.cpp
OBJ = $(SRC:.cpp=.o)

all: libgreetings.so

libgreetings.so: $(OBJ)
	$(CXX) -shared -o $@ $^

%.o:%.cpp
	$(CXX) -fpic -D$(LANG) -o $@ -c $< -Iinclude

src/greetings.o: include/greetings.hpp

src/conclusion.o: include/conclusion.hpp

format: $(SRC) include/greetings.hpp include/conclusion.hpp
	@clang-format -i $^ 2>/dev/null || echo "Please install clang-format to run this commands"

clean:
	@rm -f *~ */*~ libgreetings.so src/*.o

.PHONY: clean all format
