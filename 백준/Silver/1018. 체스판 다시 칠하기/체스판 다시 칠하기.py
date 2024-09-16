n,m = map(int,input().split())

board =[]

for _ in range(n):
    board.append(input())

paintCount = []

for k in range(n-7):
    for l in range(m-7):
        case1 = 0
        case2 = 0
        for i in range(k,k+8):
            for j in range(l,l+8):
                if((i + j) % 2 == 0):
                    if(board[i][j] == 'W'):
                        case1 += 1
                    elif(board[i][j] == 'B'):
                        case2 += 1
                else:
                    if board[i][j] == 'B':
                        case1 += 1
                    elif board[i][j] == 'W':
                        case2 += 1
                    
        if (case1 > case2):
            paintCount.append(case2)
        else:
            paintCount.append(case1)
        
print(min(paintCount))        