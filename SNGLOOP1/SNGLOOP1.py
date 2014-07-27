import sys
t = int(input())
while t > 0:
	line = sys.stdin.readline().split()
	mod = (int(line[1]) - int(line[0])) % 4
	print((3**mod)%10)
	t -= 1
