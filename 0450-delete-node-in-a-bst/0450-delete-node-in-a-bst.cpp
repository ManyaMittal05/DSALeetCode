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
        if(node->right == NULL) return node;
        return findRightMost(node->right);
    }
    TreeNode* helper(TreeNode* node){
        if(node->left == NULL)
            return node->right;
        if(node->right == NULL)
            return node->left;
        
        TreeNode* rightmost = findRightMost(node->left);
        rightmost->right = node->right;
        return node->left;
    }

    TreeNode* deleteNode(TreeNode* root, int key) {
        TreeNode* node = root;
        if(!root) return NULL;
        if(root->val == key) return helper(root);
        while(node){
            if(node->val > key){
                if(node->left != NULL && node->left->val == key){
                    node->left = helper(node->left);
                    break;
                }
                else{
                    node = node->left;
                }
            }
            else{
                if(node->val < key){
                    if(node->right != NULL && node->right->val == key){
                        node->right = helper(node->right);
                        break;
                    }
                    else{
                        node = node->right;
                    }
                }
            }

        }
        return root;
    }
};