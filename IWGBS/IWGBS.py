def binomial(n, k):
	if(k>(n/2)):
		return binomial(n, n-k)
	num=1
	for i in range (0, k):
		num=num*(n-i)
	den=1
	for i in range (1, k+1):
		den=den*i
	return num/den

n=int(input())
ans=1
term=1
for k in range(0, int((n+1)/2)):
	term=term*(n+1-2*k)*(n-2*k)/((n+1-k)*(k+1))
	ans=ans+term
print(ans)