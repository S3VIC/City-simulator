default:
	mkdir ./build -p
	g++ -o ./build/SymulatorMiasta main.cpp ./src/kibic.cpp ./src/miasto.cpp ./src/simulator.cpp ./src/interface.cpp -I ./include/ -Wall
