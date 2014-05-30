import math
def C(N, r):
	f = math.factorial
	return f(N) / f(r) / f(N-r)
N = int(raw_input())
X = len(set(map(int, raw_input().split())))
print C(X, 3)
