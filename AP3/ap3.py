import sys
import math
t=int(input())
for i in range (0, t):
	[x, y, z]=[int(i) for i in sys.stdin.readline().split()]
	a=x+y
	b=7*x+5*y+2*z
	c=12*z
	n=(b+math.sqrt(b*b-4*a*c))/(2*a)
	d=(y-x)/(n-6)
	A=x-2*d
	print(int(n))
	n=int(n)
	for j in range(0, n):
		sys.stdout.write(str(int(A+j*d))+" ")
	sys.stdout.write("\n")
