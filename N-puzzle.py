from Queue import PriorityQueue
from sys import maxint
import numpy as np

# State has the following contents:
#	1.zero position
#	2.board
#	3.direction to reach there. Total direction

# Zero has the following contents:
#	1.zero[0] -> i
#	2.zero[1] -> j

def takeInput():
	_list = []
	N = int(raw_input())
	z = 'none'
	for i in xrange(0, N):
		for j in xrange(0, N):
			x = int(raw_input())
			if(x == 0):
				zero = x
			_list.append(x)

	return (zero, _list, N)

def isWin(board, N):
	if(board == getGoalState(N)):
		return 1
	else:
	 	return 0

def getGoalBoard(N):
	count =0
	_list = []
	for i in xrange(0,N*N):
		_list.append(count)
		count += 1
		
	return _list

def geti(x, N):
	return (x/N)
def getj(x, N):
	return (x%N)
def transform(i, j, N):
	if(j < N) and (i < N):
		return N*i+j
			
def Heuristic(_list, N):
	
	#zero, _list, dire = state
	dis = 0
	count = 0
	for i in xrange(0, N*N):
		s = abs(geti(i, N) - geti(_list[i], N)) + abs(getj(i, N) - getj(_list[i], N))
		dis += s
		if(s > 0):
			count += 1		
	return max(dis,count)	

def getNextState(state, N):
	
	zero, _list, direc = state
	boards = []
	zeroi = geti(zero, N)
	zeroj = getj(zero, N)
	delta = [-1, 1]
	T = []
	dup_directions = []
	dup_boards     = []
	
	for d in delta:
		if(d == -1):
			if(0 <= zeroi+d < N):
				T.append((transform(zeroi+d, zeroj, N), 'UP'))
			if(0 <= zeroj+d < N):
				T.append((transform(zeroi, zeroj+d, N), 'LEFT'))
		if(d == 1):
			if(0 <= zeroi+d < N):
				T.append((transform(zeroi+d, zeroj, N), 'DOWN'))
			if(0 <= zeroj+d < N):
				T.append((transform(zeroi, zeroj+d, N), 'RIGHT'))
	
	for t in T:
			if(0 <= t[0] < N*N):
				y = [dr for dr in direc]
				y.append(t[1])
				x = [elem for elem in _list]
				x[zero] = x[t[0]]
				x[t[0]] = 0
				boards.append((t[0], [e for e in x], [m for m in y]))
				x[:] = []
				y[:] = []
	
	return boards			
def check(visitboard, dest, N):
	count = 0
	for i in xrange(0, N*N):
		if(visitboard[i] != dest[i]):
			count += 1
	if(count == 0):
		return 0
	else:
		return 1	
				
def IDAsearch(state, goalBoard, N):
	
	Q = PriorityQueue()
	initial_cost = Heuristic(state[1], N)
	Q.put((state, initial_cost), initial_cost)
	current_threshold = initial_cost
	next_threshold    = initial_cost
	visited = []
	while(Q.empty() != True):
	
		current_threshold = next_threshold
		next_threshold    = maxint
		visit = Q.get()
		print visit
		con = 0
		if(check(visit[0][1], goalBoard, N) == 0):
				#print "fuck yeah, found it"
				return visit[0][2]
		elif(visit[1] <= current_threshold):
			if visit[0][1] not in visited:
				con = 0
			else:
				con = 1	
		if(con == 0):				
			children = getNextState(visit[0], N)
			CQ = PriorityQueue()
			for child in children:
				b = Heuristic(child[1], N)
				h =  b + 1
				if( h < next_threshold):
					next_threshold = h	
				if child[1] not in visited:
					Q.put((child, h), h)
									
		visited.append(visit[0][1])
	
#print getNextState((4,[1,2,4,6,0,5,3,7,8],[]), 3)
#print Heuristic((4,[1,2,4,6,0,5,3,7,8],[]), 3)
inp = takeInput()
out = IDAsearch((inp[0],inp[1],[]), getGoalBoard(inp[2]), inp[2])
for i in out:
	print i
