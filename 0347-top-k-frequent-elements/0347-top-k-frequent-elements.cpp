class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int,int> mpp;
        for(int i=0;i<nums.size();i++){
            mpp[nums[i]]+=1;
        }
        vector<pair<int, int>> v(mpp.begin(), mpp.end());
        sort(v.begin(), v.end(), [](auto& a, auto& b) {
            return a.second > b.second;
        });
        vector<int> ans;
        for (int i = 0; i < k; i++)
            ans.push_back(v[i].first);

        return ans;
    }
};