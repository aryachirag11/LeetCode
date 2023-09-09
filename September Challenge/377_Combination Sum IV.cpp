#include <iostream>
#include <vector>

class Solution
{
private:
  // memorization DP
  int solveDP(vector<int> &nums, int target, vector<int> &dp)
  {
    // base case
    if (target < 0)
      return 0;
    if (target == 0)
      return 1;

    // check for sol in dp
    if (dp[target] != -1)
      return dp[target];

    int ans = 0;
    // check for every number
    for (int i = 0; i < nums.size(); i++)
    {
      ans += solveDP(nums, target - nums[i], dp);
    }
    dp[target] = ans; // store ans in dp

    return dp[target];
  }

  // Tabular DP
  int solveTabDP(vector<int> &nums, int target)
  {
    vector<int> dp(target + 1, 0);
    dp[0] = 1;

    for (int i = 1; i <= target; i++)
    {
      for (int j = 0; j < nums.size(); j++)
      {
        if (i - nums[j] >= 0)
          dp[i] += dp[i - nums[j]];
      }
    }
    return dp[target];
  }

public:
  int combinationSum4(vector<int> &nums, int target)
  {
    // vector<int> dp(target + 1, -1);
    // return solveDP(nums, target, dp);
    return solveTabDP(nums, target);
  }
};

using namespace std;
int main()
{
  return 0;
}