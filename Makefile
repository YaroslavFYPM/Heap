FLAGS = -fprofile-arcs -ftest-coverage
all: a.out

a.out: tests.o heap.o
	gcc $(FLAGS) heap.o tests.o -o a.out
tests.o: tests.c
	gcc $(FLAGS) -c tests.c -o tests.o
heap.o: heap.c
	gcc $(FLAGS) -c heap.c -o heap.o 
clean:
	rm -rf a.out tests heap *.o *.gcov *.gcda *.gcno 