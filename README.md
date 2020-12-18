# Algorithm
C++ (DFS/BFS, Greedy, DP, Implementation, Sorting, Search, Shortest Path, Graph)
 
## 사전 준비
- 헤더 파일
```
#include <bits/stdc++.h>
```

- cin, cout 속도 올리기
```
ios_base :: sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);
```

## C++ vector
- 정렬 / 역정렬
```
sort(arr.begin(), arr.end());
reverse(arr.begin(), arr.end());
```
- 최대값 / 최소값
```
#include <algorithm>
int min = *min_element(vec.begin(), vec.end());
int max = *max_element(vec.begin(), vec.end());
```

## C++ map
- map 생성 (여러 개)
```
map<int, vector<int>> m;
m[0] = vector<int> {1, 2, 3};
cout << m[0][2] << endl;  // 3 출력
```

## 기타 알고리즘
- [LIS(가장 긴 증가수열)](https://jason9319.tistory.com/113) 오름차순으로 정렬된 가장 긴 부분 수열 구하기
- [Union-Find (합집합 찾기)](https://twpower.github.io/115-union-find-disjoint-set) (1-2, 2-3, 4-5)로 입력받으면 (123),(45)로 묶어지는 알고리즘
- [룬(Luhn) 알고리즘](https://ko.wikipedia.org/wiki/%EB%A3%AC_%EC%95%8C%EA%B3%A0%EB%A6%AC%EC%A6%98) 신용카드 번호 검증 알고리즘(NHN 코테 출제)
- [벡터 끼리 연산](https://1coding.tistory.com/124) 벡터 요소끼리 집합 연산 가능 (정수, 문자열 등등 가능)
