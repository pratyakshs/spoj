
def mulmod(a, b, c):
	x = 0 
	y = a % c
	while (b > 0):
		if(b%2 == 1):
			x = (x+y)%c
		y = (y*2)%c
		b >>= 1
	return x%c;



def modexp(base, exponent, modulo):
	ans=1;
	while (exponent>0):
		if(exponent%2==1):
			ans=mulmod(ans, base, modulo)
		exponent>>=1
		base=mulmod(base, base, modulo)
	return ans


t=int(input())
while t>0:
    n=int(input())
    print modexp(2, n-1, 1000000007)
    t=t-1


