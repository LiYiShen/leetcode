/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<TreeNode*> res;
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        unordered_set<int> del(to_delete.begin(), to_delete.end());
        // ���ڵ�ĸ��ڵ�Ĭ����Ҫɾ��
        dfs(del, root, 1);
        return res;
    }
    // ʹ��flag��ǵ�ǰ�ڵ�ĸ��ڵ��Ƿ���Ҫɾ��
    void dfs(unordered_set<int>& del, TreeNode*& root, int flag) {
        if (!root) return;
        int found = del.count(root->val);
        dfs(del, root->left, found);
        dfs(del, root->right, found);
        // ���ڵ�����Ҫɾ����ʱ��ż�����
        if (!found && flag) res.push_back(root);
        if (found) root = nullptr;
    }
};