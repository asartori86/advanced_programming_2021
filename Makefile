# Simple Makefile to compile, clean and format all the sample codes
# provided during the course of Advanced Programming

default: all

all: 
	+$(MAKE) $@ -C lectures

clean:
	+$(MAKE) $@ -C lectures
	@find . -type f \( -name '*~' -o -name 'a.out' \) -exec rm '{}' \;

format:
	+$(MAKE) $@ -C lectures

.PHONY: all clean format default
