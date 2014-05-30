def isWin(board):
	"""
	Given a board checks if it is in a winning state.
 
	Arguments:
	board: a list containing X,O or -.
 
	Return Value:
	True if board in winning state. Else False
	"""
	### check if any of the rows has winning combination
	for i in range(3):
		if len(set(board[i*3:i*3+3])) is 1 and board[i*3] is not '_': return True
	### check if any of the Columns has winning combination
	for i in range(3):
		if (board[i] is board[i+3]) and (board[i] is board[i+6]) and board[i] is not '_':
			return True
	### 2,4,6 and 0,4,8 cases
	if board[0] is board[4] and board[4] is board[8] and board[4] is not '_':
		return True
	if board[2] is board[4] and board[4] is board[6] and board[4] is not '_':
		return True

	return False

def Transform(N):

	return N/3, N%3

def MinMax(player, board):

	if(len(set(board)) == 1): return 0, 4
	nextPlayer = 'X' if player == 'O' else 'O'
	if isWin(board): 
		if player is 'X' : return 1, -1
		else : return -1, -1 

	if(board.count('_') == 0): return 0, -1

	_list = []
	children = []
	for i in xrange(len(board)):
		if(board[i] == '_'):
			_list.append(i)

	for i in _list:
		board[i] = player
		ret, move = MinMax(nextPlayer, board)
		children.append(ret)
		board[i] = '_'

	if player is 'O':
		maxElement = max(children)
		return maxElement, _list[children.index(maxElement)]

	else:
		minElement = min(children)
		return minElement, _list[children.index(minElement)]

def nextMove(player, board):
	v = MinMax(player, board)[1]
	x, y = Transform(v)
	print x,
	print y
def TakeInput():
	board = []
	player = raw_input()
	for i in xrange(0,3):
		c_list = list(raw_input())
		for c in c_list:
			board.append(c)

	nextMove(player, board)

TakeInput()
