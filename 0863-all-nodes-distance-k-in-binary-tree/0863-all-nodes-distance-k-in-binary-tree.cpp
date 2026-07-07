/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:

 void markParent(TreeNode* root, unordered_map<TreeNode*, TreeNode*> &parent_track, TreeNode* target){
        queue<TreeNode*> queue;
        queue.push(root);
        while(!queue.empty()){
            TreeNode* c=queue.front();
            queue.pop();
            if(c->left){
                parent_track[c->left]=c;
                queue.push(c->left);
            }
            if(c->right){
                parent_track[c->right]=c;
                queue.push(c->right);
            }
        }

    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, TreeNode*> parent_track;
        markParent(root,parent_track,target);
        unordered_map<TreeNode*, bool> visited;
        queue<TreeNode*> qu;
        qu.push(target);
        visited[target]=true;
        int curl=0;
        while(!qu.empty()){
            int size=qu.size();
            if(curl++ == k) break;
            for(int i=0;i<size;i++){
                TreeNode* cu=qu.front();
                qu.pop();
                if(cu->left && !visited[cu->left]){
                    qu.push(cu->left);
                    visited[cu->left]=true;
                }
                if(cu->right && !visited[cu->right]){
                    qu.push(cu->right);
                    visited[cu->right]=true;
                }
                if(parent_track[cu] && !visited[parent_track[cu]]){
                    qu.push(parent_track[cu]);
                    visited[parent_track[cu]]=true;
                }
            }
        }
        vector<int> result;
        while(!qu.empty()){
            TreeNode* cc=qu.front(); qu.pop();
            result.push_back(cc->val);
        }
        return result;
    }
};