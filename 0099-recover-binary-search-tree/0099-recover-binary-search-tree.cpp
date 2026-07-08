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
    void inord(TreeNode* root, vector<int>& ans){
        if(root==NULL) return;
        inord(root->left, ans);
        ans.push_back(root->val);
        inord(root->right, ans);
    }
    void inord2(TreeNode* root, int &i, vector<int>& ans ){
        if(root==NULL) return;
        inord2(root->left,i, ans);
        if(ans[i]!=root->val) root->val=ans[i];
        i++;
        inord2(root->right,i, ans);
    }
    void recoverTree(TreeNode* root) {
        vector<int> ans;
        inord(root,ans);
        sort(ans.begin(), ans.end());
        int i=0;
        inord2(root,i,ans);
    }
};