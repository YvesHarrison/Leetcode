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
    bool iterative(TreeNode* root){
        deque<TreeNode*> tmp;
        tmp.push_back(root);
        while(!tmp.empty()){
            int k=tmp.size();
            for(int i=0;i<k;++i){
                TreeNode* a=tmp.front();
                tmp.pop_front();
                if(a){
                    tmp.push_back(a->left);
                    tmp.push_back(a->right);
                }
            }
            for(int i=0;i<tmp.size();++i){
                if(i==tmp.size()-1-i)break;
                if(!tmp[i]&&!tmp[tmp.size()-i-1]) continue;
                if(!tmp[i]||!tmp[tmp.size()-i-1]) return false;
                if(tmp[i]->val!=tmp[tmp.size()-i-1]->val)return false;
            }
        }
        return true;
    }
    
    bool recursive(TreeNode* p,TreeNode* q){
        if(!p&&!q)return true;
        if(!p||!q)return false;
        if(p->val!=q->val)return false;
        return recursive(p->left,q->right)&&recursive(p->right,q->left);
    }
    
    bool isSymmetric(TreeNode* root) {
        if(!root)return true;
        return recursive(root->right,root->left);
    }
};
