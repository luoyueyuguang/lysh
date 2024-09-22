LDFLAGS+=-I./include -L./lib 
CFLAGS+=-Werror -g


SRC=$(wildcard ./src/*.c)
OBJECTS=$(SRC:.c=.o)

.PHONY: all clean

all: lysh

lysh: $(OBJECTS)
	$(CC) -o $@ $^ $(LDFLAGS) $(CFLAGS)

.INTERMEDIATE: $(OBJECTS) 
$(OBJECTS): %.o: %.c
	$(CC) -c -o $@ $^ $(LDFLAGS) $(CFLAGS)

clean:
	rm -f lysh lysh.o
