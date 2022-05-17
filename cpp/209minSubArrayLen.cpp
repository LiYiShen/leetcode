class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int l = 0, r = -1;  // nums[l...r] ˫ָ�뻬������
        int sum = 0;
        int res = nums.size() + 1;
        while (l < nums.size()) {
            if (sum < s && r + 1 < nums.size())     // if(sum < s && r < nums.size() - 1)  -->  ��д������ִ��˳��
                sum += nums[++r];
            else
                sum -= nums[l++];
            if (sum >= s)
                res = min(res, r-l+1);
        }
        if (res == nums.size() + 1)
            return 0;
        return res;
    }
};