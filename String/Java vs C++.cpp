#include <iostream>
#include <string>

using namespace std;

int main(void)
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  string s, res;
  bool cpp = false, java = false, err = false;
  cin >> s;

  for (int i = 0; i < s.length(); i++)
  {

    // 대문자인 경우
    if (s[i] >= 'A' && s[i] <= 'Z')
    {

      // 첫 문자가 대문자거나, C++를 추적했었던 경우 오류!
      if (!i || cpp)
      {
        err = true;
        break;
      }

      java = true;
      res += "_";
      res += s[i] + 32;
    }
    // '_'인 경우
    else if (s[i] == '_')
    {

      // 첫 문자나 마지막 문자가 '_'거나,
      // 자바를 추적했었던 경우 오류!
      if (!i || java || i == s.length() - 1 || s[i + 1] == '_' || (s[i + 1] >= 'A' && s[i + 1] <= 'Z'))
      {
        err = true;
        break;
      }

      cpp = true;
      res += s[++i] - 32;
    }
    // 그 외는 문자 복사
    else
      res += s[i];
  }

  if (err)
    cout << "Error!" << endl;
  else
    cout << res << endl;
}