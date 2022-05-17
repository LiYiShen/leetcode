class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res = nums[0];
        for (int i = 1; i < nums.size(); ++i)
            res ^= nums[i];
        return res;
    }
};

/*  0 ^ n => n
    n ^ n => 0
    ���ͬһ�������Σ�ԭ������
    ����Ҫ����ռ� => λ����
*/