import sys
sys.setrecursionlimit(10000)
zeros=[]
ones=[]
for i in range(0, 10001):
	zeros.append(-1)
	ones.append(-1)
zeros[0]=zeros[1]=ones[0]=ones[1]=0

def numZero(n):
	if(zeros[n]!=-1):
		return zeros[n]
	zprev=numZero(n-1)
	oprev=ones[n-1]
	ones[n]=zprev+oprev
	if(n%2==0):
		zeros[n]=zprev+oprev+1
		return zeros[n]
	else:
		zeros[n]=zprev+oprev
		return zeros[n]

for line in sys.stdin:
	try:
		x=int(line)
	except ValueError:
		break
	print(numZero(x))


