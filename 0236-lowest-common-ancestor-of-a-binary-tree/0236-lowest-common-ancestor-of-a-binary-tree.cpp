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
    TreeNode* findRootToNodePath(TreeNode* root, TreeNode* p, TreeNode* q){
        if(!root || root == p || root == q)
            return root;

        TreeNode* left = findRootToNodePath(root->left, p, q);
        TreeNode* right = findRootToNodePath(root->right, p, q);
        
        if(!right) return left;
        if(!left) return right;
        return root;
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return findRootToNodePath(root, p, q);
    }
};