class Solution {
public:
    int thirdMax(vector<int>& nums) {
        long n1 = LONG_MIN;  
        long n2 = LONG_MIN;
        long n3 = LONG_MIN;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > n1) {
                n3 = n2;
                n2 = n1;
                n1 = nums[i];
            } else if (nums[i] > n2 && nums[i] != n1) {
                n3 = n2;
                n2 = nums[i];
            } else if (nums[i] > n3 && nums[i] != n1 && nums[i] != n2) {
                n3 = nums[i];
            }
        }
        return n3 == LONG_MIN ? n1 : n3;
    }
};
// [1,2,-2147483648]

// �����C++98��׼��C++11���͵����ı���Ƕ��� long long��
// ��Ϊ���֣�long long �� unsigned long long����C++11�У���׼Ҫ�� long long ���Ϳ����ڲ�ͬƽ̨���в�ͬ�ĳ��ȣ���������64λ��
// �� long long ������ص�һ����3����LONG_MIN��LONG_MAX��ULONG_MAX
// �ֱ����ƽ̨����С�� long long ֵ������ long long ֵ���Լ����� unsigned long long ֵ��