class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for (int num : nums) sum += num;
        if (sum % 2 != 0) return false;
        vector<vector<bool>> dp(nums.size(), vector<bool>((sum/=2)+1, false)); // sum �Ѽ���
        // dp[i][j] ����ǰi�������Ƿ����j (��ά����Ķ�̬�滮)
        for (int i = 0; i < nums.size(); i++)
            for (int j = 0; j <= sum; j++) {
                if (i == 0)
                    dp[i][j] = (nums[i] == j);
                else
                    dp[i][j] = dp[i-1][j] || (j-nums[i] >= 0 ? dp[i-1][j-nums[i]] : false);
            }
        return dp[nums.size()-1][sum];
    }
};
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for (int num : nums) sum += num;
        if (sum % 2 != 0) return false;
        vector<bool> dp((sum/=2)+1, false); // sum �Ѽ���
        // dp[j] ����ǰi�������Ƿ����j (��һ��ֻ����ǰһ�У�ת��Ϊһά����Ķ�̬�滮)
        for (int i = 0; i < nums.size(); i++)
            for (int j = sum; j >= 0; j--)   // i==0 �õ���ֵ��Ȼ��ÿ�ζ��Ӻ���ǰ�����޸� dp[j]
                if (i == 0)
                    dp[j] = (nums[i] == j);
                else
                    dp[j] = dp[j] || (j-nums[i] >= 0 ? dp[j-nums[i]] : false);
        return dp[sum];
    }
};

class Solution {
    int n;
public:
    bool canPartition(vector<int>& nums) {
        n = nums.size();
        int target = accumulate(nums.begin(), nums.end(), 0); 
        if (target & 1) return false; 
        target >>= 1;
        sort(nums.begin(), nums.end(), [](int& a, int& b) {return a > b; });
        if (nums[0] > target) return false;
        return dfs(nums, 0, target);

    }
    bool dfs(vector<int>& nums, int idx, int target) {   //  DFS + ��֦
        if (idx >= n) 
            return false;
        if (nums[idx] == target) 
            return true;
        if (nums[idx] > target) 
            return dfs(nums, idx + 1, target);
        return dfs(nums, idx + 1, target - nums[idx]) || dfs(nums, idx + 1, target);
    }
};