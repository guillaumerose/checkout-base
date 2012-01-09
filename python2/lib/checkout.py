import sys

class Checkout:
    def process(self, a):
        return a.upper()

if sys.argv[0] == __file__:
    checkout = Checkout()
    while 42:
        print ">",
        print checkout.process(raw_input(''))
