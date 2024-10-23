import math

n = int(input())
sum = 0
j = 0
for i in range(n,round(n/2)-1,-1):
    sum += math.comb(i, j)
    j += 1

print(sum%10007)