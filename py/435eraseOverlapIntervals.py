class Solution(object):
    def eraseOverlapIntervals(self, intervals):
        if not intervals:
            return 0
        intervals = sorted(intervals, key = lambda x: x[1])  # ���������Ҷ˵�����
        res = 0
        new_interval = intervals[0]     # ��ѡ����������
        for interval in intervals[1:]:
            if interval[0] < new_interval[1]:   # �ص���ɾ������
                res += 1
            else:  # ���ص������new_interval
                new_interval = interval
        return res

# sorted(iterable, cmp=None, key=None, reverse=False)
# iterable -- �ɵ�������
# cmp -- �Ƚϵĺ���
# key -- ��Ҫ���������бȽϵ�Ԫ�أ�ֻ��һ������
# reverse -- reverse = False ����Ĭ�ϣ�

# sort()��Ӧ���� list �ϵķ�����sorted()���Զ����пɵ����Ķ���������������
# list ��sort()�Ƕ��Ѿ����ڵ��б���в������޷���ֵ; 
# ���ڽ�����sorted()�������ص���һ���µ� list��������ԭ���Ļ����Ͻ��еĲ�����