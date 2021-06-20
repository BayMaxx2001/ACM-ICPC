str = "abcd" #unique
import unittest

class Test(unittest.TestCase):
	dataT = [('abcd') , ('s412fad') , ('')]
	dataF = [('aa'), ('bb')]

	def test_unique(self):
		for test_case in self.dataT:
			res = unique(test_case)
			self.assertTrue(res)
		for test_case in self.dataF:
			res = unique(test_case)
			self.assertFalse(res)


def unique(s):
	print(s)
	char_set = {}
	
	for char in s:
		# print(char)
		if char in char_set:
			return False
		char_set[char] = 1

	return True

if __name__ == "__main__":
	# s = input()
	# print(unique(s))
	unittest.main() 