def binomial(n, r):
	ans=1
	term=n
	for i in range(1, r+1):
		ans=ans*term/i
		term=term-1
	return ans

the_string = raw_input()
n, r = the_string.split()
print(binomial(int(n)-1,int(r)-1)%10000007)