import numpy as np

def calculator(num1, num2 , option):
	switcher = {
		1: num1 + num2,
		2: num1 - num2,
		3: num1 * num2,
		4: num1 / num2,
	}
	return 	switcher.get(option,"invalid option")

def main():
	num1 = int(input("Enter number 1 "))
	num2 = int(input("Enter number 2 "))

	print("Enter 1 for addition")	
	print("Enter 2 for subtraction")	
	print("Enter 3 for multiplication")	
	print("Enter 4 for division")	

	option = int(input("Enter option"))
	print(calculator(num1,num2,option))	

if __name__ == "__main__":
	main()
	
