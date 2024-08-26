/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    void traversal(Node* root, vector<int>& postorder){
        if(!root) return;

        vector<Node*> child = root->children;
        for(int i = 0; i<child.size(); i++){
            traversal(child[i], postorder);
        }
        postorder.push_back(root->val);
    }
    vector<int> postorder(Node* root) {
        if(!root) return {};
        vector<int> post;
        traversal(root, post);
        return post;
    }
};