n=int(input())
ans=1
term=1
for k in range(0, int((n+1)/2)):
	term=term*(n+1-2*k)*(n-2*k)/((n+1-k)*(k+1))
	ans=ans+term
print(ans)