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
        if(!root) return NULL;
        
        if(root == p || root == q)
            return root;

        TreeNode* left = findRootToNodePath(root->left, p, q);
        TreeNode* right = findRootToNodePath(root->right, p, q);
        
        if((left == p && right == q) || (right == p && left == q))
            return root;
        if(left) return left;
        if(right) return right;
        return NULL;
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return findRootToNodePath(root, p, q);
    }
};