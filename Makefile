ALGO_DIR = RNG_Algorithm/
IMP = random_number_generator.exe

$(IMP): main.o algo.o
	gcc -g -Wall main.o algo.o -o $(IMP)

main.o: main.c $(ALGO_DIR)lcg.h $(ALGO_DIR)lcg.c $(ALGO_DIR)mwc.c $(ALGO_DIR)mwc.h $(ALGO_DIR)xorshift.c $(ALGO_DIR)xorshift.h
	gcc -g -Wall -c main.c -o main.o

algo.o: lcg.o mwc.o xorshift.o
	ld -r lcg.o mwc.o xorshift.o -o algo.o

lcg.o: $(ALGO_DIR)lcg.h $(ALGO_DIR)lcg.c
	gcc -g -Wall -c $(ALGO_DIR)lcg.c -o lcg.o

mwc.o: $(ALGO_DIR)mwc.h $(ALGO_DIR)mwc.c
	gcc -g -Wall -c $(ALGO_DIR)mwc.c -o mwc.o

xorshift.o: $(ALGO_DIR)xorshift.c $(ALGO_DIR)xorshift.h
	gcc -g -Wall -c $(ALGO_DIR)xorshift.c -o xorshift.o

run: $(IMP)
	./$(IMP)

clean:
	del -Q $(IMP)
	del -Q *.o
	del -Q *.txt