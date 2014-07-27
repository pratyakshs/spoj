t=int(input())
for i in range(0, t):
	n=int(input())
	n2=n*n
	n3=n2*n
	n4=n3*n
	n5=n4*n
	print((((6*n5)+(30*n4)+(50*n3)+(30*n2)+(4*n))/120)%1000000003)