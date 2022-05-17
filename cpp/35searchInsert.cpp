class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        if (nums[nums.size()-1] < target)
            return nums.size();
        for (int i = 0; i < nums.size(); i++)
            if (nums[i] >= target)
                return i;
        return 0;
    }
};

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        if (target <= nums[0])
            return 0;
        if (target > nums.back())
            return nums.size();
        return (int)(lower_bound(nums.begin(), nums.end(), target) - nums.begin());
    }
};
// lower_bound( )��upper_bound( )�������ö��ֲ��ҵķ�����һ���ź���������н��в��ҵġ�
// lower_bound( begin,end,num)���������beginλ�õ�end-1λ�ö��ֲ��ҵ�һ�����ڻ����num�����֣��ҵ����ظ����ֵĵ�ַ���������򷵻�end��
// ͨ�����صĵ�ַ��ȥ��ʼ��ַbegin,�õ��ҵ������������е��±ꡣ