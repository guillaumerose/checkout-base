import unittest

# Ajout de ../ au path
import os, sys
sys.path.insert(0, os.path.dirname(os.path.dirname(os.path.abspath(__file__))))

import lib.checkout

class checkout_test(unittest.TestCase):
    def test_always_true(self):
        checkout = lib.checkout.Checkout()
        self.assertEqual("ABC", checkout.process("aBc"))

if __name__ == '__main__':
    unittest.main()
