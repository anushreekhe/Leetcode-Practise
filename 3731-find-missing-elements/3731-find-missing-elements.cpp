class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        vector<int> ans;
        sort(nums.begin(),nums.end());
        int a=nums[0];
        int b=nums[nums.size()-1];
        if(nums.size()==b-a+1) return ans;
        else{
            int j=0;
            for(int i=a;i<=b;i++){
                if(nums[j]==i){
                    j++;
                    continue;
                }
                else{
                    ans.push_back(i);
                }
            }
            return ans;
        }
        
    }
};