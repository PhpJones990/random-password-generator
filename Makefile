random_number_generator.exe: main.o lcg.o
	gcc -g -Wall main.o lcg.o -o random_number_generator.exe

main.o: main.c RNG_Algorithm/lcg.h RNG_Algorithm/lcg.c
	gcc -g -Wall -c main.c -o main.o

lcg.o: RNG_Algorithm/lcg.h RNG_Algorithm/lcg.c
	gcc -g -Wall -c RNG_Algorithm/lcg.c -o lcg.o

run: random_number_generator.exe
	./random_number_generator.exe

clean:
	del -Q random_number_generator.exe
	del -Q *.o
	del -Q *.txt