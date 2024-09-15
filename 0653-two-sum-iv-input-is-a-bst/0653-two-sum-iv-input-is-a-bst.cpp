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
    void inorder(TreeNode* root, int k, unordered_map<int,int>& mp, bool& ans){
        if(!root) return;

        inorder(root->left, k, mp, ans);

        if(mp.find(root->val) != mp.end())
            ans = true;
        mp[k - root->val]++;

        inorder(root->right, k, mp, ans);
    }
    bool findTarget(TreeNode* root, int k) {
        bool ans = false;
        unordered_map<int, int> mp;
        inorder(root, k, mp, ans);
        return ans;
    }
};