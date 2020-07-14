class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        if (root == nullptr) return vector<int>{};
        stack<pair<int, TreeNode*>> stack;
        vector<int> res;
        stack.push(make_pair(0, root));
        while (!stack.empty()) {
            auto p = stack.top();
            stack.pop();
            int color = p.first;
            TreeNode *node = p.second;
            if (color == 1) res.push_back(node->val);
            else {
                if (node->right != nullptr)
                    stack.push(make_pair(0, node->right));
                stack.push(make_pair(1, node));
                if (node->left != nullptr)
                    stack.push(make_pair(0, node->left));
            }
        }
        return res;
    }
};