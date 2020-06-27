class Solution {
public:
    int trap(vector<int>& height) {
        int result = 0, n = height.size(), maxWall = 0;
        vector<int> leftMax(n, 0), rightMax(n, 0);
        
        //find left max wall
        for(int i = 0; i < n; i++)
        {
            leftMax[i] = maxWall;
            maxWall = max(maxWall, height[i]);
        }
        
        maxWall = 0;
        //find right max wall
        for(int i = n - 1; i >= 0; i--)
        {
            rightMax[i] = maxWall;
            maxWall = max(maxWall, height[i]);
        }
        
        //find & add water height
        for(int i = 0; i < n; i++)
        {
            int waterHeight = min(leftMax[i], rightMax[i]);
            if(waterHeight > height[i])
                result += waterHeight - height[i];
        }
        
        return result;
    }
};
