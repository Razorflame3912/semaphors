all: control.c
	gcc -o control control.c

clean:
	rm -f *~
	rm -f control

run: all
	./control -c 5
	./control -c 5
	./control -v
	./control -r
