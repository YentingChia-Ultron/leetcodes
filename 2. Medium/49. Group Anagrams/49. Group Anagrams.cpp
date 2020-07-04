class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        unordered_map<string, int> mymap;
        for(int i = 0, j = 0; i < strs.size(); i++)
        {
            string str = strs[i];
            sort(str.begin(), str.end());
            if(mymap.count(str) > 0)
                res[mymap[str]].push_back(strs[i]);
            else
            {
                mymap[str] = j;
                res.push_back({strs[i]});
                j++;
            }
        }
        
        return res;
    }
};
