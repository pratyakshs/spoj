import sys 
for t in range(int(sys.stdin.readline())): 
	n=int(sys.stdin.readline()) 
	sys.stdout.write(str((((((6*n*n*n*n*n)+(15*n*n*n*n)+(10*n*n*n)-n)/30) + (n*n*(n+1)*(n+1)/2) + (n*(n+1)*(2*n+1)/6))/4)%1000000003)+"\n")