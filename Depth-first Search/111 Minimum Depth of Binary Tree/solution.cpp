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
    int minDepth(TreeNode* root) {
        if(root==NULL) return 0;
        if(root->left&&!root->right)return minDepth(root->left)+1;
        if(root->right&&!root->left)return minDepth(root->right)+1;//保证一直下探到叶节点
        return min(minDepth(root->left),minDepth(root->right))+1;
    }
};
