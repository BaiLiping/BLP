CPP=g++
FLAG= -g

test:test.cpp heap.so
	$(CPP) $(FLAG) $^ -o $@
heap.so:heap.cpp heap.h
	$(CPP) -c $(FLAG) heap.cpp -o $@
clean:
	rm -f *.so
	rm -f *.out
	rm -f test

