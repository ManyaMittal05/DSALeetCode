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
    unordered_set<int> delVal;
    vector<TreeNode*> output;

    void traverse(TreeNode*& root){
        if(!root)
            return;

        traverse(root->left);
        traverse(root->right);
        if(delVal.find(root->val) != delVal.end()){
            if(root->left) output.push_back(root->left);
            if(root->right) output.push_back(root->right);
            root = NULL;
            delete root;
        }

    }
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        delVal.insert(to_delete.begin(), to_delete.end());
        traverse(root);

        if(root) 
            output.push_back(root);
        return output;
    }
};