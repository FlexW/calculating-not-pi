pi: decimal.o main.cc
	g++ -o pi -g main.cc decimal.o

decimal.o: decimal.cc decimal.h
	g++ -c -g decimal.cc

clean:
	rm -Rf decimal.o main.o pi
