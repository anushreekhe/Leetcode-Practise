class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        if(digits[digits.size()-1]!=9){
            digits[digits.size()-1]=digits[digits.size()-1]+1;
            return digits;
        }
        //if(digits.size()==1) return [1,0];
        digits[digits.size()-1]+=1;
        int i=digits.size()-1;
        while(i>=1 && digits[i]==10){
            digits[i]=0;
            digits[i-1]+=1;
            i--;
        }
        if(digits[0]==10){
            digits[0]=1;
            digits.push_back(0);
        }
        return digits;
    }
};