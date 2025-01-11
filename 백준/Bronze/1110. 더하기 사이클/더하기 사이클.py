N = int(input())
ans = N
count = 0
while(True):
    count += 1
    P = N // 10 + N % 10
    N = P % 10 + (N % 10) * 10
    if N == ans:
        break
print(count)