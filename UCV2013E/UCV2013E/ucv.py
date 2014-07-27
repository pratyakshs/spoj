import sys
sys.setrecursionlimit(10000)

factorials=[]
for i in range (0, 501):
	factorials.append(-1)

factorials[0]=1
factorials[1]=1

def fact(n):
	if(n==0):
		return 1
	if (factorials[n]!=-1):
		return factorials[n]
	else: 
		factorials[n]=n*fact(n-1)
		return factorials[n]


while (1==1):
	n=int(input())
	if(n==0):
		break
	xi=(raw_input()).split()
	xf=(raw_input()).split()
	xd=[]
	for i in range(0, n):
		xd.append(int(xf[i])-int(xi[i]))
	#	print xd[i]
	sum=0
	for i in range(0, n):
		sum=sum+xd[i]
#	print(sum)
	ans=fact(sum)
	for i in range(0, n):
		#print("fact("+str(xd[i])+")="+str(fact(xd[i])))
		ans=(ans/factorials[xd[i]])
	

 	print(ans%1000000007)

# n=int(input())
# print(fact(n))