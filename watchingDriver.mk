watchingDriver: watchingDriver.o Watched.o Observer.o
	g++ -Wall watchingDriver.o Watched.o Observer.o -o watchingDriver

Watched.o: Watched.cpp Watched.h
	g++ -c -Wall Watched.cpp

Observer.o: Observer.cpp Observer.h
	g++ -c -Wall Observer.cpp

watchingDriver.o: watchingDriver.cpp Watched.h Observer.h
	g++ -c -Wall watchingDriver.cpp

