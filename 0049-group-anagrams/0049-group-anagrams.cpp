class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string, vector<string>> mpp;
        for(int i=0;i<strs.size();i++){
            string a=strs[i];
            sort(a.begin(), a.end());
            mpp[a].push_back(strs[i]);
        }
        vector<vector<string>> ans;
        for (auto& entry : mpp)
            ans.push_back(entry.second);
        return ans;
    }
};