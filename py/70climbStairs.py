class Solution(object):
    def climbStairs(self, n):
        """
        :type n: int
        :rtype: int
        """
        i1 = 1
        i2 = 2
        if n == 1:
            return i1
        for i in range(3, n+1):
            temp = i1 + i2
            i1 = i2
            i2 = temp
        return i2

# dp[i] = dp[i-1] + dp[i-2]:
# ��i����¥�ݷ����� = ��i-1����¥�ݷ�����������һ���� + ��i-2����¥�ݷ�����������������