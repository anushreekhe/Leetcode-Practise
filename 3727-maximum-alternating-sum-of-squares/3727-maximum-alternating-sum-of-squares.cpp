class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n=nums.size();
        for(int i=0;i<n;i++) nums[i]=nums[i]*nums[i];
        sort(nums.begin(),nums.end());
        long long ans=0;
        for(int i=0;i<n/2;i++) ans-=nums[i];
        for(int j=n/2;j<n;j++) ans+=nums[j];
        return ans;
    }
};