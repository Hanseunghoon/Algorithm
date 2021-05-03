# n, m을 공백으로 구분하여 입력받기
n, m = map(int, input().split())

# 2차원 리스트의 map 정보 입력받기
graph = []
for i in range(n):
    graph.append(list(map(int, input())))

############################################################


def dfs(x, y):
    # x, y가 범위를 벗어나면 종료
    if x < 0 or x >= n or y < 0 or y >= m:
        return False

    # 방문되지 않은 노드라면
    if graph[x][y] == 0:
        # 해당 노드 방문 처리
        graph[x][y] = 1

        # 노드의 주변을 상하좌우 모두 재귀적 호출
        dfs(x-1, y)
        dfs(x+1, y)
        dfs(x, y-1)
        dfs(x, y+1)
        return True

    return False

############################################################


# 모드 노드를 검사하며 DFS 수행 - 음료수 채우기
result = 0
for i in range(n):
    for j in range(m):
        if dfs(i, j) == True:
            result += 1

print(result)
