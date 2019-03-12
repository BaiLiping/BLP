CPP=g++
FLAGS= -g -Wall -Wextra

test: test.cpp bst.so
	$(CPP) $(FLAGS)  $^ -o $@
bst.so: bst.cpp bst.hpp
	$(CPP) -c $(FLAGS)  bst.cpp -o $@ 
clean:
	rm -f *.out;
	rm -f test;
	rm -f *.so;
	rm -f *~;
	rm -f *.o;
