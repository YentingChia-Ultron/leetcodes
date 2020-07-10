class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> latterCount(128, 0);
        int left = 0, count = 0, minLen = INT_MAX, resLeft = -1;
        for(char c : t) ++latterCount[c];
        for(int i = 0; i < s.size(); i++)
        {
            if(--latterCount[s[i]] >= 0) count++;
            while(count == t.size())
            {
                int nowLen = i - left + 1;
                if(nowLen < minLen)
                {
                    minLen = nowLen;
                    resLeft = left;
                }
                if(++latterCount[s[left]] > 0) --count;
                left++;
            }
        }
        return (resLeft == -1)? "":s.substr(resLeft, minLen);
    }
};
