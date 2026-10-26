class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        for(int i=0;i<nums.size();i++){
            if(nums[i]<=0) nums[i]=nums.size()+1;
        }
        for(int i=0;i<nums.size();i++){
            int a=abs(nums[i]);
            int idx=a-1;
            if(idx>=0 && idx<nums.size() && nums[idx]>0) nums[idx]=-nums[idx];
        }
        int ans=-1;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>0){
                ans=i+1;
                break;
            }
        }
        if(ans==-1) return nums.size()+1;
        else return ans;
}};