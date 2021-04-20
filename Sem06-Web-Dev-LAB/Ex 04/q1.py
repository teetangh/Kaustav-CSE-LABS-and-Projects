#!/usr/bin/env python3

class Solution:  
    def f1(self, s1):  
        return self.f2([], sorted(s1))  
 
    def f2(self, curr, s1):  
        if s1:  
            return self.f2(curr, s1[1:]) + self.f2(curr + [s1[0]], s1[1:])  
        return [curr]  

elements_list = [int(x) for x in input().split()]

subset_solution = Solution()
print("Subsets: ")
for ele in subset_solution.f1(elements_list): 
    print(ele)