SRC = test_count_operations.cpp test_time.cpp 
HEADERS= instrumented.hpp timer.hpp

CXX = c++
CXXFLAGS = -O3 -std=c++14 -march=native


EXE = $(SRC:.cpp=.x)


# eliminate default suffixes
.SUFFIXES:
SUFFIXES =

# just consider our own suffixes
.SUFFIXES: .cpp .o

all: $(EXE)

.PHONY: all

%.o: %.cpp
	$(CXX) $< -o $@ $(CXXFLAGS) -c

%.x: %.o
	$(CXX) $^ -o $@

format: $(SRC) $(HEADERS) instrumented.cpp
	@clang-format -i $^ -verbose || echo "Please install clang-format to run this command"

.PHONY: format

clean:
	rm -f $(EXE) *~ *.o

.PHONY: clean

test_count_operations.o: instrumented.hpp
test_count_operations.x: instrumented.o
test_time.o: timer.hpp
instrumented.o: instrumented.hpp
