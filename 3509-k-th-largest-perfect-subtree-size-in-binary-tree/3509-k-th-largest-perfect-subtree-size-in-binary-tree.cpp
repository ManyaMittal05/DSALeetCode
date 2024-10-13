/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    // Helper function to check if a subtree rooted at 'root' is perfect and
    // return its size
    int isPerfect(TreeNode* root, bool& isPerfectSubtree) {
        if (!root) {
            isPerfectSubtree = true;
            return 0;
        }

        bool leftPerfect = false, rightPerfect = false;
        int leftSize = isPerfect(root->left, leftPerfect);
        int rightSize = isPerfect(root->right, rightPerfect);

        // Check if this node forms a perfect subtree
        if (leftPerfect && rightPerfect && leftSize == rightSize) {
            isPerfectSubtree = true;
            return leftSize + rightSize + 1; // Size of this perfect subtree
        }

        isPerfectSubtree = false;
        return 0;
    }

    // Function to find all perfect subtree sizes
    void findPerfectSubtrees(TreeNode* root, vector<int>& sizes) {
        if (!root)
            return;

        bool isPerfectSubtree = false;
        int size = isPerfect(root, isPerfectSubtree);

        if (isPerfectSubtree) {
            sizes.push_back(size);
        }

        findPerfectSubtrees(root->left, sizes);
        findPerfectSubtrees(root->right, sizes);
    }

    int kthLargestPerfectSubtree(TreeNode* root, int k) {
        vector<int> sizes;
        findPerfectSubtrees(root, sizes);

        if (sizes.size() < k)
            return -1; // Not enough perfect subtrees

        // Sort sizes in decreasing order
        sort(sizes.rbegin(), sizes.rend());

        return sizes[k - 1];
    }
};