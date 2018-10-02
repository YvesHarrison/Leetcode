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
    void find(TreeNode* &root,vector<int>&tmp){
        if(root->left==NULL&&root->right==NULL){
            tmp.push_back(root->val);root=NULL;return;
        }
        if(root->left!=NULL)find(root->left,tmp);
        if(root->right!=NULL)find(root->right,tmp);
    }
    vector<vector<int>> findLeaves(TreeNode* root) {
        vector<vector<int>>res;
        while(root){
            vector<int>tmp;
            find(root,tmp);
            res.push_back(tmp);
        }
        return res;
    }
};
