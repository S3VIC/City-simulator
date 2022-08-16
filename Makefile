default:
	mkdir ./build -p
	g++ -o ./build/SymulatorMiasta main.cpp ./src/kibic.cpp ./src/miasto.cpp -I ./include/ -Wall