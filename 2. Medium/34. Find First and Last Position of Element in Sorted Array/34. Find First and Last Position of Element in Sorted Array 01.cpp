class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if(nums.size() == 0) return {-1, -1};
        return {findLeftEqual(nums, target), findRightEqual(nums, target)};
    }
    
private:
    int findLeftEqual(const vector<int>& nums, const int target)
    {
        int l = 0, r = nums.size();
        while(l < r)
        {
            int mid = l + (r - l) / 2;
            if(nums[mid] < target)
                l = mid + 1;
            else
                r = mid;
        }
        if(l >= nums.size() || nums[l] != target)
            return -1;
        return l;
    }
    
    int findRightEqual(const vector<int>& nums, const int target)
    {
        int l = 0, r = nums.size();
        while(l < r)
        {
            int mid = l + (r - l) / 2;
            if(nums[mid] <= target)
                l = mid + 1;
            else
                r = mid;
        }
        l--;
        if(l < 0 || nums[l] != target)
            return -1;
        return l;
    }
};

