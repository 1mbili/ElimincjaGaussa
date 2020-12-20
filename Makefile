all:
	gcc -Wall --pedantic src/*.c -o bin/gauss

test1: all
	bin/gauss dane/A2 dane/b2

test2: all
	bin/gauss dane/A2-1 dane/b2-1

test3: all
	bin/gauss dane/C dane/d
