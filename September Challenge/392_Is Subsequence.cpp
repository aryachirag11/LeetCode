#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  bool isSubsequence(string s, string t)
  {
    int n = s.size();
    int m = t.size();
    if (n == 0)
      return true;
    if (m < n)
      return false;

    int i = 0, j = 0;
    while (i < n && j < m)
    {
      if (s[i] == t[j])
        i++;

      j++;
    }
    return i == n;
  }
};

int main()
{
  return 0;
}