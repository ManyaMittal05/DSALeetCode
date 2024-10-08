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
    TreeNode* findRightMost(TreeNode* node){
        while(node->right) node = node->right;
        return node;
    }
    
    void flatten(TreeNode* root) {
        if(!root) return;
        
        TreeNode* temp = root->right;
        root->right = root->left;
        root->left = NULL;
        TreeNode* rightMost = findRightMost(root);
        rightMost->right = temp;
        flatten(root->left);
        flatten(root->right);
    }
};