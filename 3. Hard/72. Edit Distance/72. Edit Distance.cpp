class Solution {
public:
    int minDistance(string word1, string word2) {
        int l1 = word1.length(), l2 = word2.length();
        vector<vector<int>>minMap(l1 + 1,  vector<int>(l2 + 1, 0));
        for(int i = 1; i <= l1; i++)
            minMap[i][0] = i;
        for(int j = 1; j <= l2; j++)
            minMap[0][j] = j;
          
        for(int i = 1; i <= l1; i++)
            for(int j = 1; j <= l2; j++)
            {
                int c = (word1[i - 1] == word2[j - 1]) ? 0 : 1;
                minMap[i][j] = min(minMap[i - 1][j - 1] + c, min(minMap[i][j - 1], minMap[i - 1][j]) + 1);
            }
        
        return minMap[l1][l2];
    }
};
