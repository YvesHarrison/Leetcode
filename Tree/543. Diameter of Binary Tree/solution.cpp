/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution1 {
public:
    int ans;
    int depth(TreeNode* root){
        if(!root)return 0;
        int left = depth(root->left);
        int right = depth(root->right);
        ans = max(ans,left+right);
        return max(left,right)+1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        depth(root);
        return ans;
    }
};

class Solution2 {
public:
    int depth(TreeNode* root){
        if(!root)return 0;
        return max(depth(root->left),depth(root->right))+1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(!root)return 0;
        queue<TreeNode*>q;
        q.push(root);
        int ans=0;
        while(!q.empty()){
            TreeNode* tmp = q.front();
            q.pop();
            if(tmp->left)q.push(tmp->left);
            if(tmp->right)q.push(tmp->right);
            int dep=depth(tmp->left)+depth(tmp->right);
            if(dep>ans)ans=dep;
        }
        return ans;
    }
};
