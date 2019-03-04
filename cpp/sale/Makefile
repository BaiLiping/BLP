test: test.cpp sale.so discountsale.so
	g++ -g -Wall test.cpp sale.so discountsale.so -o test
sale.so: sale.cpp sale.h
	g++ -g -Wall -c sale.cpp sale.h -o sale.so
discountsale.so: discountsale.cpp discountsale.h
	g++ -g -Wall -c discountsale.cpp discountsale.h -o discountsale.so


