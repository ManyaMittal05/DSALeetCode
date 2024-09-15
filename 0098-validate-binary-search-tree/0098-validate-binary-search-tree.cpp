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
    bool helper(TreeNode* root, long min, long max){
        if(root == NULL) return true;
        if(root->val >= max || root->val <= min) return false;

        return helper(root->left, min, (long)root->val)
                && helper(root->right, (long)root->val, max);
        
    }

    bool isValidBST(TreeNode* root) {
        return helper(root, (long)INT_MIN-1, (long)INT_MAX+1);
    }
};