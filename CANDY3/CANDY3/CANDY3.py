t=int(input())
for i in range(0, t):
	nl=raw_input()
	s=0
	n=int(input())
	for j in range(0, n):
		x=int(input())
		s=s+x
	if((s%n)==0):
		print("YES")
	else:
		print("NO")

