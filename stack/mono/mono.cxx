// start 4:58 PM
#include <stack>
#include <iostream>
#include <vector>
#include <fstream>

#include "../../util/toString.cxx"
#include "../../util/fs.cxx"
#include "input.cxx"

class Solution
{
public:

  std::vector<int> nextSmallerToRight(std::vector<int> &arr){
    std::vector<int> ans(arr.size());
    std::stack<int> mono;

    for(int i=arr.size()-1; i>=0; i--)
    {
      while(!mono.empty() && arr[i] <= mono.top())
        mono.pop();
      if (mono.empty())
        ans[i] = -1;
      else
        ans[i] = mono.top();
      mono.push(arr[i]);
    }
    return ans;
  }

  std::vector<int> nextGreaterToLeft(std::vector<int> &arr)
  {
    std::vector<int> res(arr.size());
    std::stack<int> mono;

    for (int i = 0; i < arr.size(); i++)
    {
      while (!mono.empty() && arr[i] >= mono.top())
        mono.pop();
      if (mono.empty())
        res[i] = -1;
      else
        res[i] = mono.top();
      mono.push(arr[i]);
    }
    return res;
  }
};

void runner()
{
  Solution sol;
  for (auto testcase : testcases)
  {
    auto ans = sol.nextSmallerToRight(testcase);
    std::string output = dsa::toString(ans);
    std::cout << output << "\n";
    dsa::appendFile(std::string("output.txt"), output);
  }
}

int main()
{
  runner();
  return 0;
}