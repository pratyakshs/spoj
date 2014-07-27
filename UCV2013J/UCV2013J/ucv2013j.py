import sys
def p(n):
	ans=0
	while (n+1> 1<<ans):
		ans=ans+1
	return ans-1

while(True):
	line=sys.stdin.readline().split()
	N=int(line[0])
	if(N==0):
		break
	nums=line[1:]
	s=0
	n=p(N)
	b=((1<<n)-1)
	for i in range(b, N):
		s+=int(nums[i])
	print(s)

