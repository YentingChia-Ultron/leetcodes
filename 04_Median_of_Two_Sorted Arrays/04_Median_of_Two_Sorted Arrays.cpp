class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size(), n2 = nums2.size();
        //keep first array with smaller size
        if (n1>n2)
            return findMedianSortedArrays(nums2, nums1);
        double result=0;
        int k = (n1 + n2 + 1) / 2;
        
        //using binary search
        int left = 0, right = n1;
        while(left < right)
        {
            int m1 = left + (right - left) / 2 ;
            int m2 = k - m1;
            if(nums1[m1] < nums2[m2-1])
                left = m1 + 1;
            else
                right = m1;
        }
        
        int m1 = left;
        int m2 = k - m1;
        result = max(m1 <= 0 ? INT_MIN : nums1[m1 - 1],
                     m2 <= 0 ? INT_MIN : nums2[m2 - 1]);
        //it's even
        if((n1 + n2) % 2 == 0)
        {
            result+= min(m1 >= n1 ? INT_MAX : nums1[m1],
                         m2 >= n2 ? INT_MAX : nums2[m2]);
            result*=0.5;
        }
        return result;
    }
};
