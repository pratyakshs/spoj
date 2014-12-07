import sys
for line in sys.stdin:
	n = int(line)
	if n < 2:
		print n
	else:
		print 2*n-2