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
    void transform(TreeNode* root,vector<TreeNode*>& nodes){
        if(!root)return;
        nodes.push_back(root);
        transform(root->left,nodes);
        transform(root->right,nodes);
    }
    void flatten(TreeNode* root) {
        if(!root)return;
        vector<TreeNode*> nodes;
        transform(root,nodes);
        for(int i=0;i<nodes.size()-1;++i){
            nodes[i]->right=nodes[i+1];
            nodes[i]->left=NULL;
        }
        root=nodes[0];
    }
};
