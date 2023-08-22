options = -Wshadow -Winit-self -Wredundant-decls -Wcast-align -Wundef -Wfloat-equal -Winline -Wunreachable-code -Wmissing-declarations -Wmissing-include-dirs -Wswitch-enum -Wswitch-default -Weffc++ -Wmain -Wextra -Wall -g -pipe -fexceptions -Wcast-qual -Wconversion -Wctor-dtor-privacy -Wempty-body -Wformat-security -Wformat=2 -Wignored-qualifiers -Wlogical-op -Wno-missing-field-initializers -Wnon-virtual-dtor -Woverloaded-virtual -Wpointer-arith -Wsign-promo -Wstack-usage=8192 -Wstrict-aliasing -Wstrict-null-sentinel -Wtype-limits -Wwrite-strings -Werror=vla -D_DEBUG -D_EJUDGE_CLIENT_SIDE

debug = 

run : start.exe
	
start.exe : Square_Solver_main.o Start_Input.o Input.o Calculation.o Output.o Tests.o
	g++ -g Square_Solver_main.o Start_Input.o Input.o Calculation.o Output.o Tests.o -o start.exe 

Square_Solver_main.o : Square_Solver_main.cpp
	g++ -g -c Square_Solver_main.cpp -o Square_Solver_main.o $(options) $(debug)

Start_Input.o : Start_Input.cpp
	g++ -g -c Start_Input.cpp -o Start_Input.o $(options) $(debug)

Input.o : Input.cpp
	g++ -g -c Input.cpp -o Input.o $(options) $(debug)

Calculation.o : Calculation.cpp
	g++ -g -c Calculation.cpp -o Calculation.o $(options) $(debug)

Output.o : Output.cpp
	g++ -g -c Output.cpp -o Output.o $(options) $(debug)

Tests.o : Tests.cpp
	g++ -g -c Tests.cpp -o Tests.o $(options) $(debug)
