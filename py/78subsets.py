class Solution(object):
    def subsets(self, nums):
        res = [[]]
        for i in range(len(nums)-1, -1, -1):
            for subres in res[:]:
                res.append(subres + [nums[i]])
        return res

# �Ӻ����������һ�����Ͱ������Ӽ����ϸ�������µ��Ӽ�
# ��ѭ����res[:]�����£���res��������Ԫ��push��ȥ