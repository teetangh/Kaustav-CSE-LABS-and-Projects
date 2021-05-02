#!/usr/bin/env python3

class Solution:

    def get_string(self):
        self.q4_string = str(input("Enter the string: "))

    def print_string(self):
        print(self.q4_string.upper())

if __name__ == "__main__":
    sol = Solution()

    sol.get_string()
    sol.print_string()