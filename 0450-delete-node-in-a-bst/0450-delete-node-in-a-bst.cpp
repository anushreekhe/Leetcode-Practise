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
    TreeNode* deleteNode(TreeNode* root, int val) {
        if(root == NULL) return NULL;
        if(root->val==val) return helper(root);
        TreeNode* dummy=root;
        while(root!=NULL){
            if(root->val > val){
                if(root->left!=NULL && root->left->val==val){
                    root->left=helper(root->left);
                    break;
                }
                else{
                    root=root->left;
                }
            }
            else{
                if(root->right!=NULL && root->right->val==val){
                    root->right=helper(root->right);
                    break;
                }
                else{
                    root=root->right;
                }
            }
        }    
        return dummy;
    }
    TreeNode* helper(TreeNode* root){
        if(root->left==NULL) return root->right;
        else if(root->right==NULL) return root->left;
        TreeNode* rc=root->right;
        TreeNode* lr=findlr(root->left);
        lr->right=rc;
        return root->left;
    }
    TreeNode* findlr(TreeNode* root){
        if(root->right==NULL) return root;
        return findlr(root->right);
    }
};