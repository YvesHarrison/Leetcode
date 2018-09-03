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
    bool hasPathSum(TreeNode* root, int sum) {
        if(!root)return false;
        if(sum-root->val==0&&!root->left&&!root->right)return true;//与其找一个不知位置的空节点，不如直接判断是否为叶节点 
        return hasPathSum(root->left,sum-root->val)||hasPathSum(root->right,sum-root->val);
    }
};
