class Solution(object):
    def longestCommonPrefix(self, strs):
        """
        :type strs: List[str]
        :rtype: str
        """
        if not strs:
            return ""
        s1 = min(strs)
        s2 = max(strs)
        for i, x in enumerate(s1):
            if x != s2[i]:
                return s2[:i]
        return s1

# Python���ַ������ԱȽϣ����� ascII ֵ����
# �Ƚ������С�ַ����Ĺ���ǰ׺����Ϊ��������Ĺ���ǰ׺��

class Solution(object):
    def longestCommonPrefix(self, strs):
        """
        :type strs: List[str]
        :rtype: str
        """
        if not strs:
            return ""
        ss = list(map(set, zip(*strs)))
        res = ""
        for i, x in enumerate(ss):
            x = list(x)
            if len(x) > 1:
                break
            res += x[0]
        return res

# ����python��zip��������str����list�������뿴�ɶ�ά���飬���������ѹ����
# Ȼ���ÿ�����ü���ȥ�أ�֮�����list���ҵ�Ԫ�س��ȴ���1֮ǰ�ļ�Ϊ����ǰ׺��