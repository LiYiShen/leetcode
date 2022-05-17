class Solution(object):
    def canPartition(self, nums):
        if not nums:
            return True
        total = sum(nums)
        if total & 1:  # ��Ϊ����
            return False
        total = total >> 1  # ��2
        nums.sort(reverse=True)  # ������
        if total < nums[0]:  # ���������ֵ�����ܺ͵�һ��
            return False
        return self.dfs(nums, total)

    def dfs(self, nums, total):
        if total == 0:
            return True
        if total < 0:
            return False
        for i in range(len(nums)):
            if self.dfs(nums[i+1:], total - nums[i]):  # ��ȥi����֮ǰ����֤ÿ����ֻ��һ��
                return True
        return False
