class Solution {
private:
    unordered_set<int> history;
public:
    bool isHappy(int n) {
        if (n == 1) return true;
        if (history.find(n) != history.end()) return false;
        history.insert(n);
        int tmp = 0;
        while (n) { tmp += (n % 10) * (n % 10); n /= 10; }
        return isHappy(tmp);
    }
};

class Solution {
public:
    int bitSquareSum(int n) {
        int sum = 0;
        while (n > 0) {
            int bit = n % 10;
            sum += bit * bit;
            n = n / 10;
        }
        return sum;
    }
    bool isHappy(int n) {
        int slow = n, fast = n;
        do {
            slow = bitSquareSum(slow);
            fast = bitSquareSum(fast);
            fast = bitSquareSum(fast);
        } while (slow != fast);
        return slow == 1;
    }
};

// ��������������һֱѭ���ظ�����ô��ָ�루ֵ��һ����׷����ָ�루ֵ����Ҳ��������һ�������
// ��û��ѭ���ظ���������ָ��Ҳ����ȣ��Ҷ�����1��