An = int(raw_input())
A = map(int, raw_input().split())
Bn = int(raw_input())
B = map(int, raw_input().split())
_print = []
for item in B:
	if (B.count(item) > A.count(item)):
		if(item not in _print):
			_print.append(item)
			#print item
		
for x in _print:
		print x,
