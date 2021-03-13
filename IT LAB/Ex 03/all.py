import numpy as np
import os

class Q1:
    def calculator(self,num1, num2 , option):
        switcher = {
            1: num1 + num2,
            2: num1 - num2,
            3: num1 * num2,
            4: num1 / num2,
        }
        return 	switcher.get(option,"invalid option")

    def main(self):
        num1 = int(input("Enter number 1 "))
        num2 = int(input("Enter number 2 "))

        print("Enter 1 for addition")	
        print("Enter 2 for subtraction")	
        print("Enter 3 for multiplication")	
        print("Enter 4 for division")	

        option = int(input("Enter option"))
        print(self.calculator(num1,num2,option))	


class Q2:
    def main(self):	
        with open("input2.txt" , "r") as file1:
            data = file1.read()
        data_1 = data[::-1]

        file2 = open("output2.txt" , "w")
        file2.write(data_1)
        file2.close()

        file2 = open("output2.txt" , "r")
        print(file2.read())


class Q3:
    def binary_search(self,array , key):

        if len(array) <= 0:
            return -1

        low = 0
        high = len(array) - 1
        
        mid = (low + high)/2
        mid = int(mid)
        # print("DEBUG: mid", mid , "array[mid]" , array[mid])	

        if key == array[mid]:
            return mid + 1
        elif key < array[mid]:
            answer =  self.binary_search(array[:mid] , key)
            if answer == -1:
                return -1
            else:
                return answer
        else:
            answer = self.binary_search(array[mid+1:] , key)	
            if answer == -1:
                return -1
            else:
                return mid + answer

    def main(self):
        array = [int(x) for x in input("Enter the elements with spacing: ").split()]
        key = int(input("Enter the key: "))
        
        array.sort()
        print("The sorted array is: " , array)
        print("Result at index: " , self.binary_search(array,key))



class Q4:
    def main(self):
        word_list = [str(word) for word in input("Enter the word list ").split()]
        print(word_list)

        word_list.sort()
        print(word_list)

if __name__ == "__main__":
    q1 = Q1()
    q2 = Q2()
    q3 = Q3()
    q4 = Q4()

    q1.main()
    print("------------------------")
    q2.main()
    print("------------------------")
    q3.main()
    print("------------------------")
    q4.main()
    print("------------------------")

