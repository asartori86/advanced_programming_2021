# Simple Makefile to compile, clean and format all the sample codes
# provided during the course of Advanced Programming

default: all

all: 
	+$(MAKE) $@ -C c++

clean:
	+$(MAKE) $@ -C c++
	@find . -type f \( -name '*~' -o -name 'a.out' \) -exec rm '{}' \;

format:
	+$(MAKE) $@ -C c++

.PHONY: all clean format default
