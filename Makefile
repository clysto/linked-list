CC = cc
CFLAGS = -std=c99 -fPIC -pedantic -Wall -g -Isrc
LDFLAGS= -shared
SOURCES = src/linked_list.c
OBJECTS = $(SOURCES:.c=.o)
TARGET_LIB = liblinkedlist.so

.PHONY: all
all: $(TARGET_LIB)

$(TARGET_LIB): $(OBJECTS)
	$(CC) ${LDFLAGS} -o $@ $^

.PHONY: clean
clean:
	rm -f src/*.o tests/test $(TARGET_LIB)

.PHONY: test
.ONESHELL:
test: $(TARGET_LIB)
	cc -o tests/test -Isrc -L. -llinkedlist tests/test.c
	LD_LIBRARY_PATH=. DYLD_LIBRARY_PATH=. ./tests/test
