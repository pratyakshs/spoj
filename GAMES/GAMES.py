import fractions
t = int(input())
for i in range(0,t):
    x = float(input())
    x = x * 100000
    print int(100000/fractions.gcd(100000, x))
