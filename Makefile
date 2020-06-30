laba: main.o info.o list.o 
	g++ main.o info.o list.o -o laba

main.o: main.cpp
	g++ -c main.cpp 
info.o: info.cpp
	g++ -c info.cpp
list.o: list.cpp
	g++ -c list.cpp
clean:
	rm *.o laba
