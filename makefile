a.out:compileAll
	g++ *.o
	rm -f *.o

compileAll: include/*.h source/*.cpp
	g++ -Iinclude/ -c source/*.cpp
run:
	./.a.out
