#include <string>
#include <vector>

using namespace std;

bool solution(vector<string> phone_book)
{
  for (int i = 0; i < phone_book.size(); i++)
    for (int j = 0; j < phone_book.size(); j++)
      if (phone_book[j].find(phone_book[i]) == 0 && i != j)
        return false;

  return true;
}