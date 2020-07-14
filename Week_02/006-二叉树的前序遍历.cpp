class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        // helper(root, res);
        iterHelper(root, res);
        return res;
    }

    void helper(TreeNode* node, vector<int> &res) {
        if (node == nullptr) return;
        res.push_back(node->val);
        helper(node->left, res);
        helper(node->right, res);
    }

    void iterHelper(TreeNode* node, vector<int> &res) {
        if (node == nullptr) return;
        stack<pair<int, TreeNode*>> stack;
        stack.push(make_pair(0, node));
        while (!stack.empty()) {
            auto p = stack.top();
            stack.pop();
            int color = p.first;
            auto node = p.second;
            if (color == 0) {
                if (node->right != nullptr)
                    stack.push(make_pair(0, node->right));
                if (node->left != nullptr)
                    stack.push(make_pair(0, node->left));
                stack.push(make_pair(1, node));
            } else res.push_back(node->val);
        }
    }
};