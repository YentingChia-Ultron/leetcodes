class Solution {
public:
    string longestPalindrome(string s) {
        const int n = s.length();
        if(n==1)
            return s;
        int startPos = 0;
        int maxlen = 0;
        for(int i=0; i<n-1; i++)
        {
            int paliLen = max(getPalindromeLen(i, i, s), getPalindromeLen(i, i+1, s));
            if(maxlen<paliLen)
            {
                maxlen = paliLen;
                startPos = i-(maxlen-1)/2;
            }
        }     
        return s.substr(startPos, maxlen);
    }
private:
    int getPalindromeLen(int l, int r, const string& s)
    {
        while((l>=0) && (r<s.size()) && (s[l]==s[r]))
              {
                  l--;
                  r++;
              }
        return  r-l-1;
    }
};
