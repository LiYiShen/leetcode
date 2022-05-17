class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if (n <= 1) return 0;
        int dp_i_k1_0 = 0, dp_i_k1_1 = INT_MIN;  // k = 1
        int dp_i_k2_0 = 0, dp_i_k2_1 = INT_MIN;  // k = 2
        for (int i = 0; i < n; i++) {
            dp_i_k2_0 = max(dp_i_k2_0, dp_i_k2_1 + prices[i]);
            dp_i_k2_1 = max(dp_i_k2_1, dp_i_k1_0 - prices[i]);  // k = 2 ������ k = 1 ���и���
            dp_i_k1_0 = max(dp_i_k1_0, dp_i_k1_1 + prices[i]);
            dp_i_k1_1 = max(dp_i_k1_1, -prices[i]);  // k = 1 ������ k = 0 ���и��� (dp_i_k0 == 0)
        }
        return dp_i_k2_0;  // �ڵ�i�죬���ٽ���2�ν��ף����ղ����й�Ʊ������������档
    }
};
/* k = 2:
 * ԭʼ�Ķ�̬ת�Ʒ��̣�û�пɻ���ĵط�
 * dp[i][k][0] = max(dp[i-1][k][0], dp[i-1][k][1] + prices[i])
 * dp[i][k][1] = max(dp[i-1][k][1], dp[i-1][k-1][0] - prices[i])
 *
 * ����û������ k ��Ӱ�죬���Ա���Ҫ�� k ������٣�
 * int max_k = 2;
 * int[][][] dp = new int[n][max_k + 1][2];
 * for (int i = 0; i < n; i++) {
 *    for (int k = max_k; k >= 1; k--) {
 *        if (i - 1 == -1) { // ���� base case }
 *        dp[i][k][0] = max(dp[i-1][k][0], dp[i-1][k][1] + prices[i]);
 *        dp[i][k][1] = max(dp[i-1][k][1], dp[i-1][k-1][0] - prices[i]);
 *    }
 * }
 * // ����� n �� max_k �� 2 ��״̬����ȷ��
 * return dp[n - 1][max_k][0];
 *
 * ֱ�Ӱ� k = 1 �� 2 �����ȫ���оٳ���Ҳ����.
 */