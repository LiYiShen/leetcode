class Solution {
public:
    string LCS(string str1, string str2) {
        int m = str1.size(), n = str2.size();
        // dp[i][j] str1ǰi���ַ���str2ǰj���ַ�������Ϊβ�ַ�����������Ӵ����� ==> ����������
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        int maxLen = 0;
        int index = 0;
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (str1[i-1] == str2[j-1]) {  // �������������, dp[i][j] = 0;
                    dp[i][j] = dp[i-1][j-1] + 1;
                    if (dp[i][j] > maxLen) {
                        maxLen = dp[i][j];
                        index = i;
                    }
                }
            }
        }
        if (maxLen == 0) {
            return "";
        } else {
            return str1.substr(index - maxLen, maxLen);
        }
    }
};