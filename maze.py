board = []
player = int(raw_input())
for i in xrange(0, 3):
	board.append(raw_input())	
left=0
right=0
up=0
down=0
_break = 0
for i in xrange(0,3):
	for j in xrange(0, 3):
		if(board[i][j] == '#'):
			if(i == 0):
				up +=1
			if(j == 0):
				left += 1
			if(j == 2):
				right += 1
			if(i == 2):
				down += 1
		if(board[i][j] == 'e'):
			if(i>1):
				print 'DOWN'
				_break = 1
				break
			if(i<1):
				print 'UP'
				_break = 1
				break
			if(i == 1)and(j>1):
				print 'RIGHT'
				_break = 1
				break
			if(i == 1)and(j<1):
				print 'LEFT'
				_break = 1 
				break					
if(_break == 0):
	
	ans = 'NULL'
	if(right == 3) and (up != 3):
		ans = 'UP'
	if(left == 3) and (down != 3):
		ans = 'DOWN'	
	if(up == 3) and (left == 3):
		ans = 'RIGHT'
	if(right == 3) and (down == 3):
		ans = 'LEFT'
	if(ans == 'NULL'):
				if(up == 3):
					ans = 'DOWN'
				if(down == 3):
					ans = 'UP'
				if(right == 3):
					ans = 'LEFT'
				if(left == 3):
					ans = 'RIGHT'
            
	print ans	 	
						
					
					
