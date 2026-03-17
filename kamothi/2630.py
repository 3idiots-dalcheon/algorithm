import sys
input=sys.stdin.readline

n = int(input().strip())
arr = [list(map(int,input().rstrip().split())) for _ in range(n)]

blue = 0
white = 0
        
def rec(x, y, s):
    flag = True
    global blue
    global white
    for i in range(x,x+s):
        for j in range(y,y+s):
            if arr[x][y] != arr[i][j]:
                rec(x,y,s//2)
                rec(x,y+s//2,s//2)
                rec(x+s//2,y,s//2)
                rec(x+s//2,y+s//2,s//2)
                return
        
    if arr[x][y] == 0:
        white += 1
    else:
        blue += 1


rec(0,0,n)

print(white)
print(blue)
