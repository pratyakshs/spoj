import sys, math

t = int(sys.stdin.readline())

while t > 0:
    n, i = (sys.stdin.readline()).split()
    n, i = float(i), float(i)
    pow1 = math.pow(2, i-3)
    ans = ((i-1)*i*(n-2)*(n-2)*pow1) + (4*pow1*i*(n-2)) + (8*pow1)
    print int(ans)
    t = t - 1
