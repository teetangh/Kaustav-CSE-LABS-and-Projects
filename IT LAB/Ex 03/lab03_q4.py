
def main():
	word_list = [str(word) for word in input("Enter the word list").split()]
	print(word_list)

	word_list.sort()
	print(word_list)

if __name__ == "__main__":
	main()
