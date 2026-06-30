class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        int c=0;
        for(string& p : patterns){
            if(word.find(p)!=string::npos){
                c++;
            }

        }
        return c;
    }
};