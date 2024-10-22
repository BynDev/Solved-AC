def fib(n):
    f = [0] * (n + 1)
    if(n == 0):
        f[0] = 1
    if(n == 1):
        f[1] = 0
    elif (n>1):
        f[2] = 1
        for i in range(3,n+1):
            f[i] = f[i-1] + f[i-2]

    return f[n]

def fib2(n):
    f = [0] * (n + 1)
    if (n>0):
        f[1] = 1
        for i in range(2,n+1):
            f[i] = f[i-1] + f[i-2]

    return f[n]

T = int(input())
            
for i in range(T):
    num = int(input())
    print(fib(num),fib2(num))