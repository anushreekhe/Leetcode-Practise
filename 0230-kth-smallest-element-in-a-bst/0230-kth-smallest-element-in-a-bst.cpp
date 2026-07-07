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
int c=0;
int inord(TreeNode* root, int k){
        if (root == NULL) return -1;

        int left = inord(root->left, k);
        if (left != -1) return left;   // found in left subtree, propagate up

        c++;
        if (c == k) return root->val;

        return inord(root->right, k);  // return this directly
    }
    int kthSmallest(TreeNode* root, int k) {
       
        return inord(root,k);
    }
};