alpha = ['a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z']
T = int(raw_input())
_list = []
for i in xrange(0, T):
		X = list(raw_input())
		for elem in alpha:
			if(X.count(elem) > 0):
				_list.append(elem)
		alpha[:] = []
		alpha = list(_list)
		_list[:] = []
print len(alpha)
