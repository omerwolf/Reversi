target: compileAll
	g++ -o ../../exe/client.out *.o
	rm -f *.o

compileAll: include/*.h source/*.cpp
	g++ -Iinclude/ -c source/*.cpp
