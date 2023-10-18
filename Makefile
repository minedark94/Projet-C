CC = gcc
CFLAGS = -Wall
LDFLAGS = -lssl -lcrypto
INCLUDES = -I/usr/include/openssl
SOURCES = src/main.c src/arbre_binaire.c src/lecture_ecriture.c src/sha256.c
EXECUTABLE = projet-bin

all: $(SOURCES)
	$(CC) $(CFLAGS) $(INCLUDES) $(SOURCES) -o $(EXECUTABLE) $(LDFLAGS)

clean:
	rm -f $(EXECUTABLE)
