def FizzBuzz(ans):
    if(ans % 3 == 0 and ans % 5 == 0):
            print("FizzBuzz")
    elif(ans % 3 == 0 and ans % 5 != 0):
            print("Fizz")
    elif(ans % 3 != 0 and ans % 5 == 0):
            print("Buzz")
    else:
        print(ans)

lst = []

for i in range(3):
    lst.append(input())

for j in range(len(lst)):
    if(lst[j] != "Fizz" and lst[j] != "Buzz" and lst[j] != "FizzBuzz"):
        ans = int(lst[j]) + (3 - j)

FizzBuzz(ans)