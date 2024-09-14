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
    //we will do preorder traversal (or any traversal) on the left and right subtree of root
    //for left subtree traversal is : root, left, right'
    //for right subtree traversal is : root, right, left
    //if both traversals are equal, then the tree is symmetrical, otherwise not
    //for any type of traversal switch the right and left position for right and left subtree to get the answer
    //time comp = O(N)
    //space comp = O(h)

public:
    bool checkSymmetry(TreeNode* leftTree, TreeNode* rightTree){
        if(leftTree == NULL || rightTree == NULL)
            return leftTree == rightTree;

        return leftTree->val == rightTree->val 
                && checkSymmetry(leftTree->left, rightTree->right)
               && checkSymmetry(leftTree->right, rightTree->left);
    }

    bool isSymmetric(TreeNode* root) {
        if(root == NULL)
            return true;
        return checkSymmetry(root->left, root->right);
    }
};