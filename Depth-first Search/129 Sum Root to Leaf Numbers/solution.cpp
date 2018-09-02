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
    void get(TreeNode* root,vector<int>&tmp,vector<vector<int>>&num){
        if(!root)return;
        tmp.push_back(root->val);
        if(!root->left&&!root->right)num.push_back(tmp);
        get(root->left,tmp,num);
        get(root->right,tmp,num);
        tmp.pop_back();
    }
    int sumNumbers(TreeNode* root) {
        vector<vector<int>>num;
        vector<int>tmp;
        int res=0;
        get(root,tmp,num);
        for(int i=0;i<num.size();++i){
            int n=0;
            for(int j=num[i].size()-1;j>=0;--j){
                n+=num[i][j]*pow(10,num[i].size()-1-j);  
            }
            res+=n;
        }
        return res;
    }
};
