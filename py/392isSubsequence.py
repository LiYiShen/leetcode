class Solution(object):
    def isSubsequence(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: bool
        """
        t = iter(t)
        return all(i in t for i in s) 

class Solution(object):
    def isSubsequence(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: bool
        """
        i = 0
        j = 0
        while i < len(s) and j < len(t):
            if s[i] == t[j]:  # �൱��˫ָ��
                i += 1
            j += 1
        return i == len(s)

class Solution(object):
    def isSubsequence(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: bool
        """
        ti = 0
        for si in s:
            for j in range(ti, len(t)):
                if si == t[j]:
                    ti = j + 1  # ��¼��һ����ʼλ��
                    break
            else:
                return False
        return True
