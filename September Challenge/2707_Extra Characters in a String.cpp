#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
class Solution
{
public:
  int f(int index, string &s, unordered_map<string, bool> &mp, vector<int> &dp)
  {
    if (index >= s.size())
      return 0;

    if (dp[index] != -1)
      return dp[index];

    string curr = "";
    int res = s.size();
    for (int i = index; i < s.size(); i++)
    {
      curr.push_back(s[i]);
      int extraCount = curr.size();
      if (mp[curr])
        extraCount = 0;

      extraCount += f(i + 1, s, mp, dp);
      res = min(res, extraCount);
    }
    return dp[index] = res;
  }

  int minExtraChar(string s, vector<string> &dictionary)
  {
    unordered_map<string, bool> mp;
    for (auto &word : dictionary)
      mp[word] = true;

    vector<int> dp(s.size(), -1);

    return f(0, s, mp, dp);
  }
};
int main()
{
  return 0;
}