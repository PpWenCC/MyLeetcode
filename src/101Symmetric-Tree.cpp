// 给你一个二叉树的根节点 root ， 检查它是否轴对称。

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        return visit(root->left,root->right);
    }

    bool visit(TreeNode *p, TreeNode *q){
        if((p==NULL&&q!=NULL) || (p!=NULL && q==NULL)){
            return false;
        }

        if(p==NULL && q==NULL){
            return true;
        }

        if(p->val == q->val){
            return visit(p->left,q->right)&&visit(p->right,q->left);
        }
        return false;
    }
};