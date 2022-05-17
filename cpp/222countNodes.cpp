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
    int countNodes(TreeNode* root) {
        /**
        ��ȫ�������ĸ߶ȿ���ͨ�����ϵط�������������ȡ
        �ж����������ĸ߶�:
        ������, ˵������������������, Ȼ���һ���ж��������Ľڵ��� (���һ�������ֵĽڵ��Ȼ����������)
        �������, ˵�������������С������������������, Ȼ���һ���ж��������Ľڵ��� (���һ�������ֵĽڵ��Ȼ����������)
        **/
        if (root == NULL) return 0;
        int l_hight = getHight(root->left);
        int r_hight = getHight(root->right);
        if (l_hight == r_hight) 
            return (1 << l_hight) + countNodes(root->right);  // 1(���ڵ�) + (1 << ld) - 1(����ȫ�������ڵ���) + �������ڵ�����
        else
            return (1 << r_hight) + countNodes(root->left);  // 1(���ڵ�) + (1 << rd) - 1(����ȫ�������ڵ���) + �������ڵ�����
    }
    int getHight(TreeNode* node) {
        int high = 0;
        while (node) { high++; node = node->left; }
        return high;
    }
};