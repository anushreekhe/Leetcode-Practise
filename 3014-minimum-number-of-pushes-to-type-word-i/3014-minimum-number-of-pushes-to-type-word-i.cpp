class Solution {
public:
    int minimumPushes(string word) {
        int n=word.size();
        if(n<8) return n;
        else{
            int a=1, ans=0;
            int i=0;
            while(i<n){
                if(n-i>8){
                    ans=ans+a*8;
                    a++;
                    i+=8;
                }
                else{
                    ans=ans+a*(n-i);
                    break;
                }
            }
            return ans;
        }
    }
};