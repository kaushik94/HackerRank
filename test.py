import copy
y = []
x = [1,2,3,4]
x = [4,3,2,1]
y.append([i for i in x])
y[-1].append(16)
print x
print y
