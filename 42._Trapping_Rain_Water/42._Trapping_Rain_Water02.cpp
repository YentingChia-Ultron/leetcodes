class Solution {
public:
    int trap(vector<int>& height) {
        int result = 0, n = height.size(), maxWall = 0;
        vector<int> maxWalls(n, 0);
        
        //find left max wall
        for(int i = 0; i < n; i++)
        {
            maxWalls[i] = maxWall;
            maxWall = max(maxWall, height[i]);
        }
        
        maxWall = 0;
        //find right max wall & find water height & add water height to result
        for(int i = n - 1; i >= 0; i--)
        {
            maxWalls[i] = min(maxWall, maxWalls[i]);
            maxWall = max(maxWall, height[i]);
            if(maxWalls[i] > height[i])
                result += maxWalls[i] - height[i];
        }
        
        return result;
    }
};
