import sys
t=int(raw_input())
for i in range (0, t):
	[m, n]=[int(i) for i in sys.stdin.readline().split()]
	if(m<n):
		m,n=n,m
	if(m&1):
		if(n&1):
			sys.stdout.write(str((n+1)*m/2)+'\n')
		else:
			sys.stdout.write(str((m+1)*n/2)+'\n')
	else:
		if(n&1):
			sys.stdout.write(str(m*(n+1)/2)+'\n')
		else:
			sys.stdout.write(str(m*n/2)+'\n')
