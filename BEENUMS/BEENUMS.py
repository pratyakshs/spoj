import sys, math
def is_square(apositiveint):
  if apositiveint == 0 or apositiveint == 1:
  	return True
  x = apositiveint // 2
  seen = set([x])
  while x * x != apositiveint:
    x = (x + (apositiveint // x)) // 2
    if x in seen: return False
    seen.add(x)
  return True

for line in sys.stdin:
	n = int(line)
	if n == -1:
		break
	if ((n-1) % 3 != 0):
		print 'N'
		continue
	n = (n-1)/3
	if (is_square(1+4*n)):
		print 'Y'
	else:
		print 'N'