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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        //using multiset beacause there can be multiple nodes of same values
        map<int, map<int, multiset<int>>> mp; //vertical -> {level, {multiple nodes}}
        queue<pair<TreeNode*, pair<int, int>>> q;

        vector<vector<int>> ans;
        q.push({root, {0, 0}});

        while(!q.empty()){
            auto it = q.front();
            TreeNode* node = it.first;
            int vertical = it.second.first;
            int level = it.second.second;
            q.pop();

            mp[vertical][level].insert(node->val);

            if(node->left) q.push({node->left, {vertical-1, level+1}});
            if(node->right) q.push({node->right, {vertical+1, level+1}});
        }

        for(auto [vertical, mapping] : mp){
            vector<int> vec;
            for(auto [level, value] : mapping){
                
                vec.insert(vec.end(), value.begin(), value.end());
            }
            ans.push_back(vec);
        }
        return ans;
    }
};