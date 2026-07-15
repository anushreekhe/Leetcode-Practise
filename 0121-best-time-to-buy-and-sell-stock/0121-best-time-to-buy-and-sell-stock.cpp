class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int i=0;
        int j=1;
        int minm=0;
        int d=0;
        while(j<prices.size()){
            if(prices[j]>prices[i]){
                d=prices[j]-prices[i];
                if(minm<d) minm=d;
                j++;
            }
            else{
                i=j;
                j++;
            }
        }
        return minm;
    }
};