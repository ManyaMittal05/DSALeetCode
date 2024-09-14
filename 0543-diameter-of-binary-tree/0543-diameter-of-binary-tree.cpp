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
    int maxHt = 0;
    int findHeight(TreeNode* root){
        if(!root) return 0;

        int lh = findHeight(root->left);
        int rh = findHeight(root->right);

        return 1 + max(lh, rh);
    }

    int diameterOfBinaryTree(TreeNode* root) {
        if(!root) return 0;

        int leftHt = findHeight(root->left);
        int rightHt = findHeight(root->right);    
        maxHt = max(maxHt, leftHt + rightHt);

        diameterOfBinaryTree(root->left);
        diameterOfBinaryTree(root->right);
        return maxHt;
    }
};