# ��������: ���Խ������߽���ĳһ���򻬶���
# ���磬��[i, j)���һ���1��Ԫ�أ����Ϊ [i+1, j+1).
# �Ż��������ڣ������ַ���������ӳ��

class Solution(object):
    def lengthOfLongestSubstring(self, s):
        """
        :type s: str
        :rtype: int
        """
        st = {}
        i, ans = 0, 0
        for j in range(len(s)):
            if s[j] in st:
                i = max(st[s[j]], i)
            ans = max(ans, j - i + 1)
            st[s[j]] = j + 1           # ����ӳ��
        return ans;

a = Solution()
print(a.lengthOfLongestSubstring("abcabcbb"))