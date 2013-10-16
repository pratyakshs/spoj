def binomial(n, k):
	ans=1
	num=n
	for i in range (1, k+1):
		ans=ans*num
		num=num-1
	for i in xrange(1,k+1):
		ans=ans/i
	return ans

t=int(input())
for i in range(0, t):
	string=raw_input()
	if (not string):
		n, k=raw_input().split()
	else:
		n,k=string.split()
	n=int(n)
	k=int(k)
	bk1=binomial(n,k-1)
	print((bk1*bk1*(n-k+1)/(n*k))% 1000000007)

