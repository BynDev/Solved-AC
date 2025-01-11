DP = [0] * 10000
Ans = list(range(1, 10001))

def sum_of_digits(number):
    return sum(int(digit) for digit in str(number))

for i in range(10000):
    DP[i] = i + sum_of_digits(i) 

Ans = [x for x in Ans if x not in DP]

for number in Ans:
    print(number)    