class Solution {
public:
    int uniquePaths(int m, int n) {
        int res = 0;
        vector<int> map(n);
        for(int i = 0; i < n; i++)
            map[i] = 1;
        for(int i = 1; i < m; i++)
            for(int j = 1; j < n; j++)
                map[j] += map[j - 1];
        res = map[n - 1];
        return res;
    }
    
    
};


