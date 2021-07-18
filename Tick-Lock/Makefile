
all: test-lock

clean:
	rm -f test-lock tick_lock.o rw_liblock.so

lock: tick_lock.c tick_lock.h
	gcc -g -c -Wall -Werror -fpic tick_lock.c
	gcc -g -shared -o libtick_lock.so tick_lock.o
	chmod +x libtick_lock.so tick_lock.o

test-lock: lock	test-lock.c
	gcc -L. -o test-lock test-lock.c -Wall -pthread -g -ltick_lock
