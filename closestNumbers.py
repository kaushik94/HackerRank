from sys import maxint

N = int(raw_input())
_list = map(int, raw_input().split())
_list.sort()
numbers = []
structs = []
e = maxint
diffs = []
for i in xrange(0, N-2):
	if( e >= abs( _list[i] - _list[i+1] )):
		e = abs(_list[i] - _list[i+1])
		structs.append((_list[i], _list[i+1], e))
		diffs.append(e)
diffs.sort()
_pList = []
for struct in structs:
		if(diffs[0] == struct[2]):
			_pList.append(struct[0])
			_pList.append(struct[1])
PList = set(_pList)	
for number in _pList:
	print number,
