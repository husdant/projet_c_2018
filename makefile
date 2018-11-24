CC   = gcc
CFLAGS =  -std=c99  -Wall -pedantic
LDFLAGS=

EXEFILE = .
EXENAME = lena

EXE=.exe

all: $(EXENAME)

lena:main.o pixmap.o
	$(CC) -o $(EXENAME)$(EXE) pixmap.o main.o $(CFLAGS)

main.o:main.c
		$(CC) -c main.c $(CFLAGS) -o main.o

pixmap.o:pixmap.c
	$(CC) -c pixmap.c $(CFLAGS) -o pixmap.o

clean :
	rm -rf *.o
	rm -rf $(EXE)
