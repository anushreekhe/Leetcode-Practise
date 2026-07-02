class Solution {
public:
bool getPath(TreeNode* root, vector<TreeNode*>& arr, int x){
    if(!root) return false;
    arr.push_back(root);
    if(root->val==x) return true;
    if(getPath(root->left,arr,x) || getPath(root->right,arr,x)) return true;
    arr.pop_back();
    return false;
}
vector<TreeNode*> solve(TreeNode* A, int b){
    vector<TreeNode*> arr;
    if(A==NULL) return arr;
    getPath(A,arr,b);
    return arr;
}
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> arr1=solve(root,p->val);
        vector<TreeNode*> arr2=solve(root,q->val);
        int i=0;
        TreeNode* ans = root;
        while(i<arr1.size() && i<arr2.size() && arr1[i]==arr2[i]){
            ans = arr1[i];
            i++;
        }
        return ans;
    }
};