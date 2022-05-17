class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> s2t;
        unordered_map<char, char> t2s;
        for (int i = 0; i < s.size(); ++i) {
            char x = s[i], y = t[i];
            if ((s2t.count(x) && s2t[x] != y) || (t2s.count(y) && t2s[y] != x))
                return false;
            s2t[x] = y;
            t2s[y] = x;
        }
        return true;
    }
};

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        // ��¼�����ַ���ÿ��λ�õ��ַ���һ�γ��ֵ�λ��
        vector<int> s_first_index(256, 0), t_first_index(256, 0);
        for (int i = 0; i < s.size(); ++i) {
            if (s_first_index[s[i]] != t_first_index[t[i]])
                return false;
            s_first_index[s[i]] = t_first_index[t[i]] = i + 1;
        }
        return true;
    }
};