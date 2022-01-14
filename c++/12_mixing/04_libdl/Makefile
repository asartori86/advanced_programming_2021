CC = cc

all: libhello.so main

libhello.so: hello.c
	$(CC) -shared -fpic -o $@ $<

main: main.c libhello.so
	$(CC) -o $@ $< -ldl

clean:
	rm -f *~ libhello.so main

.PHONY: clean all format

format: hello.c main.c
	@clang-format -i $^ 2>/dev/null || echo "Please install clang-format to run this commands"


