class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int result=0, left=-1;
        vector<int> position(128, -1);
        for(int i=0;i<s.size();i++)
        {
            left = max(left, position[s[i]]);  //最靠近(max)自己的重複的字
            position[s[i]]=i;
            result = max(result, i - left);    // "i - left"->window size
        }
        return result;
    }
};
