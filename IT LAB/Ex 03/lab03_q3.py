import numpy

def binary_search(array , key):

	if len(array) <= 0:
		return -1

	low = 0
	high = len(array) - 1
	
	mid = (low + high)/2
	mid = int(mid)
	print("DEBUG: mid", mid , "array[mid]" , array[mid])	

	if key == array[mid]:
		return mid + 1
	elif key < array[mid]:
		answer =  binary_search(array[:mid] , key)
		if answer == -1:
			return -1
		else:
			return answer
	else:
		answer = binary_search(array[mid+1:] , key)	
		if answer == -1:
			return -1
		else:
			return mid + answer

def main():
	array = [int(x) for x in input("Enter the elements with spacing: ").split()]
	key = int(input("Enter the key: "))
	
	array.sort()
	print("The sorted array is: " , array)
	print("Result at:" , binary_search(array,key))


if __name__ == "__main__":
	main()
