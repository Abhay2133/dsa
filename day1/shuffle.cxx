/*
given an array of size 2n [x1, x2, ..., xn, y1, y2, ..., yn]

return array in [x1, y1, x2, y2, ..., xn, yn]
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
  vector<int> shuffle(vector<int> &arr, int n)
  {
    // your code goes here
    int currPos = 1;
    int currNum = arr[currPos];
    int newPos = currPos < n ? 2 * currPos : 2 * (currPos - n) + 1;
    int newNum = arr[newPos];

    arr[newPos] = 0 - currNum;
    currPos = newPos;
    currNum = newNum;
    while (newNum > 0)
    {
      newPos = currPos < n / 2 ? 2 * currPos : 2 * (currPos - n / 2) + 1;
      newNum = arr[newPos];

      arr[newPos] = 0 - currNum;
      currPos = newPos;
      currNum = newNum;
    }

    return arr;
  }
};

int main()
{
  vector<vector<int>> testcases = {
      {2, 5, 1, 3, 4, 7},
      {1, 2, 3, 4, 4, 3, 2, 1},
      {1, 1, 2, 2}};
  Solution sol;
  for (auto test : testcases)
  {
    vector<int> answer = sol.shuffle(test, (int)(test.size() / 2));
    for (int i = 0; i < answer.size(); i++)
    {
      cout << answer[i] << (i < answer.size() - 2 ? "," : "");
    }
    cout << "\n";
  }
  return 0;
}
