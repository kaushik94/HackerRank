alpha = ['a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z']
def count():
	strings = raw_input()
	length = len(strings)
	chars = 0
	for i in alpha:
			if(strings.count(i)%2 != 0):
					chars += 1

	if((chars == 0) and (length%2 == 0)):
			print "YES"

	if(chars == 1):
		if(length%2 == 1):
			print "YES"

		else:
			print "NO"

	if(chars > 1):
		print "NO"
count()
