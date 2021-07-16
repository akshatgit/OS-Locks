
all: test-lock

clean:
	rm -f test-lock lock.o liblock.so

lock: lock.c lock.h
	gcc -c -Wall -Werror -fpic lock.c
	gcc -shared -o liblock.so lock.o

test-lock: lock test-lock.c lock
	gcc -L . -llock -o test-lock test-lock.c -Wall -pthread -g
