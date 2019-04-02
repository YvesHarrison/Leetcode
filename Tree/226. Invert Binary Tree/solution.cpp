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
    void invert(TreeNode* head){
        if(!head)return;
        TreeNode* tmp=head->left;
        head->left=head->right;
        head->right=tmp;
        invert(head->left);
        invert(head->right);
    }
    
    TreeNode* invertTree(TreeNode* root) {
        if(!root)return NULL;
        TreeNode* head = root;
        invert(head);
        return root;
    }
};
