CC=g++
graphicus: canevas.o couche.o forme.o vecteur.o tests.o
	$(CC) -c graphicus.cpp -o graphicus 

tests.o: canevas.o tests.h tests.cpp
	$(CC) -c tests.cpp

canevas.o: canevas.h canevas.cpp forme.o couche.o
	$(CC) -c canevas.cpp 

forme.o: coordonnee.h forme.h forme.cpp
	$(CC) -c forme.cpp

vecteur.o: vecteur.h vecteur.cpp
	$(CC) -c vecteur.cpp
	
couche.o: couche.h couche.cpp
	$(CC) -c couche.cpp
