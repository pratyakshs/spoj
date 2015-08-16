import random
t = 1
print(t)
n = 10000
u = 10000
print(n, u)
for i in range(u):
	l, r = random.randint(0, n-1), random.randint(0, n-1)
	print(min(l, r), max(l, r), random.randint(0, n-1))
q = 10000
print(q)
for i in range(q):
	print(i)

