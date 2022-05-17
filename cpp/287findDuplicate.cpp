class Solution {
public:
    // ���������ظ����־Ϳ�����Ϊ����ת��Ϊ������л�
    // �����鿴����������i��λ��ָ���nums[i]��λ�õĽ��
    // ��Ϊ��������
    // 1����Ѱ�������л�����ڣ�����ָ���뻷��
    // 2������ָ���ػ�ԭ�㣬������������
    int findDuplicate(vector<int>& nums) {
        int slow = nums[0], fast = nums[slow];
        while (slow != fast) {
            slow = nums[slow];
            fast = nums[nums[fast]];
        }
        slow = 0;
        while (slow != fast) {
            slow = nums[slow];
            fast = nums[fast];
        }
        return slow;
    }
};