class Solution {
public:
    bool isPowerOfThree(int n) {
    if (n <= 0) return false;
    double a = log10(n) / log10(3) ;  // ����
    return  a == floor(a);           // �жϻ��׺��log3n�Ƿ�Ϊ��������n�Ƿ�Ϊ3�ı���
    }
};

class Solution {
public:
    bool isPowerOfThree(int n) {
        if (n < 1)  return false;
        while (n % 3 == 0) {
            n = n / 3;
        }
        return n == 1;
    }
};

class Solution {
public:
    bool isPowerOfThree(int n) {
        int a = 1;                  // a���ϳ�3�����Ƿ���n���
        while (n >= a) {
            if (a == n) return true; 
            if (a >= INT_MAX / 3) return false;
            a *= 3;
        }
        return false;
    }
};