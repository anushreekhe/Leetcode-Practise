class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> ans;
        for(int i=0;i<nums.size();i++){
            int n=abs(nums[i]);
            int a=n-1;
            if(nums[a]<0) ans.push_back(abs(nums[i]));
            else nums[a]=-nums[a];
        }
        return ans;
    }
};