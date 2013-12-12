import sys
sys.setrecursionlimit(2100000000)
for line in sys.stdin:
	n=1
	curr=int(line)
	while(curr!=1):
		if(curr%2==0):
			curr=curr>>1
		else:
			curr=3*curr+1
		n=n+1
	sys.stdout.write(str(n)+"\n")
