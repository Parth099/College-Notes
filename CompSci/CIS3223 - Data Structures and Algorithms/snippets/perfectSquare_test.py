from perfectSquare import perfectSquare
import unittest

class PerfectSquareTest(unittest.TestCase):

    def test_16(self):
        # 4
        self.assertTrue(perfectSquare(16), "16 is pref_sq")

    def test_81(self):
        # 9
        self.assertTrue(perfectSquare(81), "81 is pref_sq")

    def test_144(self):
        # 12
        self.assertTrue(perfectSquare(144), "144 is pref_sq")

    def test_82(self):
        self.assertFalse(perfectSquare(82), "82 is NOT pref_sq")

    def test_92(self):
        self.assertFalse(perfectSquare(92), "92 is NOT pref_sq")


if __name__ == '__main__':
    unittest.main()
