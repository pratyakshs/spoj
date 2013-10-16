import sys 
for t in range(int(sys.stdin.readline())): 
	p=int(sys.stdin.readline()) 
	sys.stdout.write(str(883333336*p*(p+1)*(p+2)*(3*p*(p+2)+1)%1000000003)+"\n")