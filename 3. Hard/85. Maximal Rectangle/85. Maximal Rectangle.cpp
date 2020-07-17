class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int m = matrix.size();
        if(m == 0) return 0;
        int res = 0, n = matrix[0].size();
        vector<int> heights(n + 1);
        for(int i = 0; i < m; i++)
        {
            stack<int> s;
            for(int j = 0; j < n; j++)
                heights[j] = (matrix[i][j] == '1') ? ++heights[j] : 0;
            for(int j = 0; j < n + 1; )
            {
                if(s.empty() || heights[j] >= heights[s.top()])
                    s.push(j++);
                else
                {
                    int h = heights[s.top()];
                    s.pop();
                    int w = s.empty()? j : j - s.top() - 1;
                    res = max(res, w * h);
                }
            }
        }
        return res;
    }
};
