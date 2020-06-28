class Solution {
public:
    int jump(vector<int>& nums) {
        int maxPos = 0, current = 0,result = 0;
        for(int i = 0; i < nums.size() - 1; i++)
        {
            maxPos = max(maxPos, nums[i] + i);
            if(i == current)
            {
                ++result;
                if(maxPos >= nums.size() - 1)
                    return result;
                current = maxPos;
            }
        }
        return result;
    }
};
