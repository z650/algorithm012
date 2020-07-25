struct info {
    bool find1;
    bool find2;
    TreeNode* ans;
    info(bool n1, bool n2, TreeNode* node) {
        find1 = n1;
        find2 = n2;
        ans = node;
    }
};

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == nullptr) return nullptr;
        info res = process(root, p, q);
        return res.ans;
    }
    info process(TreeNode* root, TreeNode* o1, TreeNode* o2) {
        if (root == nullptr) return info(false, false, nullptr);
        info leftInfo = process(root->left, o1, o2);
        info rightInfo = process(root->right, o1, o2);

        // 如果左右子树中找到了最低公共祖先就返回找到的公共祖先
        if (leftInfo.ans != nullptr) return info(true, true, leftInfo.ans); 
        if (rightInfo.ans != nullptr) return info(true, true, rightInfo.ans);

        // 代码走到这里说明在 root 的左右子树中没有发现最低公共祖先
        // 那么从这里开始就要判断 o1, o2 的分布情况

        // 情况1:  如果o1, o2 分布在 root 的左右子树中, 那么 root 是最低公共祖先
        if (leftInfo.find1 && rightInfo.find2) return info(true, true, root); 
        if (leftInfo.find2 && rightInfo.find1) return info(true, true, root);

        // 代码走到这里说明没有在 root 的子树中发现o1 和 o2
        // 情况2: root 的子树中只发现 o1 或只发现 o2 或都没有发现

        // 这里是判断当前 root 是不是 o1 或 o2
        bool find1 = root == o1;
        bool find2 = root == o2;

        // 情况2.1: 左树或右树中只发现了 o1
        if (leftInfo.find1 || rightInfo.find1) {
            // 如果当前节点是 o2, 那么当前节点就是最低公共祖先
            if (find2) return info(true, true, root);
            else return info(true, false, nullptr); 
        } 

        // 情况2.2: 左树或右树中只发现了 o1
        if (leftInfo.find2 || rightInfo.find2) {
            // 如果当前节点是 o1, 那么当前节点就是最低公共祖先
            if (find1) return info(true, true, root);
            else return info(false, true, nullptr);
        }

        // 情况2.3: 当前节点的子树中即没有发现 o1 也没有发现 o2
        // 那就只返回当前节点有没有发现 o1, o2, 这里必然不会发现最低公共祖先
        return info(find1, find2, nullptr);
    }
};