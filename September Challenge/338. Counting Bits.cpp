#include <iostream>
#include <vector>
using namespace std;

// brute force
int getBits(int n)
{
  int cnt = 0;
  while (n)
  {
    n = n & n - 1;
    cnt++;
  }
  return cnt;
}
vector<int> countBits(int n)
{
  vector<int> ans;
  for (int i = 0; i <= n; i++)
    ans.push_back(getBits(i));
  return ans;
}

// optimal solution
vector<int> countBits(int n)
{
  vector<int> ans(n + 1, 0);
  for (int i = 1; i <= n; i++)
  {
    ans[i] = ans[i / 2] + (i % 2);
  }
  return ans;
}
int main()
{
  return 0;
}