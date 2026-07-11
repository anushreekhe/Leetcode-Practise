class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> pre;
        pre[0]=1;
        int sum=0,c=0;
        for(int num:nums){
            sum+=num;
            if(pre.find(sum-k)!=pre.end()){
                c+=pre[sum-k];
            }
            pre[sum]++;
        }
        return c;
    }
};