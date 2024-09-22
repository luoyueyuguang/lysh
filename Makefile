LDFLAGS+=-I./include -L./lib 
CFLAGS+=-Wall


SRC=$(wildcard ./src/*.c)
OBJECTS=$(SRC:.c=.o)

.PHONY: all clean

all: lysh

lysh: $(OBJECTS)
	$(CC) -o $@ $^ $(LDFLAGS) $(CFLAGS)

$(OBJECTS): %.o: %.c
	$(CC) -c -o $@ $^ $(LDFLAGS) $(CFLAGS)

clean:
	rm -f lysh lysh.o
