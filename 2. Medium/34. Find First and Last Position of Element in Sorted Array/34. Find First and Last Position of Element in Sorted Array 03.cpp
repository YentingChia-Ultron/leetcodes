class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if(nums.size() == 0) return {-1, -1};
        int left = findLeftEqual(nums, target, 0);
        if(left >= nums.size() || nums[left] != target) return {-1, -1};
        return {left, findLeftEqual(nums, target + 1, left) - 1};
    }
    
private:
    int findLeftEqual(const vector<int>& nums, const int target, int l)
    {
        int r = nums.size();
        while(l < r)
        {
            int mid = l + (r - l) / 2;
            if(nums[mid] < target)
                l = mid + 1;
            else
                r = mid;
        }
        return l;
    }
};

