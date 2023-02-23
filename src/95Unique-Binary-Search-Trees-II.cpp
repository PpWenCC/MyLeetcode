// 给你一个整数 n ，请你生成并返回所有由 n 个节点组成且节点值从 1 到 n 互不相同的不同 二叉搜索树 。可以按 任意顺序 返回答案。

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
    vector<TreeNode*> generateTrees(int n) {
        if(!n){
            return {};
        }

        return generateEntry(1,n);
    }

    vector<TreeNode*> generateEntry(int start,int end){
        if(start>end){
            return {nullptr};
        }

        vector<TreeNode*> res;

        for(int i = start;i<=end;i++){
            vector<TreeNode*> leftTrees = generateEntry(start,i-1);

            vector<TreeNode*> rightTrees = generateEntry(i+1,end);

            for(auto& leftNode : leftTrees){
                for(auto& rightNode : rightTrees){
                    TreeNode *curNode = new TreeNode(i);
                    curNode->left = leftNode;
                    curNode->right = rightNode;
                    res.emplace_back(curNode);
                }
            }
        }
        return res;
    }
};