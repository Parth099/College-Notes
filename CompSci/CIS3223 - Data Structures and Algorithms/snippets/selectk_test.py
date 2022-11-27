from selectk import selectK
import unittest

class TestSelectK(unittest.TestCase):

    def test_start(self):
        S, k = [1, 2, 3, 5], 1
        result = 1
        self.assertEqual(selectK(S, k), result, "Failed if element at start of array")

    def test_mid1(self):
        S, k = [1, 2, 3, 5], 2
        result = 2
        self.assertEqual(selectK(S, k), result, "Failed if element in middle of array")

    def test_mid2(self):
        S, k = [9, 9, 3, 4, 5, 6, 8, 4, 5, 6], 4
        result = 5
        self.assertEqual(selectK(S, k), result, "Failed if element in middle (long) of array")

    def test_mid3(self):
        S, k = [9, 3, 4, 5, 6, 8, 4, 5, 6], 8
        result = 8
        self.assertEqual(selectK(S, k), result, "Failed if element in middle (long) of array")

    def test_end(self):
        S, k = [9, 3, 4, 5, 6, 8, 4, 5, 6], 9
        result = 9
        self.assertEqual(selectK(S, k), result, "Failed if element at end of array")

    def test_single_element(self):
        S, k = [1], 1
        result = 1
        self.assertEqual(selectK(S, k), result, "Single element")

    def test_error(self):
        S, k = [14, 18, 13, 1901], 5
        result = float("-inf")
        self.assertEqual(selectK(S, k), result, "ret -inf on too high k")

if __name__ == '__main__':
    unittest.main()

