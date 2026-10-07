class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> ps;
        ps[0]=1;
        int s=0, c=0;
        for(int num:nums){
            s+=num;
            if(ps.find(s-k)!=ps.end()){
                c+=ps[s-k];
            }
            ps[s]++;
        }
        return c;
    }
};