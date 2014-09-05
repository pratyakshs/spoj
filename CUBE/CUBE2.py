import sys
import math
t=sys.stdin.readline()
t=int(t)
for i in range(t):
    [a,b]=(sys.stdin.readline()).split()
    a=int(a)
    b=int(b)
    if a==1:
        sys.stdout.write("1\n")
    else :
        sys.stdout.write(str((a**b)-((a-2)**b))+"\n")
