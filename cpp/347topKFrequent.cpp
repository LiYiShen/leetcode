class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;  // ��һ��intΪԪ�أ��ڶ���intΪƵ��
        // priority_queue< type, container, function >
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;  // С����(Сֵ���ȼ���)
        vector<int> res;
        for (int i = 0; i < nums.size(); i++) mp[nums[i]]++;
        for (unordered_map<int, int>::iterator it = mp.begin(); it != mp.end(); it++) {
            if (pq.size() == k) {
                if (it->second > pq.top().first) {
                    pq.pop();
                    pq.push(make_pair(it->second, it->first));
                }
            } else
                pq.push(make_pair(it->second, it->first));  // ��һ��ΪƵ�ʣ��ڶ���ΪԪ��(pq Ĭ�ϰ��յ�һ��Ԫ��ֵ����)
        }
        while (!pq.empty()) {
            res.push_back(pq.top().second);
            pq.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};