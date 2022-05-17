class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> res;
        int n = nums.size();
        for (int i = 0; i < n; i++) {  // �ѳ��ֵ�ֵ-->�ѳ��ֵ�����-->��������ȡ��, ��֤�ѳ��ֹ���ֵΪ��, ��ʧ��������Ӧֵ��Ϊ��
            int index = abs(nums[i]) - 1;
            if (nums[index] > 0) nums[index] *= -1;
        }
        for (int i = 0; i < n; i++)
            if (nums[i] > 0)
                res.push_back(i + 1);
        return res;
    }
};