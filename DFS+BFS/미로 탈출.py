from collections import deque

# n, m을 공백으로 구분하여 입력받기
n, m = map(int, input().split())

# 2차원 리스트의 map 정보 입력받기
graph = []
for i in range(n):
    graph.append(list(map(int, input())))

# 이동할 상하좌우 방향
dx = [-1, 1, 0, 0]
dy = [0, 0, -1, 1]

############################################################


# BFS 메소드 정의
def bfs(x, y):
    # 큐 구현을 위해 deque 라이브러리 사용
    queue = deque()
    queue.append((x, y))

    # 큐가 빌 때까지 반복
    while queue:
        x, y = queue.popleft()
        # 현재 위치에서 상하좌우 방향으로의 위치 확인
        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]

            # 이동한 위치가 공간을 벗어난 경우는 무시!
            if nx < 0 or ny < 0 or nx >= n or ny >= m:
                continue

            # 값이 0이면 벽이므로 무시!
            if graph[nx][ny] == 0:
                continue

            # 값이 1이라면 처음 방문하는 경우에만 최단 거리 기록
            if graph[nx][ny] == 1:
                graph[nx][ny] = graph[x][y] + 1
                queue.append((nx, ny))

    # 도착점까지의 최단 거리 반환
    return graph[n - 1][m - 1]

############################################################


print(bfs(0, 0))
