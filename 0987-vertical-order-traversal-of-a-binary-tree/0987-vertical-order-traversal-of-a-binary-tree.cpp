/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> in;
    void enterleft(TreeNode* root,int r, int c){
        vector<int> left={root->val,r+1,c-1};
        in.push_back(left);
        if(root->left!=NULL) enterleft(root->left,r+1,c-1);
        if(root->right!=NULL) enterright(root->right,r+1,c-1);
    }
    void enterright(TreeNode* root, int r, int c){
        vector<int> right={root->val, r+1, c+1};
        in.push_back(right);
        if(root->left!=NULL) enterleft(root->left,r+1,c+1);
        if(root->right!=NULL) enterright(root->right,r+1,c+1);
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        
        if(root==NULL) return in;
        vector<int> top={root->val,0,0};
        in.push_back(top);
        if(root->left!=NULL) enterleft(root->left,0,0);
        if(root->right!=NULL) enterright(root->right,0,0);
        sort(in.begin(), in.end(), [](const vector<int>& a, const vector<int>& b) {
        if (a[2] != b[2]) return a[2] < b[2]; 
        if (a[1] != b[1]) return a[1] < b[1]; 
        return a[0] < b[0];                     
        });
        vector<vector<int>> ans;
        int a=in[0][2];
        vector<int> anss;
        for(int i=0;i<in.size();i++){
            
            if(in[i][2]==a) anss.push_back(in[i][0]);
            else{
                ans.push_back(anss);
                a=in[i][2];
                anss.clear();
                anss.push_back(in[i][0]);
            }
        }
        ans.push_back(anss);
        return ans;
    }
};