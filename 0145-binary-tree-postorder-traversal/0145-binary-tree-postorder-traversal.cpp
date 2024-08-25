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
    void findPostorder(TreeNode* root, vector<int>& postorder){
        if(!root)
            return;
        
        findPostorder(root->left, postorder);
        findPostorder(root->right, postorder);
        postorder.push_back(root->val);
    }

    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> postorder;
        findPostorder(root, postorder);
        return postorder;
    }
};