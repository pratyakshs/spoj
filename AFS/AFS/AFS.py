import sys
sys.setrecursionlimit(1000000)

table=[]
for i in range(0, 1000000):
	table.append(-1)

table[0]=0
table[1]=0

sumdivs=[]
for i in range(0, 1000000):
	sumdivs.append(-1)


def sumdiv(num):
	if(sumdivs[num]!=-1):
		return sumdivs[num]
	s=0
	step=1
	if(num%2==1):
		step=2
	i=1
	while (i*i<=num):
		if(num%i==0):
			if(i*i==num):
				s=s+i
			else:
				s=s+i+(num/i)
		i=i+step
	sumdivs[num]=s-num
	return sumdivs[num]



def afs(n):
	if(table[n]!=-1):
		return table[n]
	else:
		table[n]=afs(n-1)+sumdiv(n)
		return table[n]

m=500
while(m<1000000):
	afs(m)
	m=m+500
	
t=int(input())
for i in range(0, t):
	x=int(input())
	print(afs(x))