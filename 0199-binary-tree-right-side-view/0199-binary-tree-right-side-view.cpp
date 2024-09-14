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
//we have to return rightmost node of each level in the tree
    //for this we will use recursive preorder traversal technique
    //but instead of Root, Left, Right ... we will traverse Root, Right, Left
    //beacause we need rightmost node
    //if we have to return the left view of the tree, then we must have done preorder in root,left,right manner only
    //if the size of data structure == level, then insert the node->val in data structure
    void preOrder(TreeNode* root, vector<int>& res, int level){
        if(!root) return;

        if(res.size() == level) res.push_back(root->val);
        preOrder(root->right, res, level+1);
        preOrder(root->left, res, level+1);
    }

    vector<int> rightSideView(TreeNode* root) {
        vector<int> result;
        int level = 0;
        preOrder(root, result, level);
        return result;    
    }
};