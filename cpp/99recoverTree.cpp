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
private:
    TreeNode* t1 = nullptr;  // �����������¼������������ڵ㣬�����н���
    TreeNode* t2 = nullptr;
    TreeNode* pre = nullptr;  // ��¼�������ǰһ���ڵ�
public:
    void recoverTree(TreeNode* root) {
        InOrder(root);
        int tmp = t1->val;
        t1->val = t2->val;
        t2->val = tmp;
    }
    void InOrder(TreeNode* root) {
        if (root == nullptr) return;
        InOrder(root->left);
        if (pre != nullptr && pre->val > root->val) {
            if (t1 == nullptr) t1 = pre;  // ��¼��һ������ڵ�
            t2 = root;  // ��¼���һ������ڵ�
        }
        pre = root;
        InOrder(root->right);
    }
};