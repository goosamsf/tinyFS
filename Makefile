CC = gcc
CFLAGS = -g -Wall
LD = gcc
LDFLAGS = -g -Wall
PROG=libDisk
SRCS=libDisk.c 


tinyFS: tinyFS.c tinyFS.h tinyFS.o ./lib/libDisk.a 
	$(CC) $(CFLAGS) -o tinyFS tinyFS.o -L./lib -lDisk

tinyFS.o : tinyFS.c tinyFS.h ./lib/libDisk.a
	$(CC) $(CFLAGS) -c tinyFS.c -L./lib -lDisk

run: libDisk.o diskTest.o util.o
	$(LD) $(LDFLAGS) -o run libDisk.o diskTest.o util.o

libDisk.o: libDisk.c libDisk.h util.c util.h
	$(CC) $(CFLAGS) -c $(SRCS) 

diskTest.o: diskTest.c libDisk.c libDisk.h
	$(CC) $(CFLAGS) -c diskTest.c

util.o: util.c util.h
	$(CC) $(CFLAGS) -c util.c


#libDisk.a: 
#ar r libDisk.a libDisk.o util.o


gen_text:
	@./scripts/gen_textfile.sh

clean:
	rm -f *.o
	rm -f *.dsk

