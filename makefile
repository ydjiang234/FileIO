Include_Path = -I ../Eigen
FileIO=FileIO.a

linkclass:link ar

test:linkclass main

link:FileIO.h FileIO.cpp
	g++ -c FileIO.cpp $(Include_Path) -std=c++11

ar:FileIO.o
	ar rvs FileIO.a FileIO.o

main:main.cpp FileIO.h FileIO.cpp FileIO.a
	g++ main.cpp $(FileIO) -o main $(Include_Path) -std=c++11

