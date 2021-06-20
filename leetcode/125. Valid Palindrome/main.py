import re

class Solution:
	def isPalindrome(s: str)-> bool:
		# s = re.sub('[a-z\d]+', '', s.lower())
		s = re.sub('[^a-z\d]+','',s.lower())
		return s == s[::-1]

if __name__ == "__main__":
	s = input()
	print(Solution.isPalindrome(s))