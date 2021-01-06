#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> scoville, int K)
{
  int answer = 0;
  int low, second;

  priority_queue<int, vector<int>, greater<int>> sc(scoville.begin(), scoville.end());

  while (sc.top() < K)
  {

    if (sc.size() == 1)
      return -1;

    low = sc.top();
    sc.pop();

    second = sc.top();
    sc.pop();

    sc.push(low + second * 2);
    answer++;
  }

  return answer;
}