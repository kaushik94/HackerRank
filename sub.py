def modular(sub, m):
	if(len(sub) < 100):
		return int(sub)%m
	else:
		while(len(sub) > 100):
			sub  = str(int(sub[:100])%m) + sub[100:]
		return int(sub)%m		
string = raw_input()
subs = []
m = 1000000007
sumE=0
for i in xrange(0, len(string)):
	for j in xrange(1, len(string)-i+1):
			sumE += modular(string[i:i+j], m)
sumE %= m
print sumE	
