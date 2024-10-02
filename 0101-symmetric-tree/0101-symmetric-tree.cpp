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
    bool preorder(TreeNode* leftTree, TreeNode* rightTree){
        if(!leftTree && !rightTree) 
            return true;
        if(!leftTree && rightTree || leftTree && !rightTree)
            return false;
        
        return (leftTree->val == rightTree->val) &&
                preorder(leftTree->left, rightTree->right) &&
                preorder(leftTree->right, rightTree->left);
    }

    bool isSymmetric(TreeNode* root) {
        if(!root) return true;
        return preorder(root->left, root->right);
    }
};