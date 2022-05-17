class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if (nums.empty()) return {-1, -1};
		int l = 0, r = nums.size() - 1;
		while (l < r) {  // �ҵ���ʼλ��
			int mid = l + r >> 1;
			if (nums[mid] >= target) r = mid;
			else l = mid + 1;
		}
		if (nums[l] != target) return {-1, -1};
		int start = l;
		r = nums.size() - 1;
		while (l < r) {  // �ҵ��յ�λ��
			int mid = l + r + 1 >> 1;  // ��������Ч�ʸ���
			if (nums[mid] > target) r = mid - 1;
			else l = mid;
		}
		return {start, r};
    }
};