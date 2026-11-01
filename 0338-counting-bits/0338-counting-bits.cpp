class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans(n+1);
        ans[0]=0;
        for(int i=1;i<n+1;i++){
            int c=0;
            int num=i;
            while(num!=0){
                if(num%2!=0) c++;
                num/=2;
            }
            ans[i]=c;
        }
        return ans;
    }
};