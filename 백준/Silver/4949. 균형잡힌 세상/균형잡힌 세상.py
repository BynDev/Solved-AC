def judgeBalance(lst, a, b):
    stack = []
    ans = "yes"
    
    for i in range(a, b):
        if lst[i] == '(' or lst[i] == '[':
            stack.append(lst[i])
        elif lst[i] == ')':
            if len(stack) == 0 or stack[-1] != '(':
                ans = "no"
                break
            stack.pop()
        elif lst[i] == ']':
            if len(stack) == 0 or stack[-1] != '[':
                ans = "no"
                break
            stack.pop()
    
    if len(stack) != 0:
        ans = "no"
    
    return ans

while True:
    sent = input()
    if(sent == "."):
        break
    print(judgeBalance(sent,0,len(sent)-1))