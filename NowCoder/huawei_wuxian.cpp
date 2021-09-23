// ����һ����������, �ж��Ƿ�����ظ�Ԫ��
bool isReapted(vector<int>& nums) {
    unordered_map<int, int> ump;
    if (nums.size() <= 1) return false;
    for (int i = 0; i < nums.size(); ++i) {
        if (ump.find(nums[i]) != ump.end()) return true;
        ump[nums[i]]++;
    }
    return false;
}

// ����Сд�ַ���ɵ��ַ���s, ɾ�������ظ����ַ�  abbaca --> ca  s���Ȳ�����20000
string delelteRepeatChar(string s) {
    if (s.size() <= 1) return s;
    stack<char> st;
    for (int i = 0; i < s.size(); ++i) {
        if (!st.empty() && st.top() == s[i]) {
            st.pop();
            int tmp = s[i++];
            while (true) {
                if (tmp == s[i]) i++;
                else break;
            }
        }
        st.push(s[i]);
    }
    string res;
    while (!st.empty()) {
        res = st.top() + res;
        st.pop();
    }
    return res;
}