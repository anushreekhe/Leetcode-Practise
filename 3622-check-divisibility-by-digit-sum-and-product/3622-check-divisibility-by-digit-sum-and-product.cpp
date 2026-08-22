class Solution {
public:
    bool checkDivisibility(int n) {
        int num=n;
        int s=0, p=1;
        while(n!=0){
            int d=n%10;
            s+=d;
            p*=d;
            n/=10;
        }
        if(num%(s+p)==0) return true;
        else return false;
    }
};