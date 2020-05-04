class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if(digits.size() == 0) return {};
        vector<string> res;
        string phoneLett[10];
        phoneLett[0] = " ";
        phoneLett[1] = "";
        phoneLett[2] = "abc";
        phoneLett[3] = "def";
        phoneLett[4] = "ghi";
        phoneLett[5] = "jkl";
        phoneLett[6] = "mno";
        phoneLett[7] = "pqrs";
        phoneLett[8] = "tuv";
        phoneLett[9] = "wxyz";
        string str;
        dfs(digits,phoneLett, str, 0, res);
        return res;
    }
private:
    void dfs(const string& digits, const string (&phoneLett) [10], string str, const int i, vector<string>& res)
    {
        if(i == digits.size())
        {
            res.push_back(str);
            return;
        }
        else
        {
            for(const char c : phoneLett[digits[i] - '0'])
            {
                str.push_back(c);
                dfs(digits,phoneLett, str, i + 1, res);
                str.pop_back();
            }
        }
    }
};
