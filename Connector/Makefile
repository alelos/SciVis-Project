CC=g++
CFLAGS= -c -lssh
LDFLAGS=
SOURCES=main.cpp Connector.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=a

all:$(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@
.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -rf *o a
