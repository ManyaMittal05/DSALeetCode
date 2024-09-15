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
    void inorderTrav(TreeNode* root, int k, int& kthSmallest, int& count){
        if(root == NULL || count >= k)
            return;
        inorderTrav(root->left, k, kthSmallest, count);
        count++;
        if(count == k){
            kthSmallest = root->val;
            return;
        }
        inorderTrav(root->right, k, kthSmallest, count);
    }
    int kthSmallest(TreeNode* root, int k) {
        int ans, count = 0;
        inorderTrav(root, k, ans, count);
        return ans;
    }
};