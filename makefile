CC=gcc
CFLAGS=-Wall -Wextra -g
LDFLAGS=
SOURCES=main.c sync.c vlc.c
OBJECTS=$(SOURCES:.c=.o)
EXECUTABLE=executable

all: $(SOURCES) $(EXECUTABLE)
	rm -f *.o *~

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.o:
	$(CC) $(CFLAGS) $< -o $@
