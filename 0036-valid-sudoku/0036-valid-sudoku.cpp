class Solution {
public:

    bool cross(vector<vector<char>>& board, int a, int b){
        unordered_map<int,int> hash;
        for(int i=a;i<a+3;i++){
            for(int j=b;j<b+3;j++){
                if(board[i][j]=='.') continue;
                int x=board[i][j]-'0';
                hash[x]++;
                if(hash[x]>1) return false;
            }
        }
        return true;
    }

    bool isValidSudoku(vector<vector<char>>& board) {
       for(int i=0;i<9;i++){
        unordered_map<int,int> hash1;
        unordered_map<int,int> hash2;
        for(int j=0;j<9;j++){
            if(board[i][j]!='.'){
            int a=board[i][j]-'0';
            hash1[a]++;
            if(hash1[a]>1) return false;
            }
            if(board[j][i]!='.'){
                int b=board[j][i]-'0';
                hash2[b]++;
                if(hash2[b]>1) return false;
            }
        }
       }
        bool f=true;
        f=cross(board,0,0);
        if(f==false) return false;
        f=cross(board,0,3);
        if(f==false) return false;
        f=cross(board,0,6);
        if(f==false) return false;
        f=cross(board,3,0);
        if(f==false) return false;
        f=cross(board,3,3);
        if(f==false) return false;
        f=cross(board,3,6);
        if(f==false) return false;
        f=cross(board,6,0);
        if(f==false) return false;
        f=cross(board,6,3);
        if(f==false) return false;
        f=cross(board,6,6);
        if(f==false) return false;
        return true;
    }
};