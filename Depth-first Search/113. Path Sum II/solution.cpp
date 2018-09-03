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
    void find(vector<vector<int>>&res,vector<int>&tmp,TreeNode* root, int sum){
        if(!root)return;
        tmp.push_back(root->val);
        if(!root->left&&!root->right&&sum-root->val==0)res.push_back(tmp);
        find(res,tmp,root->left,sum-root->val);
        find(res,tmp,root->right,sum-root->val);
        tmp.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>>res;
        vector<int>tmp;
        find(res,tmp,root,sum);
        return res;
    }
};
