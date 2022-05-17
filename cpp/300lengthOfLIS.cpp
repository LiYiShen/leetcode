class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        if (n < 1) return 0;
        int res = 1;
        vector<int> dp(n, 1);
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[i] > nums[j]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                    res = max(res, dp[i]);
                }
            }
        }
        return res;
    }
};

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        if (n < 1) return 0;
        vector<int> dp;  // ����ҵ������������� (����Ԫ��ֵԽСԽ�ã�����������һ����ֵ��ʱ�򣬹������������еĿ����Ծ�Խ��.)
        dp.push_back(nums[0]);
        for (int i = 1; i < n; ++i) {
            if (nums[i] > dp.back()) {
                dp.push_back(nums[i]);
            } else {
                int aim = lower_bound(dp.begin(), dp.end(), nums[i]) - dp.begin();
                dp[aim] = nums[i];
            }
        }
        return dp.size();
    }
};

// ��������arr���賤��Ϊn�����arr������������С�������ж���𰸣���������� ����ֵ(ע�������ڰ������ַ���ASCII��ֵ)���бȽϵ� �ֵ�����С���Ǹ���
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> LIS(vector<int>& arr) {
        // ��һ��������̰��������������г���
        vector<int> res;
        vector<int> maxLen;
        if (arr.size() < 1) return res;
        res.emplace_back(arr[0]);
        maxLen.emplace_back(1);
        for (int i = 1; i < arr.size(); ++i) {
            if (arr[i] > res.back()) {
                res.emplace_back(arr[i]);
                maxLen.emplace_back(res.size());
            } else {
                int pos = lower_bound(res.begin(), res.end(), arr[i]) - res.begin();
                res[pos] = arr[i];
                maxLen.emplace_back(pos+1);
            }
        }
        // �ڶ�������������������
        for (int i = arr.size() - 1, j = res.size(); j > 0; --i) {
            if (maxLen[i] == j) {
                res[--j] = arr[i];
            }
        }
        return res;
    }
};