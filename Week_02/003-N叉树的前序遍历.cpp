class Solution {
public:
    vector<int> preorder(Node* root) {
        vector<int> res;
        recur(root, res);
        return res;
    }

    void recur(Node* node, vector<int> &res) {
        if (node == nullptr) return;
        res.push_back(node->val);
        for (auto child : node->children) {
            recur(child, res);
        }
    }
    
};
