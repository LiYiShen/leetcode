class Solution(object):
    def integerBreak(self, n):
        memo = [False for _ in range(n+1)]
        def breakInteger(n):
            if n == 1:
                return 1
            if memo[n] != False:
                return memo[n]
            res = -1
            for i in range(1, n):
                res = max(res, max(i * (n-i), i * breakInteger(n-i)))
            memo[n] = res;
            return res
        return breakInteger(n)

class Solution(object):
    def integerBreak(self, n):
        dp = [False for _ in range(n+1)]
        # dp[i]��ʾ������i�ָ���ٷָ�������֣���õ������˻�
        dp[1] = 1;
        for  i in range(2, n+1):
            # ���dp[i]
            for j in range(1, i):
                dp[i] = max(dp[i], max(j * (i-j), j*dp[i-j]))
        return dp[n]