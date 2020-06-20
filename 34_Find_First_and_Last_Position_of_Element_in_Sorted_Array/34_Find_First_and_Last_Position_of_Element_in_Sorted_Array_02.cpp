class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if(nums.size() == 0) return {-1, -1};
        int left = findLeftEqual(nums, target);
        if(left == -1) return {-1, -1};
        return {left, findRightEqual(nums, target, left)};
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
    
    int findRightEqual(const vector<int>& nums, const int target,int l)
    {
        int r = nums.size();
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

