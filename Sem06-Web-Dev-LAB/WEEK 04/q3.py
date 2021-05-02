#!/usr/bin/env python3

class Solution:
	def power(self,x,n):
		if  x == 0 or x==1 or n==0:
			return x
		elif n < 0:
			return 1 / self.power(x,-n)
		else: 
			return x * self.power(x,n-1)

if __name__ == "__main__":
	sol = Solution()
	x = int(input("Enter x: "))
	n = int(input("Enter n: "))
	answer = sol.power(x,n)
	print(answer)
