# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def delNodes(self, root, to_delete):
        """
        :type root: TreeNode
        :type to_delete: List[int]
        :rtype: List[TreeNode]
        """
        if not root: return None
        res = []
        # ʹ��flag��ǵ�ǰ�ڵ�ĸ��ڵ��Ƿ���Ҫɾ��
        def dfs(root, flag):
            if not root: return
            if root.val in to_delete:
                dfs(root.left, 1)
                dfs(root.right, 1)
                root = None
            else:
                root.left = dfs(root.left, 0)
                root.right = dfs(root.right, 0)
                # ���ڵ�����Ҫɾ����ʱ��ż�����
                flag and res.append(root)
            return root
        # ���ڵ�ĸ��ڵ�Ĭ����Ҫɾ��
        dfs(root, 1)
        return res