class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        if (root == nullptr) return {};
        vector<vector<int>> res;
        queue<Node*> q;
        q.push(root);
        while (!q.empty()) {
            vector<int> level;
            for (int i = q.size(); i > 0; i--) {
                Node* node = q.front();
                q.pop();
                level.push_back(node->val);
                for (auto c : node->children) q.push(c);
            }
            res.push_back(level);
        }
        return res;
    }
};