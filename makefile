hepsi:derle obj calistir
					
derle:
	g++ -I ./include -c ./src/AVLTree.cpp -o ./lib/AVLTree.o
	g++ -I ./include -c ./src/Dugum.cpp -o ./lib/Dugum.o
	g++ -I ./include -c ./src/Kisi.cpp -o ./lib/Kisi.o
	g++ -I ./include -c ./src/Islem.cpp -o ./lib/Islem.o
	g++ -I ./include -c ./src/Stack.cpp -o ./lib/Stack.o
	g++ -I ./include -c ./src/Test.cpp -o ./lib/Test.o
obj:
	g++ ./lib/Stack.o ./lib/AVLTree.o ./lib/Kisi.o ./lib/Dugum.o ./lib/Islem.o  ./lib/Test.o  -o ./bin/FinalOdev.exe
calistir:
	./bin/FinalOdev