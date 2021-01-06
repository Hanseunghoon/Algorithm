#include <bits/stdc++.h>

using namespace std;

string solution(vector<string> participant, vector<string> completion)
{
  string answer = "";

  vector<string> res(1);
  vector<string>::iterator iter;

  sort(participant.begin(), participant.end());
  sort(completion.begin(), completion.end());

  iter = set_difference(participant.begin(), participant.end(), completion.begin(), completion.end(), res.begin());
  res.resize(iter - res.begin());

  answer = res[0];

  return answer;
}