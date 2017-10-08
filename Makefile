all:
	$(CC) -o notpi main.c calcpi.c -lgmp -lmpfr

clean:
	rm -Rf notpi
