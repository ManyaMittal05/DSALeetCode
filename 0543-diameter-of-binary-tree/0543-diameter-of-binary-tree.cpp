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
    int helper(TreeNode* root, int& diam){
        if(!root) return 0;

        int leftHt = helper(root->left, diam);
        int rightHt = helper(root->right, diam);
        diam = max(diam, leftHt + rightHt);
        return 1 + max(leftHt, rightHt);
    }

    int diameterOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
        int diam = 0;
        helper(root, diam);
        return diam;    
    }
};