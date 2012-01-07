.PHONY: clean test

all: checkout.o console.o checkout_test console

checkout_test: checkout.o

test: checkout_test
	./checkout_test

clean:
	rm -f *.o checkout_test console
