// 给你一棵 完美 二叉树的根节点 root ，请你反转这棵树中每个 奇数 层的节点值。

// 例如，假设第 3 层的节点值是 [2,1,3,4,7,11,29,18] ，那么反转后它应该变成 [18,29,11,7,4,3,1,2] 。
// 反转后，返回树的根节点。

// 完美 二叉树需满足：二叉树的所有父节点都有两个子节点，且所有叶子节点都在同一层。

// 节点的 层数 等于该节点到根节点之间的边数。

// 来源：力扣（LeetCode）
// 链接：https://leetcode.cn/problems/reverse-odd-levels-of-binary-tree
// 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

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

// dfs
class Solution {
public:
    TreeNode* reverseOddLevels(TreeNode* root) {
        invertOddLevels(root->left,root->right,1);
        return root;
    }

    void invertOddLevels(TreeNode *left,TreeNode *right,int level){
        if(left==NULL){
            return;
        }
        if(level %2!=0){
            int temp = left->val;
            left->val = right->val;
            right->val = temp;
        }
        invertOddLevels(left->left,right->right,level+1);
        invertOddLevels(left->right,right->left,level+1);
    }
};