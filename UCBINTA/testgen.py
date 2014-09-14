n = int(input())
import random
ans = [int(10*random.random()) for i in xrange(n)]

f = open('output', 'w')
for x in ans:
    f.write(str(x) + ' ')
    
f.close()
f = open('input', 'w')
f.write(str(n)+'\n')
for i in range(n):
    for j in range(n):
        if i == j:
            f.write('0 ')
        else:
            f.write(str(ans[i]+ans[j]) + ' ')
    f.write('\n')
        
