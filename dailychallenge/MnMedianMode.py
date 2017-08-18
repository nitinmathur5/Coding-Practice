from collections import Counter
if __name__ == '__main__':
	n= input()
	n = int(n)
	assert (n <= 2500)
	arrayElements = []
#	for x in range(0,n):
#		iE = int(input())
#		assert (iE <= 100000)
#		arrayElements.insert(x, iE)
#	arrayElements = sorted(arrayElements)
	arrayElements = raw_input().split()
	for x in range(0,n):
		e = arrayElements.pop(x)
		arrayElements.insert(x,int(e))

	arrayElements = sorted(arrayElements)

	sum = 0
	for x in range (0,n):
		sum += float(arrayElements[x])

	if n%2 == 1:
		median = float(arrayElements[n/2])
	else:
		median = (float((arrayElements[(n-1)/2]) + float(arrayElements[n/2]))/2.0)

	print "mean   = %.1f" % (sum/n)
	print "median = %.1f" %median
	#print "mode   = %.1f", arrayElements[n-1]
	#get a count of each value, if its duplicate, then increase the counter
	#print sorted(sorted (Counter(arrayElements).items(), key = lambda x: x[1], reverse = False))
	mode = sorted(sorted (Counter(arrayElements).items(), key = lambda x: x[1], reverse = False))[0][0]
	print "mode   = " + str(mode)

