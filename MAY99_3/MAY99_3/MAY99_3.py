import fractions
t=int(input())
while(t>0):
	the_string = raw_input()
	x, y, z= the_string.split()
	x=int(x)
	y=int(y)
	z=int(z)
	if(z > x and z > y):
		print("NO")
	else:
		g = fractions.gcd(x,y)
		if(z % g == 0):
			print("YES")
		else:
			print("NO")
	t=t-1