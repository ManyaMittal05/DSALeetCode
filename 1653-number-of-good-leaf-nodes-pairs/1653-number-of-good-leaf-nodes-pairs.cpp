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
    //post order tarversal
    vector<int> helper(TreeNode* root, int& res, int d){
        if(!root) return {};
        if(!root->left && !root->right) return {1}; //return dist as 1 if lead node is found

        vector<int> left = helper(root->left, res, d); //vector containing dist from left childs
        vector<int> right = helper(root->right, res, d); //vector containing dist from right childs

        //for each left child, calculate its dist from right child by add both dist
        //if the dist is less than or equal to the target dist increment the result
        for(int i = 0; i<left.size(); i++){
            for(int j = 0; j<right.size(); j++){
                if(left[i] + right[j] <= d)
                    res++;
            }
        }

        //now when the parent node is encountered
        //it will return the distance of both left and right child
        //so create a vector and append the values in left and right vectors to it
        //add values + 1 as 1 node more is covered i.e. the parent node
        vector<int> parent_vec;
        for(int i = 0; i<left.size(); i++){
            parent_vec.push_back(left[i]+1);
        }
        for(int j = 0; j<right.size(); j++){
            parent_vec.push_back(right[j]+1);
        }
        return parent_vec;
    }

    int countPairs(TreeNode* root, int distance) {
        int res = 0;
        helper(root, res, distance);
        return res;
    }
};