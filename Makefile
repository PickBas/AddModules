./src/main.o: ./src/main.cpp
	g++ -c ./src/main.cpp

./src/CreationCModule.o: ./src/CreationCModule.cpp
	g++ -c ./src/CreationCModule.cpp

./src/CreationCppModule.o: ./src/CreationCppModule.cpp
	g++ -c ./src/CreationCppModule.cpp

AddModule: ./src/main.o ./src/CreationCModule.o ./src/CreationCppModule.o
	g++ main.o CreationCModule.o CreationCppModule.o -o AddModule
	rm *.o

all: AddModule