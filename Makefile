options = -Wall -Wextra -D _DEBUG
debug = 

run : start.exe
	start.exe

start.exe : Square_Solver_main.o Tests.o Input.o Calculation.o Output.o
	g++ -g Square_Solver_main.o Tests.o Input.o Calculation.o Output.o -o start.exe

Square_Solver_main.o : Square_Solver_main.cpp
	g++ -g -c Square_Solver_main.cpp -o Square_Solver_main.o $(options)

Tests.o : Tests.cpp
	g++ -g -c Tests.cpp -o Tests.o $(options) $(debug)

Input.o : Input.cpp
	g++ -g -c Input.cpp -o Input.o $(options) $(debug)

Calculation.o : Calculation.cpp
	g++ -g -c Calculation.cpp -o Calculation.o $(options) $(debug)

Output.o : Output.cpp
	g++ -g -c Output.cpp -o Output.o $(options) $(debug)