from Queue import *

Visited = []
ToVisit_ = []
Walls = []
Food = []
printList = []

X = {}
Route = []


def printer():

    if(printList):
    	print len(printList)
    while(printList):
        p = printList.pop(0)
        print p[0],
        print p[1]

    print len(Route) - 1
    while(Route):
        p = Route.pop()
        print p[0],
        print p[1]

def ManhattanHeuristic(A, B):

	X1, Y1 = A
	X2, Y2 = B

	return abs(X1-X2) + abs(Y1-Y2)

def nextMove(r, c, pacman_r, pacman_c, food_r, food_c, grid):

    # BFS(r, c, pacman_r, pacman_c, food_r, food_c, grid)
    # DFS(r, c, pacman_r, pacman_c, food_r, food_c, grid)
    # UCS(r, c, pacman_r, pacman_c, food_r, food_c, grid)
    AStar(r, c, pacman_r, pacman_c, food_r, food_c, grid)


def UCS(r, c, pacman_r, pacman_c, food_r, food_c, grid):

    ToVisit = PriorityQueue()
    Food.append(tuple((food_r, food_c)))
    cost = 0
    ToVisit.put(tuple((tuple((pacman_r, pacman_c)), cost)), cost)
    ToVisit_.append(tuple((tuple((pacman_r, pacman_c)), cost)))

    while(ToVisit):
        visit = ToVisit.get()
	visit_cost = visit[1]
        found = 0

	if visit[0] in Food:
		food_r, food_c = Food.pop()
		Food.append((tuple((food_r, food_c)) , visit_cost))
		break

	for i in Visited:
		if(i[0] == visit[0]):
			found = 1
			if(i[1] > visit_cost):
				Visited.remove(i)
				children = getNeighbours(visit[0], r, c)
				for child in children:
					child = tuple((child, visit_cost + 1))
					X[child] = visit
					ToVisit.put(child, visit_cost+1)
				Visited.append(visit)

			else:
				continue

	if(found == 0):
		children = getNeighbours(visit[0], r, c)
		for child in children:
			child = tuple((child, visit_cost + 1))
			X[child] = visit
			ToVisit.put(child, visit_cost+1)
		Visited.append(visit)

    node  = Food.pop()
    start = tuple((tuple((pacman_r, pacman_c)), 0))
    while(node[0] != start[0]):
	Route.append(node[0])
	node = X[node]

    Route.append(start[0])
    printer()

def BFS(r, c, pacman_r, pacman_c, food_r, food_c, grid):

    ToVisit = Queue()
    Food.append(tuple((food_r, food_c)))
    ToVisit.put(tuple((pacman_r, pacman_c)))
    ToVisit_.append(tuple((pacman_r, pacman_c)))

    while(ToVisit):
        visit = ToVisit.get()
        ToVisit_.pop(0)
        printList.append(visit)
        if visit in Food:
            # print "found"
            break

        if visit not in Visited:
            Visited.append(visit)
            children = getNeighbours(visit, r, c)
            # print children
            while (children):
                child = children.pop(0)
                if child not in Visited:
                    if child not in ToVisit_:
                        ToVisit.put(child)
                        ToVisit_.append(child)
                        X[child] = visit

    node = Food.pop()
    start = tuple((pacman_r, pacman_c))
    while(node != start):
        Route.append(node)
        node = X[node]
    Route.append(start)
    printer()

def AStar(r, c, pacman_r, pacman_c, food_r, food_c, grid):

    ToVisit = PriorityQueue()
    goal = tuple((food_r, food_c))
    Food.append(goal)
    cost = 0
    ToVisit.put(tuple((tuple((pacman_r, pacman_c)), cost)), cost)
    ToVisit_.append(tuple((tuple((pacman_r, pacman_c)), cost)))

    while(ToVisit):
        visit = ToVisit.get()
	visit_cost = visit[1] + ManhattanHeuristic(visit[0], goal)
        found = 0

	if visit[0] in Food:
		food_r, food_c = Food.pop()
		Food.append((tuple((food_r, food_c)) , visit_cost))
		break

	for i in Visited:
		if(i[0] == visit[0]):
			found = 1
			if(i[1] > visit_cost + ManhattanHeuristic(visit[0], goal)):
				Visited.remove(i)
				children = getNeighbours(visit[0], r, c)
				for child in children:
					child = tuple((child, visit_cost + 1 + ManhattanHeuristic(visit[0], goal)))
					X[child] = visit
					ToVisit.put(child, visit_cost + 1 + ManhattanHeuristic(visit[0], goal))
				Visited.append(visit)

			else:
				continue

	if(found == 0):
		children = getNeighbours(visit[0], r, c)
		for child in children:
			child = tuple((child, visit_cost + 1 + ManhattanHeuristic(visit[0], goal)))
			X[child] = visit
			ToVisit.put(child, visit_cost + 1 + ManhattanHeuristic(visit[0], goal))
		Visited.append(visit)

    node  = Food.pop()
    start = tuple((tuple((pacman_r, pacman_c)), 0))
    while(node[0] != start[0]):
	Route.append(node[0])
	node = X[node]

    Route.append(start[0])
    printer()


def getNeighbours(visit, rows, coulmns):

    a, b = visit

    a, b = int(a), int(b)
    d = 1
    Neighbours = []

    x1 = tuple((a - d, b))
    # print x1
    if x1 not in Walls:
        if (0 < a - d < rows):
            Neighbours.append(x1)
            # print "passed"

    x2 = tuple((a, b - d))
    if x2 not in Walls:
        if (0 < b - d < coulmns):
            Neighbours.append(x2)

    x3 = tuple((a, b + d))
    if x3 not in Walls:
        if(0 < b + d < coulmns):
            Neighbours.append(x3)

    x4 = tuple((a + d, b))
    if x4 not in Walls:
        if(0 < a + d < rows):
            Neighbours.append(x4)

    return Neighbours

pacman_r, pacman_c = [int(i) for i in raw_input().strip().split()]
food_r, food_c = [int(i) for i in raw_input().strip().split()]
r, c = [int(i) for i in raw_input().strip().split()]

grid = []
for i in xrange(0, r):
    for index, j in enumerate(raw_input().strip()):
        if j == '%':
            Walls.append(tuple((i, index)))


# print Walls
nextMove(r, c, pacman_r, pacman_c, food_r, food_c, grid)
#dfs(r, c, pacman_r, pacman_c, food_r, food_c, grid)
