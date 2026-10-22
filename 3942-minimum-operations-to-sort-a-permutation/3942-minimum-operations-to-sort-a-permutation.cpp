class Solution {
public:
    int minOperations(vector<int>& nums) {
        int p=0;
        int n=nums.size();
        if (n == 1) return 0;
        for(int i=0;i<n;i++){
            if(nums[i]==0){
                p=i;
                break;
            }
        }
        int f=0;
        if(p!=0 && p!=n-1){
            if(nums[p+1]!=1 && nums[p-1]!=1) return -1;
            if(nums[p-1]==1){
                f=1;
            }
        }
        else if(p==0){
            if(nums[1]!=1 && nums[n-1]!=1) return -1;
            if(nums[1]!=1){
                f=1;
            }
        }
        else if(p==n-1){
            if(nums[0]!=1 && nums[n-2]!=1) return -1;
            if(nums[0]!=1){
                f=1;
            }
        }
        int q=p;
        if(f==1){
            reverse(nums.begin(),nums.end());
            q=n-1-p;
        }
        //checking if rotation of all nos exist or not
        for(int i=0;i<n-1;i++){
            if(nums[i+1]!=(nums[i]+1)%n) return -1;
        }
        int l=q;
        int r=n-q+2;
        if(f==0){
            if(q==0) return 0;
            return min(l,r);
        }
        else{
            l=1+q;
            r=1+n-q;
            return min(l,r);
        }
    }
};