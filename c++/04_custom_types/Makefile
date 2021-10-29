SRC = 01_enum.cpp                    \
      02_scoped_enum.cpp             \
      03_namespace.cpp               \
      04_why_scoped.cpp              \
      05_struct_class.cpp            \
      06_operator_overloading.cpp    \
      07_multiple_flags.cpp          \
      08_constructor_destructor.cpp  \
      09_template_class.cpp

CXX = c++
CXXFLAGS = -Wall -Wextra -g -std=c++14

EXE = $(SRC:.cpp=.x)

# eliminate default suffixes
.SUFFIXES:
SUFFIXES =

# just consider our own suffixes
.SUFFIXES: .cpp .x

all: $(EXE)

.PHONY: all

%.x: %.cpp 
	$(CXX) $< -o $@ $(CXXFLAGS)

format: $(SRC)
	@clang-format -i $^ -verbose || echo "Please install clang-format to run this command"

.PHONY: format

clean:
	rm -f $(EXE) *~

.PHONY: clean

01_enum.x : CXXFLAGS += -Wno-unused-variable
02_scoped_enum.x : CXXFLAGS += -Wno-unused-variable
05_struct_class.x : CXXFLAGS += -Wno-unused-but-set-variable -Wno-unknown-warning-option
