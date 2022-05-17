class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        if (n <= 1) return 0;
        if (k > n/2) return maxProfit_infinity(prices);
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(k + 1, vector<int>(2, 0)));
        for (int i = 0; i < n; i++) {
            for (int j = k; j >= 1; j--) {
                if (i == 0) {   // base case
                    dp[i][j][0] = 0;
                    dp[i][j][1] = -prices[i];
                    continue;  // Don't forget this
                }
                dp[i][j][0] = max(dp[i-1][j][0], dp[i-1][j][1] + prices[i]);
                dp[i][j][1] = max(dp[i-1][j][1], dp[i-1][j-1][0] - prices[i]);  // dp[0][0][0] = 0
            }
        }
        return dp[n-1][k][0];
    }
    int maxProfit_infinity(vector<int>& prices) {
        int dp_i_0 = 0, dp_i_1 = INT_MIN;
        for (int i = 0; i < prices.size(); i++) {
            int temp = dp_i_0;
            dp_i_0 = max(dp_i_0, dp_i_1 + prices[i]);
            dp_i_1 = max(dp_i_1, temp - prices[i]);
        }
        return dp_i_0;
    }
};
/*
 * һ�ν�����������������ɣ�������Ҫ���졣����˵��Ч������ k Ӧ�ò����� n/2�������������û��Լ�������ˣ��൱�� k = +infinity��
 */