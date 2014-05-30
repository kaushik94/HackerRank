answers = []
N = int(raw_input())
_input = []

for i in xrange(0, N):
	_input.append(int(raw_input()))
_inputX = sort(set(_input))
for i in _inputX:
	_sum += i
	
print _sum 
