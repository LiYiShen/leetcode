class Solution {
public:
    int numberOfBoomerangs(vector<vector<int>>& points) {
        int res = 0;
        for (int i = 0; i < points.size(); i++) {        //ѡ���һ����
            unordered_map<int, int> um;                 //����, ����
            for (int j = 0; j < points.size(); j++) {    //ѡ��ڶ�����
                if (i == j) continue;                    //���i��jָ��ͬһ��, ����
                int dist2 = (points[i][0] - points[j][0]) * (points[i][0] - points[j][0]) + 
                            (points[i][1] - points[j][1]) * (points[i][1] - points[j][1]);  //�������
                um[dist2] ++;
            }
            for (auto p : um) {
                res += p.second * (p.second - 1);
            }
        }
        return res;
    }
};