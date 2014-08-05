# Reminder how awesome is python for string problems. C++ sucked even for such a trivial problem.
import sys
t = int(sys.stdin.readline())
while t > 0:
    line = sys.stdin.readline().split()
    l, p, curp = 0, 0, 0
    for x in line:
        if len(x) == l:
            curp += 1
        else:
            curp = 1
            l = len(x)
        p = max(p, curp)
    print(p)
    t -= 1

