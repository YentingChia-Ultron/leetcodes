class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        DFS(n, n, "", res);
        return res;
    }
private:
    void DFS(int left, int right, string tmpStr, vector<string>& res)
    {
        if(left > right)    return;
        if(left == 0 && right == 0) res.push_back(tmpStr);
        else
        {
            if(left > 0)    DFS(left - 1, right, tmpStr + '(', res);
            if(right > 0)   DFS(left, right - 1, tmpStr + ')', res);
        }
    }
};
