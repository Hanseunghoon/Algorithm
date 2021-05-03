from collections import deque

############################################

n, m, k, x = map(int, input().split())

# 도시 수를 고려하여 graph의 크기 결정
# 도시는 4개지만 번호가 1부터 시작이라 5개를 만들어 여유롭게 사용
graph = [[] for _ in range(n + 1)]

# 인접 리스트 형태 - 모든 도로 정보 입력
for _ in range(m):
    a, b = map(int, input().split())
    graph[a].append(b)

# 예제 그래프 : graph = [[], [2, 3], [3, 4], [], []]

# 모든 도시에 대한 최단 거리 초기화
distance = [-1] * (n + 1)
# 출발 도시까지의 거리는 당연히 0
distance[x] = 0

############################################
# BFS 수행
queue = deque([x])

while queue:
    now = queue.popleft()

    # 현재 도시에서 이동 가능한 모든 도시 확인
    for next in graph[now]:
        # 아직 방문하지 않은 도시는 -1
        if distance[next] == -1:
            # 최단거리 갱신, 현재 노드의 값보다 + 1
            distance[next] = distance[now] + 1
            # 갱신한 노드의 인덱스를 큐에 삽입
            queue.append(next)

############################################

# 최단 거리가 K인 모든 도시의 번호를 오름차순으로 출력
check = False
for i in range(1, n + 1):
    if distance[i] == k:
        print(i)
        check = True

# 만약 최단 거리가 K인 도시가 없다면, -1 출력
if check == False:
    print(-1)
