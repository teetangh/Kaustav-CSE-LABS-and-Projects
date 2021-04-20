import os

def old():
	file1 = open("input2.txt" , "r")
	file2 = open("output2.txt" , "w+")
	

	file1.seek(0,os.SEEK_END)	
	
	while(file1):
		file1.seek(-2,os.SEEK_CUR)
		temp = file1.read(1)
		temp = str(temp , "utf-8")	
		file2.write(temp)	

def main():	
	with open("input2.txt" , "r") as file1:
		data = file1.read()
	data_1 = data[::-1]

	file2 = open("output2.txt" , "w")
	file2.write(data_1)
	print(file2.read())


if __name__ == "__main__""":
	main()
