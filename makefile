CC=g++
graphicus: canevas.o couche.o forme.o vecteur.o tests.o
	$(CC) graphicus.cpp canevas.o tests.o couche.o forme.o vecteur.o -o graphicus 

tests.o: canevas.o tests.h tests.cpp
	$(CC) -c tests.cpp

canevas.o: canevas.h canevas.cpp forme.o couche.o rectangle.o
	$(CC) -c canevas.cpp 

forme.o: coordonnee.h forme.h forme.cpp
	$(CC) -c forme.cpp

couche.o: couche.h couche.cpp
	$(CC) -c couche.cpp

vecteur.o: forme.h vecteur.h vecteur.cpp
	$(CC) -c vecteur.cpp
	
rectangle.o: forme.o rectangle.h rectangle.cpp
	$(CC) -c rectangle.cpp
