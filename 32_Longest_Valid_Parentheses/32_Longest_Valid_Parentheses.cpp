class Solution {
public:
    int longestValidParentheses(string s) {
        if(s.size() < 2) return 0;
        int result = 0, start = 0;
        stack<int> mystack;
        for(int i = 0;i<s.size();i++)
        {
            if(s[i] == '(')
                mystack.push(i);
            else
            {
                if(mystack.empty()) //invalid --> update start point
                    start = i + 1;
                else
                {
                    mystack.pop();
                    result = max(result, mystack.empty()? i - start + 1 : i - mystack.top());
                }
            }
        }
        return result;
    }
};
