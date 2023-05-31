source.o : source.cpp source.h
        clang++ -c source.cpp 

main.o : main.cpp source.h
        clang++ -c main.cpp

main.exe : source.o main.o
        clang++ source.o main.o -o main.exe