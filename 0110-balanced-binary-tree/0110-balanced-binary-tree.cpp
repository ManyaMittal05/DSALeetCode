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
    int findHeight(TreeNode* root){
        if(!root) return 0;

        int left = 1 + findHeight(root->left);
        int right = 1 + findHeight(root->right);

        return max(left, right);
    }

    bool isBalanced(TreeNode* root) {
        if(!root) return true;

        int leftHeight = findHeight(root->left);
        int rightHeight = findHeight(root->right);

        if(abs(leftHeight - rightHeight) > 1) return false;

        bool leftTree = isBalanced(root->left);
        bool rightTree = isBalanced(root->right);

        if(!leftTree || !rightTree) return false;

        return true;
    }
};