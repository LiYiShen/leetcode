class Solution {
public:
    static bool cmp(vector<int>& a, vector<int>& b) {
        return a[1] < b[1];   // ֻ�谴�ս�β���򼴿�
        //return a[1] < b[1] || (a[1] == b[1] && a[0] < b[0]);
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if (intervals.size() == 0) return 0;
        sort(intervals.begin(), intervals.end(), cmp);
        // sort(intervals.begin(), intervals.end(), [](vector<int>& a, vector<int>& b) { return a[1] < b[1]; });
        int res = 1;
        int end = intervals[0][1];
        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i][0] >= end) {
                end = intervals[i][1];
                res++;
            }
        }
        return intervals.size() - res;
    }
};
// ̰���㷨: ѡ���β��̵ģ�����ſ������Ӹ�������
// ������ת��Ϊ����ܱ������ٸ����䣬ʹ���ǻ����ظ�