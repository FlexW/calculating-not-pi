all:
	$(CC) -o notpi main.c calc_not_pi.c -lgmp -lmpfr

clean:
	rm -Rf notpi
