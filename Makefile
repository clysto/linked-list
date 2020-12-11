CC = gcc
CFLAGS = -std=c99 -fPIC -pedantic -Wall -g -Isrc
LDFLAGS = -shared -Wl,-soname,liblinkedlist.so
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
test: $(TARGET_LIB) test_exe
	LD_LIBRARY_PATH=. DYLD_LIBRARY_PATH=. ./tests/test


test_exe:
	$(CC) -o tests/test -Isrc -L. tests/test.c -llinkedlist

