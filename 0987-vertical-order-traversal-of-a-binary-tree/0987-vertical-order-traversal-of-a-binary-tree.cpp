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
    vector<array<int,3>> in;
    void enterleft(TreeNode* root,int r, int c){
        in.push_back({root->val,r+1,c-1});
        if(root->left!=NULL) enterleft(root->left,r+1,c-1);
        if(root->right!=NULL) enterright(root->right,r+1,c-1);
    }
    void enterright(TreeNode* root, int r, int c){
        
        in.push_back({root->val, r+1, c+1});
        if(root->left!=NULL) enterleft(root->left,r+1,c+1);
        if(root->right!=NULL) enterright(root->right,r+1,c+1);
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> aaa;
        if(root==NULL) return aaa;
        
        in.push_back({root->val,0,0});
        if(root->left!=NULL) enterleft(root->left,0,0);
        if(root->right!=NULL) enterright(root->right,0,0);
        sort(in.begin(), in.end(), [](const array<int,3>& a, const array<int,3>& b) {
    if (a[2] != b[2]) return a[2] < b[2];   // col
    if (a[1] != b[1]) return a[1] < b[1];   // row
    return a[0] < b[0];                     // value
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