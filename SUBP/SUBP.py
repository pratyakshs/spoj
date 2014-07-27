t=int(input())
for tt in range(1, t+1):
	s = input()
	l = [int(x) for x in s]
	table = [0] * len(s)
	for i in range(len(s)-1, -1, -1):
		table[i] = 1
		for j in range(i+1, len(s)):
			if l[j] > l[i]:
				table[i] += table[j]
	print('Case', str(tt)+':', sum(table))
