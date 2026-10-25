class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        unordered_map<int,int> hash;
        vector<int> ans;
        for(int i=0;i<nums.size();i++){
            hash[nums[i]]++;
            if(hash[nums[i]]>1) ans.push_back(nums[i]);
        }
        return ans;
    }
};