class Solution {
public:
  int largestRectangleArea(vector<int>& heights) {
      int res = 0;
      heights.push_back(0);
      stack<int> s;
      for(int i = 0; i < heights.size();)
      {
          if(s.empty() || heights[i] >= heights[s.top()])
              s.push(i++);
          else
          {
              int h = heights[s.top()];
              s.pop();
              int w = s.empty()? i : i - s.top() - 1;
              res = max(res, w * h);
          }
      }
      return res;
  }
};
