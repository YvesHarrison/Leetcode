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
    int depth(TreeNode* root){
        TreeNode *tmp=root;
        int layer=0;
        while(tmp!=NULL){
            layer++;
            tmp=tmp->left;
        }
        return layer;
    }
    int countNodes(TreeNode* root) {
        if(root==NULL) return 0;
        if(root->left==NULL) return 1;
        int layer=depth(root),level=layer;
        int left_d,right_d,num=1;
        TreeNode *tmp=root;
        while(layer>1){//continue to left to find last leaf
            left_d=layer-1;
            right_d=depth(tmp->right);
            if(left_d>right_d){
                tmp=tmp->left;
                layer=left_d;
                num=(num-1)*2+1;
            }
            else{
                tmp=tmp->right;//continue to right to find last leaf
                layer=right_d;
                num*=2;
            }
        }
        int res=pow(2,level-1)-1;
        return res+num;
    }
};
