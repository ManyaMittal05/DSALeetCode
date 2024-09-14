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
    int findHeight(TreeNode* root, int& maxi){
        if(!root) return 0;

        int lh = findHeight(root->left, maxi);
        int rh = findHeight(root->right, maxi);

        maxi = max(maxi, lh + rh);
        return 1 + max(lh, rh);
    }

    int diameterOfBinaryTree(TreeNode* root) {
        if(!root) return 0;

        int diameter = 0;
        findHeight(root, diameter);
        return diameter;
    }
};