from collections import deque

cx, cy = map(int, input('중심 좌표 입력: ').split())
radius = int(input('원의 반지름 입력: '))

dp = [[-1 for i in range(radius*2+1)] for j in range(radius*2+1)]
answer = 0
dx = [-1, 1, 0, 0]
dy = [0, 0, -1, 1]

def getArea(i, j):
    queue = deque([])
    queue.append([i, j])

    while(queue):
        cur = queue.popleft()

        left = cur[0]
        right = cur[1]
        if(left<0 or right<0 or left>=len(dp) or right>= len(dp)):                  continue
        if (dp[left][right]==-1 or dp[left][right] == 0 or dp[left][right] == 2):   continue
    
        dp[left][right] = 2
        for k in range(4):
            queue.append([left+dx[k], right+dy[k]])

def bfs(i, j):
    queue = deque([])
    queue.append([i, j])

    while(queue):
        cur = queue.popleft()

        x = cur[0] - cx + radius
        y = cur[1] - cy + radius

        if(x<0 or x>=len(dp) or y<0 or y>=len(dp)):
            continue;

        if(dp[x][y]!=-1):
            continue

        if((cur[0]-cx) * (cur[0]-cx) + (cur[1] - cy)*(cur[1] - cy) >= radius*radius):
            dp[x][y] = 0
            continue

        verify = 0
        left = abs(cur[0])
        right = abs(cur[1])
        while(left != 0):
            verify += left%10
            left = left // 10

        while(right != 0):
            verify += right%10
            right = right // 10


        if(verify >16 and verify % 2 == 1):
            dp[x][y] = 0
        else:
            dp[x][y] = 1

        for k in range(4):
            queue.append([cur[0]+dx[k], cur[1]+dy[k]])
        
            
bfs(cx, cy)

getArea(radius, radius)

answer = 0
for i in range(len(dp)):
    answer += dp[i].count(2)
    
print(answer-1)