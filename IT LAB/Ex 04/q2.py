#!/usr/bin/env python3

class Solution:
    
    def target_number(self , array  , target):
        i = 0
        j = 1
        for i in range(len(array)-2):            
            for j in range(len(array)-1):            
                if array[i] + array[j] == target:
                    return i+1,j+1


    
if __name__ == "__main__":
    sol = Solution()
    array = [int(x) for x in input("Enter the array elements: ").split()]
    target = int(input("Enter the target: "))

    answer = sol.target_number(array,target)
    print(answer)