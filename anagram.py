
Answers = []
alpha = ['a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z']
def count():
	strings = raw_input()
	length = len(strings)
	x_count = []
	y_count = []
	if(length%2 == 0):
		chars = 0
		y = strings[length/2:]
		x = strings[:length/2]
		for i in alpha:
				chars += abs(x.count(i) - y.count(i))
		chars = chars/2	
		Answers.append(chars)
	else:
		Answers.append(-1)

T = int(raw_input())
for i in xrange(0, T):
	count()
for i in xrange(0, T):
	print Answers[i]
