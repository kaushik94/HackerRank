def product(iterable):
    return reduce(operator.mul, iterable, 1)

def npr(n, r):
	return product(range(r+1, n+1))
