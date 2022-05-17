class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;
        while (left < right) {
            if (nums[left] < nums[right])  // û��ת
                return nums[left];
            int mid = left + right >> 1;
            if (nums[mid] == nums[left]) {  // �޷��ж���߶�һ�������ұ߶�һ��
                ++left;
            } else if (nums[mid] > nums[left]) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        return nums[left];
    }
};