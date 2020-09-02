all:solve generate transform
solve:solve.o sudoku.o
	g++ -o solve solve.o sudoku.o

sudoku.o:sudoku.cpp sudoku.h
	g++ -c sudoku.cpp

solve.o:solve.cpp sudoku.h
	g++ -c solve.cpp

generate:generate.cpp
	g++ -o generate generate.cpp

transform:transform.cpp
	g++ -o transform transform.cpp
