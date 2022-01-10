EXE = ap
GDIR=../01_greetings_library

LDFLAGS = -lgreetings -L $(GDIR)
CXX = c++
CXXFLAGS = -I include -I $(GDIR)/include -std=c++14

all: $(EXE)

%.o: %.cpp
	$(CXX) -c $< -o $@ $(CXXFLAGS)


$(EXE): main.o src/date.o src/student.o
	$(CXX) $^ -o $(EXE) $(LDFLAGS)

main.o: src/student.o src/date.o

src/date.o: include/date.hpp

src/student.o: include/student.hpp

format: $(SRC) include/date.hpp include/student.hpp
	@clang-format -i $^ 2>/dev/null || echo "Please install clang-format to run this commands"

clean:
	rm -rf src/*.o *.o $(EXE) */*~ *~ a.out*

.PHONY: clean all format


