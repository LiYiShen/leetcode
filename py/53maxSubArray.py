class Solution(object):
    def maxSubArray(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        for i in range(1, len(nums)):
            nums[i] = nums[i] + max(nums[i-1], 0)
        return max(nums)

# �������Ϊ��̬�滮˼�룺
# nums[i-1]�ǵ�ǰһ��Ϊֹ����������
# ֻҪ����0���Ϳ�����ӹ����������ͣ�
# С��0�����Ϊ0��nums[i]=nums[i]��
# �൱���������������¼��㡣һ�߱���һ�߼��㡣

