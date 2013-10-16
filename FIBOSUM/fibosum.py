fiblist=[]
for i in range(0, 10000000):
	fiblist.append(-1)

fiblist[0]=0
fiblist[1]=1
fiblist[2]=1
fiblist[3]=2
fiblist[4]=3

def fib(n):
	if(n < 10000000 and fiblist[n]!=-1):
		return fiblist[n]
	k=int(n/2)
	fkp1=fib(k+1)
	fk=fib(k)

	if(n<10000000):
		if(n%2==1):
			fiblist[n]=fkp1*fkp1+fk*fk
			return fiblist[n]
		else:
			fiblist[n]=fk*(2*fkp1-fk)
			return fiblist[n]
	else:
		if(n%2==1):
			return fkp1*fkp1+fk*fk
		else:
			return fk*(2*fkp1-fk)

t=int(input())

for i in range(0, t):
	m,n=raw_input().split()
	print((fib(int(n)+2)-fib(int(m)+1))%1000000007)