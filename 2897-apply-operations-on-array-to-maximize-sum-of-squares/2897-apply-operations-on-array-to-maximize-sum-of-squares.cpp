class Solution {
public:
    int maxSum(vector<int>& nums, int k) {
        const int m=1e9+7;
        int n=nums.size();
        int x=*max_element(nums.begin(),nums.end());
        int bits = 0;
        while (x > 0) {
            bits++;
            x /= 2;
        }
        vector<vector<int>> vec(n, vector<int>(bits, 0));
        for(int i=0;i<n;i++){
            int num=nums[i];
            int a=bits-1;
            while(num>0){
                vec[i][a--]=num%2;
                num/=2;
            }
        }

        vector<int> count(bits,0);
        for(int i=0;i<bits;i++){
            int c=0;
            for(int j=0;j<n;j++){
                if(vec[j][i]==1) c++;
            }
            count[i]=c;
        }
        long long ans=0;
        for(int i=0;i<k;i++){
            long long numb=0;
            for(int j=0;j<bits;j++){
                if(count[j]>0){
                    numb=numb*2+1;
                    count[j]--;
                }
                else numb=numb*2;
            }
            numb%=m;
            ans=(ans+numb*numb)%m;
        }
        return (int)ans;
    }
};