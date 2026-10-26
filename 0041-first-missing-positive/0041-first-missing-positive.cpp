class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int m=*max_element(nums.begin(),nums.end());
        unordered_map<int,int> hash;
        int c=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>0){
                hash[nums[i]]++;
                c++;
            }
        }
        int ans=-1;
        for(int i=1;i<=m;i++){
            if(hash[i]==0){
                ans=i;
                break;
            }
        }
        if(c==0) return 1;
        if(ans==-1) return m+1;
        else return ans;
    }
};