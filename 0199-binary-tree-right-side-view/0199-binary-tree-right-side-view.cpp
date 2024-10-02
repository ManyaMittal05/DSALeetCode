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
    void preOrder(TreeNode* root, vector<int>& ds, int level){
        if(!root) return;

        if(ds.size() == level) ds.push_back(root->val);
        preOrder(root->right, ds, level+1);
        preOrder(root->left, ds, level+1);
    }

    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        int level = 0;
        preOrder(root, ans, level);
        return ans;    
    }
};