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
    void find(vector<string>&res,TreeNode* root,string tmp){
        if(!root)return;
        bool flag=true;
        if(root->val>=0){
            tmp+=to_string(root->val);//val为任意整数用to_string转换
            tmp+="->";
        }
        else{
            tmp+=to_string(root->val);
            tmp+="->";
            flag=false;
        }    
        if(!root->left&&!root->right){
            tmp.resize(tmp.size()-2);
            res.push_back(tmp);
            return;
        }
        find(res,root->left,tmp);
        find(res,root->right,tmp);
        if(flag)tmp.resize(tmp.size()-3);
        else tmp.resize(tmp.size()-4);
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string>res;
        string tmp;
        find(res,root,tmp);
        return res;
    }
};
