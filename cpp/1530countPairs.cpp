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
    int countPairs(TreeNode* root, int distance) {
        int res = 0;
        dfs(root, distance, res);  
        return res;
    }
    vector<int> dfs(TreeNode* root, const int distance, int& res) {
        if (!root) return {};
        if (!root->left && !root->right) return {0};  // ��ǰ�ڵ㵽Ҷ�ӽ�����Ϊ 0
        vector<int> distanceToLeaves;  // �������, ���ص�ǰ�ڵ㵽���·�����Ҷ�ӽڵ�ľ���
        vector<int> left = dfs(root->left, distance, res);
        for (int& e : left) {
            if (++e > distance) continue;  // ������Ҷ�ӽڵ����·������, ������
            distanceToLeaves.push_back(e);
        }
        vector<int> right = dfs(root->right, distance, res);
        for (int& e : right) {
            if (++e > distance) continue;
            distanceToLeaves.push_back(e);
        }
        for (int l : left)
            for (int r : right)
                res += (l + r <= distance);
        return distanceToLeaves;
    }
};