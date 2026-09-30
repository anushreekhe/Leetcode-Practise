class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
       vector<int> ans;
       int d=0;
       for(int i=0;i<seq.size();i++){
        char c=seq[i];
        if(c=='('){
            if(d%2==0) ans.push_back(0);
            else ans.push_back(1);
            d++;
        }
        else{
            d--;
            if(d%2==0) ans.push_back(0);
            else ans.push_back(1);
            
        }
        
       } 
       return ans;
    }
};