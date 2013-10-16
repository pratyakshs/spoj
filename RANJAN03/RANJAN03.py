def bin(n):
	ans=1
	for i in range(0, n):
		ans=ans*(2*n-i)/(i+1)
	return ans

for i in range(1, 32):
	print(str(bin(i))+',')