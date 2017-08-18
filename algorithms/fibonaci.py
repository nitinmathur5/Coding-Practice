
if __name__ == '__main__':
	n= input()
	n = int(n)
	assert (n <= 100)
	element1 = 0
	element2 = 1
	print element1, element2,
	for i in range(2,n):
		elementN = element1+element2
		print elementN,
		element1 = element2
		element2 = elementN



