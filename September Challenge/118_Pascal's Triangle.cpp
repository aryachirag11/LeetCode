#include <iostream>
#include <vector>
using namespace std;

class Solution
{
private:
  vector<int> generateRow(int rowNum)
  {
    int element = 1;
    vector<int> row;
    row.push_back(element);
    for (int col = 1; col < rowNum; col++)
    {
      element *= (rowNum - col);
      element /= col;
      row.push_back(element);
    }
    return row;
  }

public:
  vector<vector<int>> generate(int numRows)
  {
    vector<vector<int>> triangle;
    for (int i = 1; i <= numRows; i++)
    {
      triangle.push_back(generateRow(i));
    }
    return triangle;
  }
};
int main()
{
  return 0;
}