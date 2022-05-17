class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if (n <= 1) return 0;
        int dp_i_0 = 0, dp_i_1 = INT_MIN;   // base (i = -1)
        for (int i = 0; i < n; i++) {
            dp_i_0 = max(dp_i_0, dp_i_1 + prices[i]);
            dp_i_1 = max(dp_i_1, -prices[i]);
        }
        return dp_i_0;
    }
};

/* k = 1:
 * dp[i][1][0] = max(dp[i-1][1][0], dp[i-1][1][1] + prices[i])
 * dp[i][1][1] = max(dp[i-1][1][1], dp[i-1][0][0] - prices[i]) 
 *             = max(dp[i-1][1][1], -prices[i])
 * ���ͣ�k = 0 �� base case������ dp[i-1][0][0] = 0��
 * 
 * ���ڷ��� k ���� 1������ı䣬�� k ��״̬ת���Ѿ�û��Ӱ���ˡ�
 * ��һ������ȥ������ k��
 * dp[i][0] = max(dp[i-1][0], dp[i-1][1] + prices[i])
 * dp[i][1] = max(dp[i-1][1], -prices[i])
 */