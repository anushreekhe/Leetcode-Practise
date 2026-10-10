class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        long long k=(long long)k1+k2;
        vector<long long> diff(nums1.size());
        int n=nums1.size();
        vector<long long> vec(100001,0);
        for(int i=0;i<n;i++) diff[i]=(abs)(nums1[i]-nums2[i]);
        for(int i=0;i<n;i++){
            vec[diff[i]]++;
        }
        for(int i=100000;i>0;i--){
            if(vec[i]==0) continue;
            long long countops=min(vec[i],k);
            vec[i]-=countops;
            vec[i-1]+=countops;
            k-=countops;
            if(k==0) break;
        }
        long long ans=0;
        for(int i=0;i<100001;i++){
            ans=ans+vec[i]*i*i;
        }
        return ans;
    }
};