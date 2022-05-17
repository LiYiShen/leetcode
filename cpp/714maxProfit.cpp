class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        if (n <= 1) return 0;
        int dp_i_0 = 0, dp_i_1 = INT_MIN;  // base (i = -1)
        for (int i = 0; i < n; i++) {
            int temp = dp_i_0;
            dp_i_0 = max(dp_i_0, dp_i_1 + prices[i]);
            dp_i_1 = max(dp_i_1, temp - prices[i] - fee);
        }
        return dp_i_0;
    }
};

/* k = +infinity with fee:
 * dp[i][0] = max(dp[i-1][0], dp[i-1][1] + prices[i])
 * dp[i][1] = max(dp[i-1][1], dp[i-1][0] - prices[i] - fee)
 * ���ͣ��൱�������Ʊ�ļ۸������ˡ�
 * �ڵ�һ��ʽ�����Ҳ��һ���ģ��൱��������Ʊ�ļ۸��С�ˡ�����C++�� INT_MIN - fee ��������������
 */