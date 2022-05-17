class Solution(object):
    def solveNQueens(self, n):
        """
        :type n: int
        :rtype: List[List[str]]
        """
        # queens:�ڷŻʺ��λ��
        # xy_dif:�����ϵ����¶Խ���x��yֵ�������ȣ�
        # xy_sum:�����ϵ����¶Խ���x��yֵ��ӣ���ȣ�
        def dfs(queens, xy_dif, xy_sum):
            row = len(queens)
            if row == n:
                result.append(queens)
                return
            for col in range(n):
                if col not in queens and row-col not in xy_dif and row+col not in xy_sum:
                    dfs(queens+[col], xy_dif+[row-col], xy_sum+[row+col])
        
        result = []
        dfs([], [], [])
        return [["." * i + "Q" + "." * (n-i-1) for i in sol] for sol in result]