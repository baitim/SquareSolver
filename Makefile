options = -Wshadow -Winit-self -Wredundant-decls -Wcast-align -Wundef -Wfloat-equal -Winline -Wunreachable-code -Wmissing-declarations -Wmissing-include-dirs -Wswitch-enum -Wswitch-default -Weffc++ -Wmain -Wextra -Wall -g -pipe -fexceptions -Wcast-qual -Wconversion -Wctor-dtor-privacy -Wempty-body -Wformat-security -Wformat=2 -Wignored-qualifiers -Wlogical-op -Wno-missing-field-initializers -Wnon-virtual-dtor -Woverloaded-virtual -Wpointer-arith -Wsign-promo -Wstack-usage=8192 -Wstrict-aliasing -Wstrict-null-sentinel -Wtype-limits -Wwrite-strings -Werror=vla -D_DEBUG -D_EJUDGE_CLIENT_SIDE

debug =

SOURCES = Main.cpp\
Process_cmd.cpp\
Calculate_equation_from_cmd.cpp\
Input.cpp\
Calculation.cpp\
Output.cpp\
Tests.cpp

run : start.exe finish

start.exe : Main.o Calculate_equation_from_cmd.o Input.o Calculation.o Output.o Tests.o Process_cmd.o
	g++ Main.o Calculate_equation_from_cmd.o Input.o Calculation.o Output.o Tests.o Process_cmd.o -o start.exe

Main.o : Main.cpp
	g++ -c Main.cpp -o Main.o $(options) $(debug)

Process_cmd.o : Process_cmd.cpp
	g++ -c Process_cmd.cpp -o Process_cmd.o $(options) $(debug)

Calculate_equation_from_cmd.o : Calculate_equation_from_cmd.cpp
	g++ -c Calculate_equation_from_cmd.cpp -o Calculate_equation_from_cmd.o $(options) $(debug)

Input.o : Input.cpp
	g++ -c Input.cpp -o Input.o $(options) $(debug)

Calculation.o : Calculation.cpp
	g++ -c Calculation.cpp -o Calculation.o $(options) $(debug)

Output.o : Output.cpp
	g++ -c Output.cpp -o Output.o $(options) $(debug)

Tests.o : Tests.cpp
	g++ -c Tests.cpp -o Tests.o $(options) $(debug)

finish :
	rm Main.o Calculate_equation_from_cmd.o Input.o Calculation.o Output.o Tests.o Process_cmd.o
