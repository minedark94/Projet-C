CC = gcc
CFLAGS = -Wall
LDFLAGS = -lssl -lcrypto
INCLUDES = -I/usr/include/openssl
SOURCES = main.c arbre_binaire.c lecture_ecriture.c sha256.c
EXECUTABLE = projet-bin

all: $(SOURCES)
	$(CC) $(CFLAGS) $(INCLUDES) $(SOURCES) -o $(EXECUTABLE) $(LDFLAGS)

clean:
	rm -f $(EXECUTABLE)
