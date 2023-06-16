CFLAGS = -Wall  # flags de compilacao

CC = gcc

# arquivos-objeto
	objects = myht.o cuckoo_hashing.o
     
myht: myht.o cuckoo_hashing.o
	$(CC) -o myht myht.o cuckoo_hashing.o

cuckoo_hashing.o: cuckoo_hashing.c
	$(CC) -c $(CFLAGS) cuckoo_hashing.c

myht.o: myht.c
	$(CC) -c $(CFLAGS) myht.c

clean:
	rm -f $(objects) 

purge:
	rm -f myht
